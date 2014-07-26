#include "grune/sentence.hpp"

#include <algorithm>

#include "grune/terminal.hpp"

using namespace grune;

sentence::sentence(const std::initializer_list<terminal*>& seq) : 
    base(seq)
{
}

sentence::sentence(const std::list<terminal*>& seq) : 
    base(seq)
{
}

sentence::sentence(const std::list<terminal_ptr>& seq)
{
    std::transform(
        seq.begin(), seq.end(), 
        std::back_inserter(*this),
        [](terminal_ptr s) -> terminal* { return s.get(); }
    );
}
