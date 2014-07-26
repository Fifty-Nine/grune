#include "grune/sequence.hpp"

#include <algorithm>
#include <boost/iterator/transform_iterator.hpp>
#include <boost/algorithm/string/join.hpp>

#include "grune/symbol.hpp"

using namespace grune;

sequence::sequence(const std::initializer_list<symbol*>& seq) : 
    base { seq }
{
}

sequence::sequence(const std::list<symbol*>& seq) : 
   base(seq)
{
}

sequence::sequence(const std::list<symbol_ptr>& seq)
{
    std::transform(
        seq.begin(), seq.end(), 
        std::back_inserter(*this),
        [](symbol_ptr s) { return s.get(); }
    );
}
