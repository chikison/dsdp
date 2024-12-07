#include <iostream>
#include <vector>
#include <list>

int main()
{
	slist<int>  s = { 1,2,3 };
	vector<int> v = { 1,2,3 };

	// java style iterator 코드

	auto it1 = s.iterator();
	auto it2 = s.iterator();

	while (it1.hasNext())
	{
		std::cout << it1.next() << std::endl;
	}

	while (it2.hasNext())
	{
		std::cout << it2.next() << std::endl;
	}
}
