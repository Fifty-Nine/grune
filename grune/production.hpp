#ifndef GRUNE_PRODUCTION_HPP
#define GRUNE_PRODUCTION_HPP

#include <list>
#include <string>

#include "grune/types.hpp"

namespace grune 
{

class non_terminal;
class symbol;

class production
{
public:
    production();
    production(non_terminal* from, const sequence_list& to = {});
    production(const sequence& from, const sequence_list& to = {});
    template<class... Args>
    static production_ptr create(Args&&...);

    bool initialized() const;

    std::string to_string() const;
    bool is_terminal() const;

private:
    sequence m_from;
    sequence_list m_to;
};

template<class... Args>
production_ptr production::create(Args&&... args)
{
    return std::make_shared<production>(args...);
}

}

#endif /* GRUNE_PRODUCTION_HPP */
