#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _numbers;
	
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		~Span();
		Span &operator=(const Span &other);

		void addNumber(int n);

		template <typename Iterator>
		void addNumber(Iterator first, Iterator last);

		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

};

template <typename Iterator>
void Span::addNumber(Iterator first, Iterator last)
{
    std::vector<int> incoming(first, last);

    if (incoming.size() > _N - _numbers.size())
        throw std::runtime_error("Span is full");

    _numbers.insert(
        _numbers.end(),
        incoming.begin(),
        incoming.end()
    );
}

#endif