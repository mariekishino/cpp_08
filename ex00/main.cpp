#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator>
#include <exception>

#include "easyfind.hpp"

static void testVector(void)
{
	std::cout << "=== VECTOR ===" << std::endl;

	std::vector<int> numbers;

	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);
	numbers.push_back(20);
	
	try
	{
		std::vector<int>::iterator found =
			easyfind(numbers, 20);

		std::cout << "found value: " << *found << std::endl;
		std::cout << "First position: "
				  << std::distance(numbers.begin(), found)
				  << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void testList(void)
{
	std::cout << "\n=== LIST ===" << std::endl;

	std::list<int> numbers;
	numbers.push_back(40);
	numbers.push_back(50);
	numbers.push_back(60);

	try
	{
		std::list<int>::iterator found =
			easyfind(numbers, 50);

		std::cout << "Found value: " << *found << std::endl;
		// *found はfound.operator*()のこと
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
}

static void testDeque(void)
{
	std::cout << "\n=== DEQUE ===" << std::endl;

	std::deque<int> numbers;
	numbers.push_back(70);
	numbers.push_back(80);
	numbers.push_back(90);

	try
	{
		std::deque<int>::iterator found =
			easyfind(numbers, 90);

		std::cout << "Found value: " << *found << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
}

static void testNotFound(void)
{
	std::cout << "\n=== NOT FOUND ===" << std::endl;

	std::vector<int> numbers;
	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);

	try
	{
		std::vector<int>::iterator found =
			easyfind(numbers, 99);

		std::cout << "Found value: " << *found << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
}



int main(void)
{
	testVector();
	testList();
	testDeque();
	testNotFound();
	return 0;
}