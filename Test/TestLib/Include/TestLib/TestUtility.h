#ifndef TESTLIB_TEST_UTILITY_H
#define TESTLIB_TEST_UTILITY_H
#include <type_traits>
#include <utility>
#include <tuple>
namespace TestLib
{
	template <typename T>
	struct remove_cv_ref : std::remove_cv<std::remove_reference_t<T>>
	{
	};
	template <typename T>
	using remove_cv_ref_t = typename remove_cv_ref<T>::type;

	template <typename TupleType>
	struct remove_cv_ref_tuple;
	template <template <typename...> typename TupleType, typename... Ts>
	struct remove_cv_ref_tuple<TupleType<Ts...>>
	{
		using type = TupleType<remove_cv_ref_t<Ts>...>;
	};
	template <typename T>
	using remove_cv_ref_tuple_t = typename remove_cv_ref_tuple<T>::type;

	template <typename TupleType, typename T0>
	struct push_tuple_left_1;
	template <template <typename...> typename TupleType, typename T0, typename... Ts>
	struct push_tuple_left_1<TupleType<Ts...>, T0>
	{
		using type = TupleType<T0, Ts...>;
	};
	template <typename TupleType, typename T0>
	using push_tuple_left_1_t = typename push_tuple_left_1<TupleType, T0>::type;

	template <typename TupleType, typename T0, typename T1>
	struct push_tuple_left_2;
	template <template <typename...> typename TupleType, typename T0, typename T1, typename... Ts>
	struct push_tuple_left_2<TupleType<Ts...>, T0, T1>
	{
		using type = TupleType<T0, T1, Ts...>;
	};
	template <typename TupleType, typename T0, typename T1>
	using push_tuple_left_2_t = typename push_tuple_left_2<TupleType, T0, T1>::type;

	template <typename TupleType>
	struct pop_tuple_left_1;
	template <template <typename...> typename TupleType, typename T0, typename... Ts>
	struct pop_tuple_left_1<TupleType<T0, Ts...>>
	{
		using type = TupleType<Ts...>;
	};
	template <typename TupleType>
	using pop_tuple_left_1_t = typename pop_tuple_left_1<TupleType>::type;

	template <typename TupleType>
	struct pop_tuple_left_2;
	template <template <typename...> typename TupleType, typename T0, typename T1, typename... Ts>
	struct pop_tuple_left_2<TupleType<T0, T1, Ts...>>
	{
		using type = TupleType<Ts...>;
	};
	template <typename TupleType>
	using pop_tuple_left_2_t = typename pop_tuple_left_2<TupleType>::type;

	namespace TestUtilityImpl
	{
		namespace make_remove_cv_ref_tuple
		{

			template <typename TupleType, size_t... Indices>
			inline auto Proc(const TupleType &tuple, std::index_sequence<Indices...>) -> remove_cv_ref_tuple_t<TupleType>
			{
				return remove_cv_ref_tuple_t<TupleType>(std::get<Indices>(tuple)...);
			}
			template <typename TupleType>
			inline auto Eval(const TupleType &tuple) -> remove_cv_ref_tuple_t<TupleType>
			{
				return Proc(tuple, std::make_index_sequence<std::tuple_size_v<TupleType>>());
			}
		}
		namespace make_push_tuple_left
		{
			template <typename TupleType, typename T0, size_t... Indices>
			inline auto Proc_1(const TupleType &tuple, const T0 &t0, std::index_sequence<Indices...>) -> push_tuple_left_1_t<TupleType, T0>
			{
				return push_tuple_left_1_t<TupleType, T0>(t0, std::get<Indices>(tuple)...);
			}
			template <typename TupleType, typename T0>
			inline auto Eval_1(const TupleType &tuple, const T0 &t0) -> push_tuple_left_1_t<TupleType, T0>
			{
				return Proc_1(tuple, t0, std::make_index_sequence<std::tuple_size_v<TupleType>>());
			}

			template <typename TupleType, typename T0, typename T1, size_t... Indices>
			inline auto Proc_2(const TupleType &tuple, const T0 &t0, const T1 &t1, std::index_sequence<Indices...>) -> push_tuple_left_2_t<TupleType, T0, T1>
			{
				return push_tuple_left_2_t<TupleType, T0, T1>(t0, t1, std::get<Indices>(tuple)...);
			}
			template <typename TupleType, typename T0, typename T1>
			inline auto Eval_2(const TupleType &tuple, const T0 &t0, const T1 &t1) -> push_tuple_left_2_t<TupleType, T0, T1>
			{
				return Proc_2(tuple, t0, t1, std::make_index_sequence<std::tuple_size_v<TupleType>>());
			}
		};
		namespace make_pop_tuple_left
		{
			template <typename TupleType, size_t... Indices>
			inline auto Proc_1(const TupleType &tuple, std::index_sequence<Indices...>) -> pop_tuple_left_1_t<TupleType>
			{
				return pop_tuple_left_1_t<TupleType>(std::get<Indices + 1>(tuple)...);
			}
			template <typename TupleType>
			inline auto Eval_1(const TupleType &tuple) -> pop_tuple_left_1_t<TupleType>
			{
				return Proc_1(tuple, std::make_index_sequence<std::tuple_size_v<TupleType> - 1>());
			}

			template <typename TupleType, size_t... Indices>
			inline auto Proc_2(const TupleType &tuple, std::index_sequence<Indices...>) -> pop_tuple_left_2_t<TupleType>
			{
				return pop_tuple_left_2_t<TupleType>(std::get<Indices + 2>(tuple)...);
			}
			template <typename TupleType, size_t... Indices>
			inline auto Eval_2(const TupleType &tuple) -> pop_tuple_left_2_t<TupleType>
			{
				return Proc_2(tuple, std::make_index_sequence<std::tuple_size_v<TupleType> - 2>());
			}
		};

	}

	template <typename TupleType>
	inline auto make_remove_cv_ref_tuple(const TupleType &tuple) -> remove_cv_ref_tuple_t<TupleType>
	{
		return TestUtilityImpl::make_remove_cv_ref_tuple::Eval(tuple);
	}

	template <typename TupleType, typename T0>
	inline auto make_push_tuple_left(const TupleType &tuple, const T0 &t0) -> push_tuple_left_1_t<TupleType, T0>
	{
		return TestUtilityImpl::make_push_tuple_left::Eval_1(tuple, t0);
	}
	template <typename TupleType, typename T0, typename T1>
	inline auto make_push_tuple_left(const TupleType &tuple, const T0 &t0, const T1 &t1) -> push_tuple_left_2_t<TupleType, T0, T1>
	{
		return TestUtilityImpl::make_push_tuple_left::Eval_2(tuple, t0, t1);
	}

	template <typename TupleType>
	inline auto make_pop_tuple_left(const TupleType &tuple) -> pop_tuple_left_1_t<TupleType>
	{
		return TestUtilityImpl::make_pop_tuple_left::Eval_1(tuple);
	}
	template <typename TupleType, typename T0, typename T1>
	inline auto make_pop_tuple_left(const TupleType &tuple) -> pop_tuple_left_2_t<TupleType>
	{
		return TestUtilityImpl::make_pop_tuple_left::Eval_2(tuple);
	}

}
#endif