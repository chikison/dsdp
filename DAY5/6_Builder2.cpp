// 2_Builder
#include <iostream>
#include <string>

typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}라고 가정


// 각 게임캐릭터(또는 자동차)를 만드는 공정을 인터페이스로 설계
struct IBuilder
{
	virtual void make_hat() = 0;		// make_엔진()
	virtual void make_uniform() = 0;	// make_바퀴()
	virtual void make_shoes() = 0;		// make_계기판()
	virtual Character get_result() = 0;	// get_car()
	virtual ~IBuilder() {}
};





class Director
{
	IBuilder* builder = nullptr;
public:
	void set_builder(IBuilder* b) { builder = b; }

	Character construct()
	{
		// 캐릭터를 만드는 공정은 동일합니다.
		builder->make_hat();
		builder->make_uniform();
		builder->make_shoes();		

		Character c = builder->get_result();

		return c;
	}
};

// 이제 국가별 빌더를 제공하면 됩니다.
class Korean : public IBuilder
{
	Character c;
public:
	void make_hat() override     { c += Hat("갓\n"); }
	void make_uniform() override { c += Uniform("한복\n"); }
	void make_shoes() override   { c += Shoes("짚신\n"); }

	Character get_result() override { return c; }
};

class American : public IBuilder
{
	Character c;
public:
	void make_hat() override     { c += Hat("야구모자\n"); }
	void make_uniform() override { c += Uniform("양복\n"); }
	void make_shoes() override   { c += Shoes("구두\n"); }

	Character get_result() override { return c; }
};

int main()
{
	Korean k;
	American a;

	Director d;
	d.set_builder(&a);
//	d.set_builder(&k); // 국가 선택을 변경하면 이 함수를 다시 호출해서
						// 인자로 해당 국가의 빌더를 전달합니다.


	Character c = d.construct();
	std::cout << c << std::endl;

}
