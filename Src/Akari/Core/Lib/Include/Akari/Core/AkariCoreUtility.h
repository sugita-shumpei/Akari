#ifndef AKARI_CORE_AKARI_CORE_UTILITY_H
#define AKARI_CORE_AKARI_CORE_UTILITY_H
#include <tuple>
#include <utility>
namespace Akari
{
    namespace Core
    {
        template<typename TupleLikeT, typename T>
        struct is_tuple_element_type_of;

        template<template<typename ...> typename TupleLike, typename T,typename T1, typename ...Ts>
        struct is_tuple_element_type_of<TupleLike<T1, Ts...>, T>
            :std::conditional_t<std::is_same_v<T1, T>,
            std::true_type,
            is_tuple_element_type_of<TupleLike<Ts...>, T>
        >{};

        template<template<typename ...> typename TupleLike, typename T, typename T1>
        struct is_tuple_element_type_of<TupleLike<T1>, T>
            :std::bool_constant<std::is_same_v<T1, T>> {};

        template<typename T, typename TupleLikeT>
        inline constexpr auto get_if(const TupleLikeT* ptr)->const T* {
            if (is_tuple_element_type_of<TupleLikeT, T>::value) {
                return &std::get<T>(*ptr);
            }
            else {
                return nullptr;
            }
        }
        template<typename T,typename TupleLikeT>
        inline constexpr auto get_if(TupleLikeT* ptr)->T* {
            if (is_tuple_element_type_of<TupleLikeT, T>::value) {
                return &std::get<T>(*ptr);
            }
            else {
                return nullptr;
            }
        }

        template<typename TupleLikeT>
        struct is_tuple_like :std::false_type {};

        template<template<typename ...> typename TupleLikeT,typename ...Ts>
        struct is_tuple_like<TupleLikeT<Ts...>> :std::true_type {};

        template <typename T1, typename T2, bool IsNotBothTupleT = !is_tuple_like<T1>::value || !is_tuple_like<T2>::value>
        struct add_tuple_right_1;
        template <typename TupleT1, typename TupleT2>
        struct add_tuple_right_1<TupleT1, TupleT2, false> {
        public:
            using type = decltype(std::tuple_cat(std::declval<TupleT1>(), std::declval<TupleT2>()));
        };

        template <template <typename...> typename Tuple, typename T, typename... Ts>
        struct add_tuple_right_1<T,Tuple<Ts...>, true>
        {
            using type = Tuple<T, Ts...>;
        };
        template <template <typename...> typename Tuple, typename T, typename... Ts>
        struct add_tuple_right_1<Tuple<Ts...>, T, true>
        {
            using type = Tuple<Ts..., T>;
        };
        template <>
        struct add_tuple_right_1<void, void, true>
        {
            using type = void;
        };
        template <typename T>
        struct add_tuple_right_1<void, T, true>
        {
            using type = std::tuple<T>;
        };
        template <typename T>
        struct add_tuple_right_1<T,    void, true>
        {
            using type = std::tuple<T>;
        };

        template <typename T1, typename T2, typename TupleT>
        struct add_tuple_right_2 : add_tuple_right_1<T1, typename add_tuple_right_1<T2, TupleT>::type> {};

        template <typename T1, typename T2, typename T3, typename TupleT>
        struct add_tuple_right_3 : add_tuple_right_1<T1, typename add_tuple_right_2<T2, T3, TupleT>::type> {};

        template <typename T1, typename T2, typename T3, typename T4, typename TupleT>
        struct add_tuple_right_4 : add_tuple_right_1<T1, typename add_tuple_right_3<T2, T3, T4, TupleT>::type> {};


        template <typename TupleT, typename T, size_t CheckPos = 0>
        struct add_tuple_right_1_if_not_contained;

        template <typename T>
        struct add_tuple_right_1_if_not_contained<void,T> {
            using type = std::tuple<T>;
        };

