#include "symbol.hpp"

#include <algorithm>
#include <boost/algorithm/string/join.hpp>

template<>
bool grune::is_terminal<grune::sequence>(const sequence& s)
{
    return all_of(
        s.begin(), s.end(), is_terminal<symbol>
    );
}

template<>
bool grune::is_empty<grune::sequence>(const sequence& s)
{
    return s.empty();
}

template<>
std::string grune::to_string(const grune::sequence& s)
{
    if (is_empty(s)) return "\"\"";

    std::vector<std::string> result(s.size());
    transform(s.begin(), s.end(), result.begin(), to_string<symbol>);
    
    return boost::algorithm::join(result, ", ");
}

