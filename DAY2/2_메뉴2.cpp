#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 객체지향 프로그래밍 이란 ?
// => 프로그램의 모든 요소를 "객체"로 생각 하는 것

// => 프로그램에서 필요한 타입을 먼저 만들어야 한다.

class MenuItem
{
	std::string title;
	int  id;
//	std::string shortcut; // 단축키
public:
	MenuItem(const std::string& title, int id)
		: title(title), id(id) {}

	std::string get_title() { return title; }

	// 메뉴 선택시 호출될 함수
	void command()
	{
		std::cout << get_title() << " 메뉴 선택됨\n";
		_getch();
	}
};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	m1.command(); // 메뉴 선택!

}




