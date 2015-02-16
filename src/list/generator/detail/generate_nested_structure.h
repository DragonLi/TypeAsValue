#ifndef TYPEASVALUE_SRC_LIST_GENERATOR_DETAIL_GENERATE_NESTED_STRUCTURE_H_
#define TYPEASVALUE_SRC_LIST_GENERATOR_DETAIL_GENERATE_NESTED_STRUCTURE_H_

namespace tav {

namespace detail {

template <
	template <typename, typename> class Structure,
	template <typename>           class Generator,
	typename                            Initial,
	typename                            Count
>
struct generate_nested_structure {
	typedef Structure<
		Initial,
		Eval<generate_nested_structure<
			Structure,
			Generator,
			Generator<Initial>,
			Substract<Count, Size<1>>
		>>
	> type;
};

template <
	template <typename, typename> class Structure,
	template <typename>           class Generator,
	typename                            Initial
>
struct generate_nested_structure<Structure, Generator, Initial, Size<0>> {
	typedef void type;
};

}

}

#endif  // TYPEASVALUE_SRC_LIST_GENERATOR_DETAIL_GENERATE_NESTED_STRUCTURE_H_
