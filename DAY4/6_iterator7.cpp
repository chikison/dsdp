#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	for (auto e : v)
	{
		std::cout << e << ", ";
	}

	// 위 코드는 컴파일러가 아래 처럼 변경합니다.
	auto first = v.begin();
	auto last  = v.end();

	for (; first != last; ++first)
	{
		auto e = *first;
		//-------------------------
		std::cout << e << ", ";
	}
}