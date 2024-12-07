#include <iostream>

// Chain Of Responsibility
// => 책임의 고리(전가) 정도로 번역..
// => 많이 사용되는데, 잘알려지지 않은 패턴
//    (많은 라이브러리가 다른 이름 사용해서)

// => 발생된 문제(이벤트)를 고리에 따라 옆으로 전달
// => 해결하면 중단될수도 있고, 해결되도 계속 옆으로 보낼수 있다.


class Handler
{
	Handler* next = nullptr;
public:
	Handler* set_next(Handler* h)
	{
		next = h;
		return next;
	}
	// 아래 함수가 핵심
	void handle(int problem)
	{
		// #1. 자신이 먼저 해결을 시도
		if (resolve(problem) == true)
			return;

		// #2. 처리되지 않은 경우 옆팀이 있으면 전달
		
		if (next != nullptr )
			next->handle(problem);
	}

	virtual bool resolve(int problem) = 0;
};
// 위 클래스가 "Chain Of Responsibility" 의 기본 로직을 제공합니다.
// 이제 문제를 해결할 각각의 파생 클래스를 만들면 됩니다.

class Team1 : public Handler
{
public:
	bool resolve(int problem)
	{
		std::cout << "Team1 Start\n";

		if (problem == 7)
		{
			std::cout << "resolved by Team1\n";
			return true;
		}
		return false;
	}
};
class Team2 : public Handler
{
public:
	bool resolve(int problem)
	{
		std::cout << "Team2 Start\n";

		if ( problem  % 2 == 1)
		{
			std::cout << "resolved by Team2\n";
			return true;
		}
		return false;
	}
};
class Team3 : public Handler
{
public:
	bool resolve(int problem)
	{
		std::cout << "Team3 Start\n";

		if (problem  < 10)
		{
			std::cout << "resolved by Team3\n";
			return true;
		}
		return false;
	}
};

int main()
{
	Team1 t1;
	Team2 t2;
	Team3 t3;

	t1.set_next(&t2)->set_next(&t3); // t1 => t2 => t3

//	t1.handle(7); // t1 이 해결
//	t1.handle(5); // t2 가 해결
//	t1.handle(8); // t3 가 해결

	t1.handle(12); // 해결 안됨.
}
