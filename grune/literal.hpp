#ifndef GRUNE_LITERAL_H
#define GRUNE_LITERAL_H

#include "grune/grune_fwd.hpp"

#include <string>

namespace grune
{

class literal 
{
public:
    literal(const std::string &text = "");

    std::string text() const;
    std::string to_string() const;

    bool is_empty() const;
    bool is_terminal() const { return true; }

private:
    std::string m_text;
};

}

#endif /* GRUNE_LITERAL_H */
