#include <iostream>
#include <string>
#include <conio.h>

// validation 정책은 변경할수 있어야 합니다.


class Edit
{
	std::string data;
public:

	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부에 있는 변해야 하는 부분을 찾아서 분리한다.
	// => 변하는 것을 가상함수로 분리 합니다

	virtual bool validate(char c)
	{
		return true;
	}

	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); 

			if (c == 13) break;

//			if (isdigit(c))  // 변하지 않은 코드 내부에 변해야 하는 부분
			if (validate(c)) // 가상함수를 사용해서 validation 수행
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

// 위 코드의 의도
// Edit 의 파생 클래스를 만들어서 validate 를 override 하면
// validation 정책을 변경할수 있다.
class NumEdit : public Edit
{
public:
	bool validate(char c) override
	{
		return isdigit(c);
	}
};

int main()
{
//	Edit e;
	NumEdit e;
//	AdressEdit e2; // 다른 정책을 가진 새로운 edit

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


