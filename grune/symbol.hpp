#ifndef GRUNE_SYMBOL_HPP
#define GRUNE_SYMBOL_HPP

#include <list>
#include <memory>
#include <string>

#include "grune/symbol_traits.hpp"

namespace grune 
{

class symbol 
{
public:
    template<class T>
    symbol(T arg) : 
        m_model(new model_impl<T>(arg))
    {
    }

    symbol(const char * s = "") : 
        symbol(std::string(s))
    { }

    symbol(const symbol& other) : 
        m_model(other.m_model ? other.m_model->copy() : nullptr)
    {
    }

    symbol& operator=(const symbol& other)
    {
        return *this = std::move(symbol(other));
    }

    symbol& operator=(symbol&&) = default;
    
    bool operator==(const symbol& other) const
    {
        return m_model->equal(*other.m_model);
    }

    /*
     * Convert the symbol into a string appropriate for pretty-printing. 
     */
    std::string to_string() const { return m_model->to_string(); }

    /* 
     * Test whether this symbol is terminal.
     */
    bool is_terminal() const { return m_model->is_terminal(); }

    /* 
     * Test whether this symbol is the empty string.
     */
    bool is_empty() const { return m_model->is_empty(); }

private:
    struct model
    {
        virtual ~model() { }
        virtual bool is_terminal() const = 0;
        virtual bool is_empty() const = 0;
        virtual std::string to_string() const = 0;
        virtual model* copy() const = 0;
        virtual bool equal(const model& other) const 
        {
            return other.is_terminal() == is_terminal() &&
                other.is_empty() == is_empty() && 
                other.to_string() == to_string();
        }
    };

    template<class T>
    struct model_impl : model
    {
        model_impl(const T& value) : 
            m_value(value)
        { }

        bool is_terminal() const { return grune::is_terminal(m_value); }
        bool is_empty() const { return grune::is_empty(m_value); } 
        std::string to_string() const { return grune::to_string(m_value); } 
        model* copy() const { return new model_impl<T>(*this); }
        virtual bool equal(const model& other) const
        {
            auto mt = dynamic_cast<const model_impl*>(&other);

            return mt ? mt->m_value == m_value : model::equal(other);
        }

        T m_value;
    };

    std::unique_ptr<model> m_model;
};

typedef std::list<symbol> sequence;
typedef std::list<sequence> sequence_list;

template<>
struct symbol_traits<sequence_list> : public symbol_list_traits<sequence_list>
{
    static std::string separator() { return " | "; }
};

}

#endif /* GRUNE_SYMBOL_HPP */
