#include <iostream>

// 방법 #2. 변하는 것을 다른 클래스로
// => 데이타는 유지 하는데, 모든 동작(멤버함수)를 변경하고 싶다는것
// => 모든 멤버함수들을 여러개의 클래스로 제공

struct IState
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}

	// 이외에 jump(), slide(), fly() 등의 모든 캐릭터의 동작을
	// 인터페이스로 약속
};
// 이제 여러개의 동작클래스를 설계 합니다.
class NoItem : public IState
{
public:
	void run()    override { std::cout << "run" << std::endl; }
	void attack() override { std::cout << "attack" << std::endl; }
};

class SuperItem : public IState
{
public:
	void run()    override { std::cout << "fast run" << std::endl; }
	void attack() override { std::cout << "power attack" << std::endl; }
};

class BadItem : public IState
{
public:
	void run()    override { std::cout << "slow run" << std::endl; }
	void attack() override { std::cout << "weak attack" << std::endl; }
};

// 위 코드의 의도
// => 멤버 함수들을 여러벌을 만들어 둔것!!!


class Character
{
	// 아래 3개 클래스는 결국 "동작만 있게 됩니다"
	// => #1. 크기가 크지 않습니다.
	// => #2. 2개 만들필요도 없습니다.
	// => #3. 모든 캐릭터 객체가 공유 해도 됩니다.
	//        그래서, static 으로 하는 경우도 있습니다.
	// => 단, 테크닉상, 상태를 가지게 할수도 있고, 그경우는 non-static 으로
	inline static NoItem    state1;
	inline static SuperItem state2;
	inline static BadItem   state3;

	IState* current = &state1;

	int gold;
	int item;
public:
	void run()    { current->run(); }
	void attack() { current->attack(); }

	void acquire_item()
	{
		current = &state2;

		// 타이머 설치후 30초 뒤에 아래 코드 실행되게
		// current = &state1;
	}
};


int main()
{
	Character* p = new Character;
	p->run();
	p->attack();

	p->acquire_item();	// 이순간, p의 상태(멤버 데이타)는 계속 유지 됩니다.
						// 그런데, 멤버 함수가 모두 변경됩니다.
						// 마치 다른 클래스를 사용하는것 같아 보입니다.

	p->run();
	p->attack();

}

// 결국 위 코드는 변하는 것을 다른 클래스로 만들어서
// 인터페이스 기반으로 교체하는 코드 입니다.

// 아래 3개의 패턴은 class Diagram 이 동일 합니다.


// strategy : 객체가 사용하는 "알고리즘" 을 교체 하는것
//(전략패턴)	  ex) 바둑게임에서 "다음수 예측" 하는 방법
//			  객체의 동작 전체가 변경되는 것은 아니다.

// state : 객체의 "상태"에 따라 모든(거의 대부분의) 동작이 변경.
//		   ex) 자판기는 "동전 투입 유무" 에 따라 모든 동작이 변경됩니다.
//			   "NoCoin", "HasCoin" 으로 2개의 동작 클래스를 만들어서
//				"동전 투입시 상태를 교체"

// builder : 복잡한 객체를 만들때
//			 만드는 방법은 동일하게 하고
//			 각 공정의 결과를 다르게 할때.

