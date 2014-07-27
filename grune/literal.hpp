#ifndef GRUNE_LITERAL_H
#define GRUNE_LITERAL_H

#include "grune/grune_fwd.hpp"
#include "grune/terminal.hpp"

namespace grune
{

class literal : public terminal
{
public:
    literal(const std::string &text = "");
    static literal_ptr create(const std::string& text = "");

    std::string text() const;
    virtual std::string to_string() const;

    virtual bool is_empty() const;

private:
    std::string m_text;
};

}

#endif /* GRUNE_LITERAL_H */
