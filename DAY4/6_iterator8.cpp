#include <iostream>
#include <vector>

// 아래 클래스를 잘 생각해 보세요
template<typename T> class take_view
{
	T& rng;
	int cnt;
public:
	take_view(T& r, int c) : rng(r), cnt(c) {}

	auto begin() { return rng.begin(); }
	auto end() { return rng.begin() + cnt; } // 핵심 
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
//	take_view tv(v, 3);

//	for (auto e : v)
//	for (auto e : tv)
	for (auto e : take_view(v, 3) )
	{
		std::cout << e << ", ";
	}

}