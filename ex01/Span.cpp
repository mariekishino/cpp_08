#include "Span.hpp"

Span::Span() : _N(0), _numbers() {}

Span::Span(unsigned int n) : _N(n) {}

Span::Span(const Span &other) : _N(other._N), _numbers(other._numbers) {}

Span::~Span() {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_numbers = other._numbers;
		_N = other._N;
	}
	return (*this);
}

void Span::addNumber(int n)
{
	if (_numbers.size() >= _N)
		throw std::runtime_error("Span is full");
	_numbers.push_back(n);
}



unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to calculate span");

	std::vector<int> copy(_numbers);
	std::sort(copy.begin(), copy.end());

	unsigned int shortest =
		static_cast<unsigned int>(copy[1])
		- static_cast<unsigned int>(copy[0]);
	for (std::vector<int>::size_type i = 2; i < copy.size(); ++i)
	{
		unsigned int diff =
			static_cast<unsigned int>(copy[i])
			- static_cast<unsigned int>(copy[i - 1]);
		
		if (diff < shortest)
			shortest = diff;
	}
	return (shortest);
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to calculate span");


	std::vector<int>::const_iterator minIt =
		std::min_element(_numbers.begin(), _numbers.end());
	
	std::vector<int>::const_iterator maxIt =
		std::max_element(_numbers.begin(), _numbers.end());
	
	return (
		static_cast<unsigned int>(*maxIt)
		- static_cast<unsigned int>(*minIt)
	);	
}

