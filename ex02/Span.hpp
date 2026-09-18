#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>


class Span
{
	private:
		unsigned int _N;
		std::vector<int> _numbers;
	
	public:
		Span();
		Span(unsigned int N);
		Span(Span const &other);
		~Span();

		Span &operator=(Span const &other);

		unsigned int getN() const;
		std::vector<int> getNumbers() const;
		
		void addNumber(int number);

		class FullStorageException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};


};

#endif