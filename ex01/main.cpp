#include "Span.hpp"
#include <exception>
#include <iostream>
#include <list>
#include <vector>
#include <climits>

static void testSubject(void)
{
	std::cout << "\n== SUBJECT TEST ===" << std::endl;

	Span sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest: " << sp.shortestSpan()
			  << " (expeceted: 2)" << std::endl;
	std::cout << "Longest: " << sp.longestSpan()
		      << " (expected: 14)" << std::endl;

}

static void testFullContainer()
{
	std::cout << "\n=== FULL CONTAINER ===" << std::endl;

	Span sp(2);

	sp.addNumber(10);
	sp.addNumber(20);

	try
	{
		sp.addNumber(30);
	}
	catch(const std::exception& e)
	{
		std::cout << "caught expected exception: "
				  << e.what() << std::endl;
	}
	
}

static void testEmpty(void)
{
    std::cout << "\n=== EMPTY SPAN ===" << std::endl;

    Span sp(5);

    try
    {
        sp.shortestSpan();
        std::cout << "FAIL: exception not thrown" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught expected exception: "
                  << e.what() << std::endl;
    }
}

static void testLarge(void)
{
    std::cout << "\n=== 10000 NUMBERS ===" << std::endl;

    Span sp(10000);

    for (int i = 0; i < 10000; ++i)
        sp.addNumber(i);

    std::cout << "Shortest: " << sp.shortestSpan()
              << " (expected: 1)" << std::endl;
    std::cout << "Longest: " << sp.longestSpan()
              << " (expected: 9999)" << std::endl;
}



static void testIteratorRange(void)
{
    std::cout << "=== ITERATOR RANGE ===" << std::endl;

    std::vector<int> numbers;
    numbers.push_back(6);
    numbers.push_back(3);
    numbers.push_back(17);
    numbers.push_back(9);
    numbers.push_back(11);

    Span sp(5);
    sp.addNumber(numbers.begin(), numbers.end());

    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp.longestSpan() << std::endl;
}

static void testListRange(void)
{
    std::cout << "=== LIST RANGE ===" << std::endl;

    std::list<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    Span sp(3);
    sp.addNumber(numbers.begin(), numbers.end());

    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp.longestSpan() << std::endl;
}


static void printResult(const char *name, bool passed)
{
    std::cout << name << ": "
              << (passed ? "PASS" : "FAIL")
              << std::endl;
}

//  there's only one element
static void testSingleElement(void)
{
    std::cout << "\n=== SINGLE ELEMENT ===" << std::endl;

    Span sp(1);
    sp.addNumber(10);

    bool shortestThrows = false;
    bool longestThrows = false;

    try
    {
        sp.shortestSpan();
    }
    catch (const std::exception &)
    {
        shortestThrows = true;
    }

    try
    {
        sp.longestSpan();
    }
    catch (const std::exception &)
    {
        longestThrows = true;
    }

    printResult("Shortest exception", shortestThrows);
    printResult("Longest exception", longestThrows);
}

// duplidated elements 
static void testDuplicates(void)
{
    std::cout << "\n=== DUPLICATES ===" << std::endl;

    Span sp(3);
    sp.addNumber(10);
    sp.addNumber(10);
    sp.addNumber(20);

    printResult("Shortest", sp.shortestSpan() == 0);
    printResult("Longest", sp.longestSpan() == 10);
}

// integers including minus
static void testNegativeNumbers(void)
{
    std::cout << "\n=== NEGATIVE NUMBERS ===" << std::endl;

    Span sp(3);
    sp.addNumber(-10);
    sp.addNumber(-5);
    sp.addNumber(20);

    printResult("Shortest", sp.shortestSpan() == 5);
    printResult("Longest", sp.longestSpan() == 30);
}

// handling INT_MIN & INT_MAX
static void testIntegerLimits(void)
{
    std::cout << "\n=== INTEGER LIMITS ===" << std::endl;

    Span sp(2);
    sp.addNumber(INT_MIN);
    sp.addNumber(INT_MAX);

    unsigned int expected =
        static_cast<unsigned int>(INT_MAX)
        - static_cast<unsigned int>(INT_MIN);

    printResult("Shortest", sp.shortestSpan() == expected);
    printResult("Longest", sp.longestSpan() == expected);

    std::cout << "Expected difference: " << expected << std::endl;
}

// iterater range overflow
static void testRangeOverflow(void)
{
    std::cout << "\n=== ITERATOR RANGE OVERFLOW ===" << std::endl;

    Span sp(3);
    sp.addNumber(10);
    sp.addNumber(20);

    std::vector<int> incoming;
    incoming.push_back(30);
    incoming.push_back(40);

    bool exceptionThrown = false;

    try
    {
        sp.addNumber(incoming.begin(), incoming.end());
    }
    catch (const std::exception &)
    {
        exceptionThrown = true;
    }

    printResult("Overflow exception", exceptionThrown);

    // 例外後も元のデータが変わっていないか
    bool unchanged =
        sp.shortestSpan() == 10 &&
        sp.longestSpan() == 10;

    printResult("Original data preserved", unchanged);

    // 残り1枠がまだ使えるか
    bool addSucceeded = false;

    try
    {
        sp.addNumber(100);
        addSucceeded = true;
    }
    catch (const std::exception &)
    {
    }

    printResult("Can still add one number", addSucceeded);

    if (addSucceeded)
    {
        printResult("Final shortest", sp.shortestSpan() == 10);
        printResult("Final longest", sp.longestSpan() == 90);
    }
}

int main()
{
	testSubject();
	testFullContainer();
	testEmpty();
	testLarge();
	testIteratorRange();
	testListRange();
	
	testSingleElement();
	testDuplicates();
	testNegativeNumbers();
	testIntegerLimits();
	testRangeOverflow();


}

