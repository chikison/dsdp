// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};

int main()
{
	// upcasting 활용 #1. 동종을 보관하는 컨테이너
//	std::vector<Dog*>    v1; // Dog 객체만 보관 가능한 vector
	std::vector<Animal*> v1; // Animal 만 보관하겠다는 것이 아니라
							 // 모든 동물(Animal 로 부터 파생된 타입)
							// 을 보관하겠다는 의도
}
