#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

#include <iostream>
#include <iterator>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		~MutantStack();
		MutantStack &operator=(const MutantStack &other);

		typedef typename Container::iterator iterator;

		iterator begin();
		iterator end();
};


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
