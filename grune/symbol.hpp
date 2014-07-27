#ifndef GRUNE_SYMBOL_HPP
#define GRUNE_SYMBOL_HPP

#include <list>
#include <memory>
#include <string>

namespace grune 
{

class symbol 
{
public:
    symbol() :
        m_model(new model)
    {
    }

    template<class T>
    symbol(T arg) : 
        m_model(new model_impl<T>(arg))
    {
    }

    symbol(const symbol& other) :
        m_model(other.m_model->copy())
    {
    }

    /*
     * Convert the symbol into a string appropriate for pretty-printing. 
     */
    virtual std::string to_string() const { return m_model->to_string(); }

    /* 
     * Test whether this symbol is terminal.
     */
    virtual bool is_terminal() const { return m_model->is_terminal(); }

    /* 
     * Test whether this symbol is the empty string.
     */
    virtual bool is_empty() const { return m_model->is_empty(); }

private:
    struct model
    {
        virtual bool is_terminal() const { return false; }
        virtual bool is_empty() const { return false; }
        virtual std::string to_string() const { return ""; }
        virtual model* copy() const { return new model(*this); }
    };

    template<class T>
    struct model_impl : model
    {
        model_impl(T value) : 
            m_value(value)
        { }

        bool is_terminal() const { return m_value.is_terminal(); }
        bool is_empty() const { return m_value.is_empty(); }
        std::string to_string() const { return m_value.to_string(); }
        model* copy() const { return new model_impl<T>(*this); }

        T m_value;
    };

    std::unique_ptr<model> m_model;
};

typedef std::list<symbol> sequence;
typedef std::list<sequence> sequence_list;

template<class T>
std::string to_string(const T& value)
{
    return value.to_string();
}
template<>
std::string to_string<sequence>(const sequence& s);
template<>
std::string to_string<sequence_list>(const sequence_list& s);

template<class T>
bool is_terminal(const T& value)
{
    return value.is_terminal();
}
template<>
bool is_terminal<sequence>(const sequence& s);

template<class T>
bool is_empty(const T& value)
{
    return value.is_empty();
}

template<>
bool is_empty<sequence>(const sequence& s);

}

#endif /* GRUNE_SYMBOL_HPP */
