#include "Span.hpp"

Span::Span() : _N(0){}

Span::Span(unsigned int N) : _N(N){}

Span::Span(Span const &other)
{
	*this = other;
}

Span::~Span(){}

Span &Span::operator=(Span const &other)
{
	if (this == &other)
		return (*this);
	this->_numbers = other.getNumbers();
	this->_N = other.getN();
	return (*this);
}

unsigned int Span::getN() const
{
	return (this->_N);
}

std::vector<int> Span::getNumbers() const
{
	return (this->_numbers);
}

void Span::addNumber(int number)
{
	if (this->_numbers.size() >= this->_N)
		throw Span::FullStorageException();
	this->_numbers.push_back(number);
}
const char* Span::FullStorageException::what() const throw()
{
	return ("_numbers is full");
}

