#include "MutantStack.hpp"

template <class T>
MutantStack<T>::MutantStack() {}

template <class T>
MutantStack<T>::MutantStack(const MutantStack<T> &other)
{
	(void) other;
}
template <class T>
MutantStack<T>::~MutantStack() {}

template<class T>
MutantStack &MutantStack::operator=(const MutantStack<T> &other)
{
	(void) other;
	return(*this);
}

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}
template <class T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

