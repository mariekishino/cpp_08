#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec = {1,2,3,4,5};

	vec.resize(4);
	vec.resize(6, -1);
	
	vec.insert(vec.begin(), 0);
	vec.erase(vec.end()-1);

	// ここでのvecはアドレスで、それをひとつずつイテレータitが一つずつみていく
	for (int it : vec)
	{
		std::cout << it << std::endl;
	}
}