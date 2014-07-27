#include "grune/sequence.hpp"

#include <algorithm>
#include <boost/iterator/transform_iterator.hpp>
#include <boost/algorithm/string/join.hpp>

#include "grune/symbol.hpp"

using namespace grune;

namespace
{

template<class C>
void filter(const C& c, sequence& out)
{
    for (auto s : c)
    {
        if (!get_ref(s).is_empty())
        {
            out.push_back(&get_ref(s));
        }
    }
}

}

sequence::sequence(const std::list<symbol*>& seq)
{
    filter(seq, *this);
}

sequence::sequence(const std::list<symbol_ptr>& seq)
{
    filter(seq, *this);
}
    
sequence::sequence(const std::initializer_list<symbol*>& seq)
{
    filter(seq, *this);
}

sequence::sequence(const std::initializer_list<symbol_ptr>& seq) 
{
    filter(seq, *this);
}
