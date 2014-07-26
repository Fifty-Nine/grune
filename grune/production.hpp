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
    production(non_terminal* from, const std::list<sequence>& to = {});
    production(const sequence& from, const std::list<sequence>& to = {});
    template<class... Args>
    static production_ptr create(Args&&...);

    bool initialized() const;

    std::string to_string() const;
    bool is_terminal() const;

private:
    sequence m_from;
    std::list<sequence> m_to;
};

template<class... Args>
production_ptr production::create(Args&&... args)
{
    return std::make_shared<production>(std::forward(args...));
}

}

#endif /* GRUNE_PRODUCTION_HPP */
