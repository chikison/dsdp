#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

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
	auto m = root->submenu(0); // m은 "색상변경" 메뉴의 포인터

	// 아래 한줄을 생각해 봅시다.
//	root->submenu(0)->add( new MenuItem("RED", 11) );
						// => error
						// => "add" 는 PopupMenu에 있는데
						// => "submenu" 이 반환 타입은 "BaseMenu*" 이므로

	// 아래 처럼 캐스팅해서 사용하면 됩니다.
	static_cast<PopupMenu*>(root->submenu(0))->add(new MenuItem("RED", 11));



	root->command();
}




