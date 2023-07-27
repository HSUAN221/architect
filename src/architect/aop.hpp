#ifndef SRC_ARCHITECT_AOP_HPP_
#define SRC_ARCHITECT_AOP_HPP_

#include <functional>
#include <map>

namespace arch {


// forward declarition. aopfy will reconstruct the series of type after
// iteration, and put it into fulltype_t;
template <typename _AopBase, template <typename> class... __Aspects>
struct aopfy;

// parameter base wrap.Only if we have a base with the template parameters, we
// can reconstruct the fulltype.
template <typename _Base, template <typename> class... __Aspects>
struct aopbase {
    // reference_t will keep the same during iteration.
    using reference_t = aopfy<aopbase, __Aspects...>;
    using base_t = _Base;
};

// iteration template defination.
template <typename _AopBase, template <typename> class __FirstAspects,
          template <typename> class... __RestAspects>
struct aopfy<_AopBase, __FirstAspects, __RestAspects...> {
    using fulltype_t = __FirstAspects<
      typename aopfy<_AopBase, __RestAspects...>::fulltype_t>;
    using this_t = typename _AopBase::base_t;
};

// end of iteration tempalte defination.
template <typename _AopBase> struct aopfy<_AopBase> {
    using fulltype_t = typename _AopBase::reference_t;
    using this_t = typename _AopBase::base_t;
};


} // end of namespace qaop

#endif // SRC_ARCHITECT_AOP_HPP_
