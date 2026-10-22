#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template <typename T, typename Container = std::deque<T>>
class MutanStack : public std::stack<T, Container>
{
	public:
		MutanStack();
		MutanStack(const MutanStack &other);
		~MutanStack();
		MutanStack &operator=(const MutanStack &other);

		typedef typename Container::iterator iterator;

		iterator begin();
		iterator end();
}


// template <class T >
// class MutantStack : public std::stack<T>
// {	
// 	public:
// 		MutantStack();
// 		MutantStack(const MutantStack<T> &other);
// 		~MutantStack();
// 		MutantStack &operator=(const MutantStack<T> &other);

// 		typedef typename std::stack<T>::container_type::iterator iterator;

// 		iterator begin();
// 		iterator end();
// };

#include "MutantStack.tpp"

#endif
