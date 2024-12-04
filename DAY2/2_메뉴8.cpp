#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class unsupported_operation {};

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title)
		: title(title) {
	}

	virtual ~BaseMenu() {}

	std::string get_title() { return title; }

	virtual void command() = 0;


	// 아래 멤버 함수는 Popup에만 있으면 되지만
	// "캐스팅 없이 사용하게 하기 위해" Base에도 추가
	virtual void add(BaseMenu* m)      { throw unsupported_operation(); }
	virtual BaseMenu* submenu(int idx) { throw unsupported_operation(); }
};






class MenuItem : public BaseMenu
{
	int  id;
public:
	MenuItem(const std::string& title, int id)
		: BaseMenu(title), id(id) {
	}

	void command()
	{
		std::cout << get_title() << " 메뉴 선택됨\n";

		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add(BaseMenu* m) { v.push_back(m); }

	void command()
	{
		while (1)
		{
			system("cls");

			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << '\n';
			}
			std::cout << sz + 1 << ". 종료\n";

			std::cout << "메뉴를 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;


			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;


			v[cmd - 1]->command();

		}
	}

	BaseMenu* submenu(int idx) { return v[idx]; }
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("색상 변경");

	root->add(pm1);
	root->add(new MenuItem("REBOOT", 21));

	//----------------------------------------------
	// static_cast<PopupMenu*>(root->submenu(0))->add(new MenuItem("RED", 11));

	// 캐스팅이 있으면 복잡해 보입니다.
	// 캐스팅 없이 아래와 같이 사용하게 해 봅시다.
	root->submenu(0)->add(new MenuItem("RED", 11)); // ok


	// 단 아래 처럼 사용하면 "PopupMenu" 가 아닌 MenuItem 인데
	// add 호출하므로 예외 발생
	try
	{
		root->submenu(1)->add(new MenuItem("RED", 11)); // 
	}
	catch (...)
	{
		std::cout << "예외\n";
	}


	root->command();
}





// add, submenu 를 BaseMenu 에 넣는 모델
// => 캐스팅이 없이 사용가능하게 되므로 편리합니다
// => 편의 모델!!

// add, submenu 를 BaseMenu 에 넣지 않는 모델
// => 캐스팅이 필요해 질수 있으므로 편리하지 않지만
// => 항상 캐스팅을 통해서 의도가 표현되므로 "안전 합니다"
// => 안전성을 중시하는 모델..
