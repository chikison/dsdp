#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include <functional> // std::bind(), std::function<>
using namespace std::placeholders;

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








class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	~PopupMenu()
	{
		for (auto m : v)
			delete m;
	}




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
};

class MenuItem : public BaseMenu
{
	using HANDLER = std::function<void()>; // 인자가 없는 함수
										   // 그런데, std::bind()가 있으므로
										   // 모든 함수 등록가능(void반환)
	std::vector<HANDLER> v; // 메뉴 선택시 여러곳에 전달
							// 관찰자 패턴응용


	int  id;


public:
	MenuItem(const std::string& title, int id, HANDLER h = nullptr )
		: BaseMenu(title), id(id) 
	{
		if (h != nullptr)
			v.push_back(h);
	}

	void add_handler(HANDLER h)
	{
		if (h != nullptr)
			v.push_back(h);
	}



	void command()
	{
		// 메뉴 선택시 등록된 모든 함수에 알려준다.
		// => 관찰자 패턴
		for (auto f : v)
			f();	// f는 function 이므로 ()로 호출가능
					// 인자 없는 함수.. 
	}
};

void foo()
{
	std::cout << "foo 호출됨 - 여기서 메뉴선택시 해야 할일 작성\n";
	std::cout << "아무키나 누르면 메뉴로 돌아갑니다\n";
	_getch();
}

void goo(int id)
{
	std::cout << "goo 호출됨 - 여기서 메뉴선택시 해야 할일 작성\n";
	std::cout << "아무키나 누르면 메뉴로 돌아갑니다\n";
	_getch();
}



int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("색상 변경");
	PopupMenu* pm2 = new PopupMenu("해상도 변경");

	root->add(pm1);
	root->add(pm2);

	pm1->add(new MenuItem("RED", 11, &foo));
	pm1->add(new MenuItem("GREEN", 12, std::bind(&goo, 12)));
	pm1->add(new MenuItem("BLUE", 13,  std::bind(&goo, 13)));
	pm1->add(new MenuItem("WHITE", 14));

	pm2->add(new MenuItem("HD", 21));
	pm2->add(new MenuItem("FHD", 22));
	pm2->add(new MenuItem("UHD", 23));

	MenuItem* m = new MenuItem("8K", 24, &foo);
	m->add_handler(std::bind(&goo, 24));

	pm2->add(m);

	root->command();

	// 위 코드는 모든 메뉴를 new 로 만들었습니다.
	// delete 해야 합니다.
	// 방법 #1. Raw Pointer 대신 스마트 포인터(std::shared_ptr) 사용
	// 방법 #2. root 만 delete 하면 모두 delete 될수 있게

	delete root; // PopupMenu 소멸자 호출
				 // => 소멸자에서 자신의 하위 메뉴 삭제..
				 // => 결국 재귀적으로 모든 메뉴 delete 됨!!!@
}

// 복습하실때.. 위 코드에
// #1. DAY2/메뉴8.cpp  내용 합쳐 보세요
// #2. DAY4/visitor4.cpp 내용(메뉴 방문자) 합쳐 보세요

// 즉, 따로 배운 내용들을 합해서 완벽한 메뉴 만들어 보세요.