        template <template <typename...> typename Tuple, typename T1, size_t CheckPos, typename... Ts>
        struct add_tuple_right_1_if_not_contained<Tuple<Ts...>, T1, CheckPos>
        {
            using type = std::conditional_t<
                CheckPos==std::tuple_size_v<Tuple<Ts...>>,
                Tuple<Ts...,T1>,
                std::conditional_t<
                std::is_same<T1, std::tuple_element_t<CheckPos, Tuple<Ts...>>>::value,
                Tuple<Ts...>,
                typename add_tuple_right_1_if_not_contained<Tuple<Ts...>, T1, CheckPos + 1>::type
                >
            >;
        };

        template<typename SrcTupleT, typename T, typename DstTupleT = void>
        struct remove_tuple;
        template<typename T>
        struct remove_tuple<void, T> {
            using type = void;
        };
        template<template <typename...> typename SrcTuple, typename T, typename DstTupleT,typename T1, typename... Ts>
        struct remove_tuple<SrcTuple<T1,Ts...>, T, DstTupleT> {
            using type = typename remove_tuple<SrcTuple<Ts...>, T,
                std::conditional_t<
                    std::is_same_v<T1, T>,
                    DstTupleT,
                    typename add_tuple_right_1<DstTupleT, T1>::type
                >
            >;
        };
        template<template <typename...> typename SrcTuple, typename T, typename DstTupleT, typename T1>
        struct remove_tuple<SrcTuple<T1>, T, DstTupleT> {
            using type = std::conditional_t<
                std::is_same_v<T1, T>,
                DstTupleT,
                typename add_tuple_right_1<DstTupleT, T1>::type
            >;
        };

        template <typename IntegerSequenceT, auto Integer>
        struct add_integer_sequence_right_1;
        template <typename IntegerT, IntegerT IntegerV, IntegerT... Indices>
        struct add_integer_sequence_right_1<std::integer_sequence<IntegerT, Indices...>, IntegerV>
        {
            using type = std::integer_sequence<IntegerT, Indices..., IntegerV>;
        };
        template <typename IntegerT, IntegerT IntegerV>
        struct add_integer_sequence_right_1<void, IntegerV> {
            using type = std::integer_sequence<IntegerT, IntegerV>;
        };

        template <typename IntegerSequenceSet, typename IntegerSequenceSet::value_type Integer>
        struct insert_integer_sequence_set;

        template <typename Integer, Integer IntegerV, Integer... Indices>
        struct insert_integer_sequence_set<std::integer_sequence<Integer, Indices...>, IntegerV>
        {
        private:
            static inline constexpr bool is_insertable()
            {
                constexpr Integer arrays[] = { Indices... };
                for (auto i = 0; i < sizeof...(Indices); ++i)
                {
                    if (arrays[i] == IntegerV)
                    {
                        return false;
                    }
                }
                return true;
            }

        public:
            using type = std::conditional_t<is_insertable(),
                std::integer_sequence<Integer, Indices..., IntegerV>,
                std::integer_sequence<Integer, Indices...>>;
        };

        template <typename IntegerSequenceSet1, typename IntegerSequenceSet2>
        struct merge_integer_sequence_set;

        template <typename IntegerSequenceSet1, typename IntegerSequenceSet1::value_type IntegerV, typename IntegerSequenceSet1::value_type... Indices>
        struct merge_integer_sequence_set<IntegerSequenceSet1, std::integer_sequence<typename IntegerSequenceSet1::value_type, IntegerV, Indices...>>
        {
            using type = typename merge_integer_sequence_set<typename insert_integer_sequence_set<IntegerSequenceSet1, IntegerV>::type, std::integer_sequence<typename IntegerSequenceSet1::value_type, Indices...>>::type;
        };

        template <typename IntegerSequenceSet1, typename IntegerSequenceSet1::value_type IntegerV>
        struct merge_integer_sequence_set<IntegerSequenceSet1, std::integer_sequence<typename IntegerSequenceSet1::value_type, IntegerV>>
        {
            using type = typename insert_integer_sequence_set<IntegerSequenceSet1, IntegerV>::type;
        };

        template <typename... IntegerSequenceSets>
        struct merge_integer_sequence_sets;

