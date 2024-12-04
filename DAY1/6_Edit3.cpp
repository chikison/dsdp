#include <iostream>
#include <string>
#include <conio.h>


// 변하는 코드를 분리하는 2가지 방법

// 1. 변하는 것을 가상함수로 - template method 패턴, Edit2.cpp
// 2. 변하는 것을 다른 클래스로 - strategy 패턴,     Edit3.cpp

// 모든 Validator 가 지켜야 하는 공통의 인터페이스 (규칙)먼저 설계

struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true; }

	virtual ~IValidator() {}
};

// 주민 등록 번호 : 961  1      확인




class Edit
{
	std::string data;

	IValidator* val = nullptr;
public:
	void set_validator(IValidator* p) { val = p; }



	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); 

			if (c == 13 && (val == nullptr || val->is_complete(data) )  ) break;

			if ( val == nullptr || val->validate(data, c) ) // 값의 유효성 여부 판단을
			{												// 다른 객체에 위임
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};



// 입력값의 유효성을 조사하는 클래스

class LimitDigitValidator : public IValidator
{
	int limit;
public:
	LimitDigitValidator(int n) : limit(n) {}


	bool validate(const std::string& s, char c) override 
	{
		return s.size() < limit && isdigit(c);
	}

	bool is_complete(const std::string& s) override
	{
		return s.size() == limit;
	}
};

// 이제 다양한 형태의 validator 를 제공하면 됩니다.
// EmailValidator, PhoneNumberValidator, ....

// 복습하실때, 다양한 형태의 Validator 만들어서 사용해 보세요
// => 아주 편리하다는 것을 느낄수 있습니다.


int main()
{
	Edit e;

	LimitDigitValidator v(5);

	e.set_validator(&v); // e 객체에 "값의 유효성을 체크하는 객체 전달"


	LimitDigitValidator v2(15);
	e.set_validator(&v2); // 동일한 edit 가 validation 정책만 변경했다.
						  // 즉, 실행시간에 정책(알고리즘)의 교체

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


