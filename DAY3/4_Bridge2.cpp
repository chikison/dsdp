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

//-----------------------------------
// 위 코드가 실제 MP3 의 구현입니다.(IMP3, IPod, 다양한 제품들)
// 사용자가 실제 위 구현을 사용하게 하지말고 아래 클래스를 사용하게 합니다.

// 아래 클래스는 실제 "MP3 Play/Stop" 기능은 없습니다.

class MP3
{
	IMP3* impl;
public:
	MP3(IMP3* p = nullptr) : impl(p)
	{
		if (impl == nullptr) impl = new IPod;
	}
	void play() { impl->play(); }
	void stop() { impl->stop(); }

	void play_one_minute()
	{
		impl->play();
		// 타이머 설치후 1분뒤에
		impl->stop();
	}
};

// 이제 모든 클래스는 IMP3 대신 MP3 를 사용하게 합니다.

class People
{
public:
	void use(MP3* p) 
	{
		p->play();
		p->stop();

		p->play_one_minute();
	}
};


int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


