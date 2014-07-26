#ifndef GRUNE_LITERAL_H
#define GRUNE_LITERAL_H

#include <string>

#include "grune/terminal.hpp"

namespace grune
{

class literal : public terminal
{
public:
    literal(const std::string &text);

    std::string text() const;
    virtual std::string to_string() const;

private:
    std::string m_text;
};

}

#endif /* GRUNE_LITERAL_H */
