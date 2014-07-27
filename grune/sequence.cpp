#include "grune/sequence.hpp"

#include <algorithm>
#include <boost/iterator/transform_iterator.hpp>
#include <boost/algorithm/string/join.hpp>

#include "grune/symbol.hpp"

using namespace grune;

namespace
{

void convert(const std::list<symbol_ptr>& in, sequence& out)
{
    std::transform(
        in.begin(), in.end(), 
        std::back_inserter(out),
        [](symbol_ptr s) { return s.get(); }
    );
}

}

sequence::sequence(const std::list<symbol*>& seq) : 
   base(seq)
{
}

sequence::sequence(const std::list<symbol_ptr>& seq)
{
    convert(seq, *this);
}
    
sequence::sequence(const std::initializer_list<symbol*>& seq) :
    base(seq)
{
}

sequence::sequence(const std::initializer_list<symbol_ptr>& seq) : 
    sequence(std::list<symbol_ptr>(seq))
{
    convert(seq, *this);
}
