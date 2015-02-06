#ifndef TYPEASVALUE_SRC_SFINAE_H_
#define TYPEASVALUE_SRC_SFINAE_H_

#include <type_traits>

namespace tav {
namespace detail {

template <bool Condition>
using enable_if = typename std::enable_if<Condition, std::size_t>::type;

}
}

#endif  // TYPEASVALUE_SRC_SFINAE_H_
