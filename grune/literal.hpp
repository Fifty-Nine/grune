#ifndef LITERAL_H
#define LITERAL_H

#include <string>

#include "grammar/terminal.hpp"

namespace grammar
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

#endif /* LITERAL_H */
