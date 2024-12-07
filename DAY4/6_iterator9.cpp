#include <iostream>
#include <vector>

// 앞에서 만든 take_view 같은 개념(컨테이너를 바라 보는 제한된 시각, 복사본생성안함)
// 이 C++, Java, C# 등에 모두 있습니다.
// C++ : Range  (C++20 부터) - C++언어 20으로 설정하세요
// C#  : LINQ
// Java : Stream 

#include <ranges>

namespace RG = std::ranges;

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };


//	for (auto e : RG::take_view(v, 3))
//	for (auto e : RG::reverse_view(v))
	for (auto e : RG::reverse_view( RG::take_view(v, 3) ) )
	{
		std::cout << e << ", ";
	}

}