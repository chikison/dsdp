#include <iostream>
#include <vector>
#include <ranges>


int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// 아래 의미 생각해 보세요
	std::ranges::take_view tv(v, 3);
	std::ranges::filter_view fv(tv, [](int n) { return n % 2 == 1; });

	// 아래 한줄이 위 코드와 완전히 동일합니다.

	auto fv2 = v | std::views::take(3) | std::views::filter(위 람다);


	for (auto e : fv2 )
	{
		std::cout << e << ", ";
	}

}