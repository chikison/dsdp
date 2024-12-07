#include <iostream>

// 방법 #1. 변하는 것을 가상함수로

class Character
{
	int gold;
	int item;
public:
	void run()    { do_run(); }
	void attack() { do_attack(); }

	virtual void do_run()  { std::cout << "run" << std::endl; }
	virtual void do_attack() { std::cout << "attack" << std::endl; }
};

class SuperCharacter : public Character
{
public:
	void do_run() override { std::cout << "fast run" << std::endl; }
	void do_attack() override { std::cout << "power attack" << std::endl; }
};

int main()
{
	Character* p = new Character;
	p->run();
	p->attack();

	p = new SuperCharacter; // 기존 캐릭터 객체의 동작이 변경된것이 아니라
							// 동작이 다른 새로운 캐릭터 객체 생성
							// => 동작만 바꾼것이 아니라, 상태도 변경된것

							// => 원하는 것은 상태는 유지 하는데, 
							//    동작(멤버함수)만 바꾸고 싶은것 !!
	p->run();
	p->attack();
}



