#include "grune/sentence.hpp"

#include <algorithm>

#include "grune/terminal.hpp"

using namespace grune;

namespace
{

template<class C>
void filter(const C& c, sentence& out)
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

sentence::sentence(const std::list<terminal*>& seq)
{
    filter(seq, *this);
}

sentence::sentence(const std::list<terminal_ptr>& seq)
{
    filter(seq, *this);
}

sentence::sentence(const std::initializer_list<terminal*>& seq)
{
    filter(seq, *this);
}

sentence::sentence(const std::initializer_list<terminal_ptr>& seq)
{
    filter(seq, *this);
}
