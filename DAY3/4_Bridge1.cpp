// 6_Bridge1 - 90 page
#include <iostream>

// 모든 MP3 제품의 규칙
struct IMP3
{
	virtual void play() = 0;
	virtual void stop() = 0;
	virtual ~IMP3() {}
};


class IPod : public IMP3
{
public:
	void play() { std::cout << "Play MP3 with IPod" << std::endl; }
	void stop() { std::cout << "Stop" << std::endl; }
};

// People 이 IMP3 를 직접사용하면
// => IMP3 가 update 되면 People 도 다시 컴파일되야 하고
// => People 에 요구사항이 생기면 IMP3고 변경해야 한다.

// UPDATE(수정) 가 자주일어나는 상황이라면
// => 직접 사용하지 말고 중간층(간접층)을 도입해라.
// => 구현과 추상의 분리. 


class People
{
public:
//	void use(IPod* p) // 강한 결합, 교체 불가능, 확장성이 없다.
	void use(IMP3* p) // 약한 결합, 교체 가능, 유연한 디자인
	{
		p->play();
		p->stop();

		// 사용자가 1분 미리 듣기를 요구한다.
		p->play_one_minute();
	}
};


int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


