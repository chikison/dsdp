#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// list : 선형 구조이고, 모든 요소의 타입이 동일 합니다.
// Menu : Tree 구조이고, 요소의 타입이 다를수 있습니다.

class MenuItem;
class PopupMenu;

struct IMenuVisitor
{
	// 아래 처럼 하면 모든 메뉴 객체를 받을수 있지만
	// => 같은 동작을 하게 됩니다.
//	virtual void visit(BaseMenu* m) = 0;

	// 아래 처럼해야 다른 동작이 됩니다.
	virtual void visit(MenuItem* m) = 0;
	virtual void visit(PopupMenu* m) = 0;	

	virtual ~IMenuVisitor() {}
};


class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	void set_title(const std::string& s) { title = s; }

	virtual void command() = 0;

	virtual void accept(IMenuVisitor* visitor) = 0;
};


class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}


	// 방문자가 MenuItem 을 방문할때
	void accept(IMenuVisitor* visitor)
	{
		// #1. 자신을 방문자에 전달하기만 하면 됩니다.
		visitor->visit(this);

		// MenuItem 은 하위 메뉴 없습니다.
	}





	void command() override
	{
		std::cout << get_title() << " 메뉴가 선택됨" << std::endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	// 방문자가 PoupMenu 를 방문할때 - 이부분이 핵심
	void accept(IMenuVisitor* visitor)
	{
		// #1. 자신을 먼저 방문자에 전달
		visitor->visit(this);

		// #2. 자신의 하위 메뉴를 전달하면
		// 직계 자식만 전달됩니다.
		// 아래 처럼하면 안됩니다.
		//for (auto m : v)
		//	visitor->visit(m);
		
		// #2. 자신의 하위 메뉴에 방문자를 방문 시켜야 합니다.
		for (auto m : v)
			m->accept(visitor); // 이렇게 해야 합니다.

	}






	void add_menu(BaseMenu* p) { v.push_back(p); }

	void command() override
	{
		while (1)
		{
			system("cls");

			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}

			std::cout << sz + 1 << ". 종료" << std::endl;

			int cmd;
			std::cout << "메뉴를 선택하세요 >> ";
			std::cin >> cmd;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			if (cmd == sz + 1)
				break;

			v[cmd - 1]->command();
		}

	}

};

// 메뉴의 타이틀을 변경하는 방문자
class MenuTitleChangeVisitor : public IMenuVisitor
{
	std::string item_deco;
	std::string popup_deco;
public:
	MenuTitleChangeVisitor(const std::string& s1, const std::string& s2)
		: popup_deco(s1), item_deco(s2) {}

	void visit(MenuItem* m) override
	{
		auto s = m->get_title();
		s = s + item_deco;
		m->set_title(s);
	}
	void visit(PopupMenu* m) override
	{
		auto s = m->get_title();
		s = s + popup_deco;
		m->set_title(s);
	}

};




int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	PopupMenu* pm2 = new PopupMenu("색상 변경");

	root->add_menu(pm1);
	root->add_menu(pm2);
	root->add_menu(new MenuItem("Reboot", 31));


	pm1->add_menu(new MenuItem("HD", 11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));

	pm2->add_menu(new MenuItem("RED", 21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));


	MenuTitleChangeVisitor v(" >", "*");

	root->accept(&v);

	// 이제 Menu 에 대해서 다양한 연산이 필요 하면
	// MenuTitleChangeVisitor 와 같은 것을 만드세요
	// 그리고 root 에 넣으세요
//	TitleColorVisitor v2(red, green);
//	root->accept(&v2);


	// Menu 는 iterator 같은 것이 없으므로 외부에서는 열거 못합니다.
	// 방문자를 사용하면 됩니다.

	root->command();

}




