#ifndef GRUNE_PRODUCTION_HPP
#define GRUNE_PRODUCTION_HPP

#include <list>
#include <string>

#include "grune/symbol.hpp"

namespace grune 
{

class non_terminal;
class production
{
public:
    production();
    production(const non_terminal& from, const sequence_list& to = {});
    production(const sequence& from, const sequence_list& to = {});

    bool initialized() const;
    bool operator==(const production& rhs) const;

    std::string to_string() const;
    bool is_terminal() const;
    sequence lhs() const;
    sequence rhs() const;

    sequence_list apply(const sequence& s) const;

private:
    sequence m_from;
    sequence_list m_to;
};

typedef std::list<production> production_list;

sequence_list apply(const production& p, const sequence& s);
sequence_list apply(const production_list& p, const sequence& s);
}

#endif /* GRUNE_PRODUCTION_HPP */
