#ifndef TYPEASVALUE_SRC_RUNTIME_LIST_FOR_EACH_H_
#define TYPEASVALUE_SRC_RUNTIME_LIST_FOR_EACH_H_

#include <type_traits>

#include "list/list.h"

namespace tav {
namespace runtime {

template <
	typename Current,
	typename Function,
	typename std::enable_if<std::is_void<Current>::value, std::size_t>::type = 0
>
void for_each(const Function&) { }

template <
	typename Current,
	typename Function,
	typename std::enable_if<!std::is_void<Current>::value, std::size_t>::type = 0
>
void for_each(const Function& function) {
	function(Head<Current>::type::value);

	for_each<Tail<Current>, Function>(function);
}

}
}

#endif  // TYPEASVALUE_SRC_RUNTIME_LIST_FOR_EACH_H_
