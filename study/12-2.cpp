// ポインタを使って配列の総和を求める

// 半開区間

#include <iostream>
#include <vector>

int sum_all(int *first, int *last, int val)
{
	while (first != last)
	{
		val += *first;
		++first;
	}
	return val;
}

int main()
{
	int array[10];
	for (int i = 0; i < 10; ++i)
	{
		array[i] = i;
	}
	int* first = &array[0];
	int* last = &array[10];

	std::cout << sum_all(first, last, 0) << std::endl;
}

std::vector