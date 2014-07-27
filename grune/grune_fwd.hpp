#ifndef GRUNE_FWD_H
#define GRUNE_FWD_H

#include <memory>

namespace grune 
{

class grammar;
typedef std::shared_ptr<grammar> grammar_ptr;

class literal;
typedef std::shared_ptr<literal> literal_ptr;

class non_terminal;
typedef std::shared_ptr<non_terminal> non_terminal_ptr;

class terminal;
typedef std::shared_ptr<terminal> terminal_ptr;

class production;
typedef std::shared_ptr<production> production_ptr;

class symbol;
typedef std::shared_ptr<symbol> symbol_ptr;

template<class T>
auto get_ref(T t)
    -> typename T::element_type&
{
    return *t.get();
}

template<class T>
T& get_ref(T* t)
{
    return *t;
}

} 

#endif /* GRUNE_FWD_H */
