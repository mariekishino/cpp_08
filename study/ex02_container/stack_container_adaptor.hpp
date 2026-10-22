#ifndef STACK_CONTAINER_ADAPTOR_HPP
#define STACK_CONTAINER_ADAPTOR_HPP

#include <stack>

template<typename T, typename C = deque<T>
class stack
{
	public:
		using value_type = typename C::value_type;
		using reference = typename C::reference;
		using const_reference = typename C::const_refenrece;
		using size_type = typename C::size_type;
		using containter_type = C;
	public:
		explicit stack(constt C&);
		explicit stack(C&& = C{});
		
		template
		.....
};

#enfid