        template <typename IntegerSequenceSet>
        struct merge_integer_sequence_sets<IntegerSequenceSet>
        {
            using type = IntegerSequenceSet;
        };

        template <typename IntegerSequenceSet1, typename IntegerSequenceSet2>
        struct merge_integer_sequence_sets<IntegerSequenceSet1, IntegerSequenceSet2> : merge_integer_sequence_set<IntegerSequenceSet1, IntegerSequenceSet2>
        {
        };

        template <typename IntegerSequenceSet1, typename IntegerSequenceSet2, typename... IntegerSequenceSets>
        struct merge_integer_sequence_sets<IntegerSequenceSet1, IntegerSequenceSet2, IntegerSequenceSets...>
        {
            using type = typename merge_integer_sequence_sets<
                typename merge_integer_sequence_set<IntegerSequenceSet1, IntegerSequenceSet2>::type,
                IntegerSequenceSets...>::type;
        };

        template <typename Integer, Integer... Indices>
        struct make_integer_sequence_set;

        template <typename Integer, Integer IntegerV>
        struct make_integer_sequence_set<Integer, IntegerV>
        {
            using type = typename std::integer_sequence<Integer, IntegerV>;
        };

        template <typename Integer, Integer IntegerV, Integer... Indices>
        struct make_integer_sequence_set<Integer, IntegerV, Indices...>
        {
            using type = typename merge_integer_sequence_set<std::integer_sequence<Integer, IntegerV>, std::integer_sequence<Integer, Indices...>>::type;
        };
        //template <typename T, size_t N, const T (&Array)[N],
        //          typename Integer = T,
        //          class = std::make_index_sequence<N>>
        //struct static_const_array_to_integer_sequence;

        //template <typename T, size_t N, typename Integer, const T (&Array)[N], size_t... Indices>
        //struct static_const_array_to_integer_sequence<T, N, Array, Integer, std::index_sequence<Indices...>>
        //{
        //    using type = std::integer_sequence< Integer, static_cast<Integer>(Array[Indices])...>;
        //};

        template<typename IntegerT, auto& ArrayV, size_t ...Indices>
        inline constexpr auto convert_array_to_index_sequence_impl(std::index_sequence<Indices...>)
        {
            return std::integer_sequence<IntegerT, static_cast<IntegerT>(ArrayV[Indices])...>();
        }
        template<typename IntegerT, auto& ArrayV>
        inline constexpr auto convert_array_to_index_sequence()
        {
            return convert_array_to_index_sequence_impl<IntegerT, ArrayV>(std::make_index_sequence<std::size(ArrayV)>());
        }

        template<typename IntegerSequence,typename ArgumentT, template<ArgumentT> typename IsReserveTraits, typename DstIntegerSequence = void>
        struct remove_integer_sequence;

        template<typename Integer, typename ArgumentT,template<ArgumentT> typename IsReserveTraits, typename DstIntegerSequence, Integer IntegerV, Integer... IntegerVList>
        struct remove_integer_sequence<std::integer_sequence<Integer,IntegerV, IntegerVList...>, ArgumentT, IsReserveTraits, DstIntegerSequence>
            :remove_integer_sequence<
            std::integer_sequence<Integer, IntegerVList...>,
            ArgumentT,
            IsReserveTraits,
            std::conditional_t<
            IsReserveTraits<static_cast<ArgumentT>(IntegerV)>::value,
            typename add_integer_sequence_right_1<DstIntegerSequence, IntegerV>::type,
            DstIntegerSequence
            >
        > {};


        template<typename Integer, typename ArgumentT, template<ArgumentT> typename IsReserveTraits, typename DstIntegerSequence, Integer IntegerV>
        struct remove_integer_sequence<std::integer_sequence<Integer, IntegerV>, ArgumentT,IsReserveTraits, DstIntegerSequence>
        {
            using type = std::conditional_t<
                IsReserveTraits<static_cast<ArgumentT>(IntegerV)>::value,
                typename add_integer_sequence_right_1<DstIntegerSequence, IntegerV>::type,
                DstIntegerSequence
            >;
        };

        
    }
}
#endif
