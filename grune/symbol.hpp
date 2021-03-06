#ifndef GRUNE_SYMBOL_HPP
#define GRUNE_SYMBOL_HPP

#include <boost/operators.hpp>
#include <list>
#include <memory>
#include <string>

#include "grune/symbol_traits.hpp"

namespace grune 
{

/*
 * Represents a symbol in a grammar.
 * Symbols use value semantics and can contain objects of any class
 * that has an appropriate symbol_traits<> specialization.
 */
class symbol : 
    boost::less_than_comparable<symbol>,
    boost::equality_comparable<symbol>
{
public:
    template<class T, class = decltype(sizeof(symbol_traits<T>))>
    symbol(T arg) : 
        m_model(new model_impl<T>(arg))
    {
    }
    
    template<class T>
    explicit symbol(const std::initializer_list<T>& arg) : 
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

    bool operator<(const symbol& other) const
    {
        return m_model->less(*other.m_model);
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

    /* 
     * If this is a non-terminal, get the identifier. Otherwise,
     * return the empty string.
     */
    std::string identifier() const { return m_model->identifier(); }

    /*
     * Get the text of this symbol. If this is a non-terminal, this
     * is the same as identifier(). If this is a terminal, this returns
     * the same as to_string() without any quoting.
     */
    std::string text() const { return m_model->text(); }

private:
    struct model
    {
        virtual ~model() { }
        virtual bool is_terminal() const = 0;
        virtual bool is_empty() const = 0;
        virtual std::string to_string() const = 0;
        virtual std::string identifier() const = 0;
        virtual std::string text() const = 0;
        virtual model* copy() const = 0;
        virtual bool equal(const model& other) const 
        {
            return other.is_terminal() == is_terminal() &&
                other.is_empty() == is_empty() && 
                other.to_string() == to_string();
        }
        virtual bool less(const model& other) const
        {
            return is_terminal() < other.is_terminal() ||
                text() < other.text();
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
        std::string identifier() const { return grune::identifier(m_value); } 
        std::string text() const { return grune::text(m_value); } 
        model* copy() const { return new model_impl<T>(*this); }
        virtual bool equal(const model& other) const
        {
            auto mt = dynamic_cast<const model_impl*>(&other);

            return mt ? mt->m_value == m_value : model::equal(other);
        }
        virtual bool less(const model& other) const
        {
            auto mt = dynamic_cast<const model_impl*>(&other);

            return mt ? m_value < mt->m_value : model::less(other);
        }

        T m_value;
    };

    std::unique_ptr<model> m_model;
};

/*
 * A list of symbols. Can be used to represent a sentence if everything in the 
 * sequence is non-terminal, or the left- or right-hand side of a production.
 */
typedef std::list<symbol> sequence;

/*
 * A list of sequences.
 */
typedef std::list<sequence> sequence_list;

inline std::string to_string(const symbol& s) { return s.to_string(); }
inline std::string identifier(const symbol& s) { return s.identifier(); }
inline std::string text(const symbol& s) { return s.text(); }
inline bool is_terminal(const symbol& s) { return s.is_terminal(); }
inline bool is_empty(const symbol& s) { return s.is_empty(); }

}

#endif /* GRUNE_SYMBOL_HPP */
