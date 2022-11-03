#ifndef AKARI_CORE_AKARI_CORE_UTILITY_H
#define AKARI_CORE_AKARI_CORE_UTILITY_H
#include <tuple>
#include <utility>
namespace Akari
{
    namespace Core
    {
        template <typename TupleT, typename T>
        struct add_tuple_right_1;
        template <template <typename...> typename Tuple, typename T, typename... Ts>
        struct add_tuple_right_1<Tuple<Ts...>, T>
        {
            using type = Tuple<Ts..., T>;
        };

        template <typename T>
        struct add_tuple_right_1<void, T>
        {
            using type = std::tuple<T>;
        };
        template <>
        struct add_tuple_right_1<void, void>
        {
            using type = void;
        };

        template <typename IntegerSequenceT, typename IntegerSequenceT::value_type Integer>
        struct add_integer_sequence_right_1;
        template <typename IntegerT, IntegerT IntegerV, IntegerT... Indices>
        struct add_integer_sequence_right_1<std::integer_sequence<IntegerT, Indices...>, IntegerV>
        {
            using type = std::integer_sequence<IntegerT, Indices..., IntegerV>;
        };

        template <typename IntegerSequenceSet, typename IntegerSequenceSet::value_type Integer>
        struct insert_integer_sequence_set;

        template <typename Integer, Integer IntegerV, Integer... Indices>
        struct insert_integer_sequence_set<std::integer_sequence<Integer, Indices...>, IntegerV>
        {
        private:
            static inline constexpr bool is_insertable()
            {
                constexpr Integer arrays[] = {Indices...};
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

        template <typename T, size_t N, const T (&Array)[N],
                  typename Integer = T,
                  class = std::make_index_sequence<N>>
        struct static_const_array_to_integer_sequence;

        template <typename T, size_t N, typename Integer, const T (&Array)[N], size_t... Indices>
        struct static_const_array_to_integer_sequence<T, N, Array, Integer, std::index_sequence<Indices...>>
        {
            using type = std::integer_sequence< Integer, static_cast<Integer>(Array[Indices])...>;
        };
    }
}
#endif
