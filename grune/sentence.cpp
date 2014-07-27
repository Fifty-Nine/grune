#include "grune/sentence.hpp"

#include <algorithm>

#include "grune/terminal.hpp"

using namespace grune;

namespace
{

void convert(const std::list<terminal_ptr>& in, sentence& out)
{
    std::transform(
        in.begin(), in.end(), 
        std::back_inserter(out),
        [](terminal_ptr s) { return s.get(); }
    );
}

}

sentence::sentence(const std::list<terminal*>& seq) : 
    base(seq)
{
}

sentence::sentence(const std::list<terminal_ptr>& seq)
{
    convert(seq, *this);
}

sentence::sentence(const std::initializer_list<terminal*>& seq) : 
    base(seq)
{
}

sentence::sentence(const std::initializer_list<terminal_ptr>& seq)
{
    convert(seq, *this);
}
