#include <iostream>
#include <string>
#include <vector>
#include <stack>

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};

struct ICommand
{
	virtual void execute() = 0;
	virtual void undo()     {}
	virtual bool can_undo() { return false; }

	virtual ~ICommand() {}
};

class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(new Rect); }
	bool can_undo() override { return true; }

	void undo() override
	{
		Shape* s = v.back(); //반환만 제거 안됨
		v.pop_back();

		delete s;
	}
};


class AddCircleCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(new Circle);	}
	bool can_undo() override { return true; }

	void undo() override
	{
		Shape* s = v.back(); 

		v.pop_back();

		delete s;
	}
};

class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override  { for (auto s : v) s->draw();	}
	bool can_undo() override { return true; }

	void undo() override {	system("cls");	}
};


int main()
{
	std::vector<Shape*> v;
	
	std::stack<ICommand*> undo_stack;
	std::stack<ICommand*> redo_stack;
	ICommand* command;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			command = new AddRectCommand(v);
			command->execute();
			undo_stack.push(command);
		}
		else if (cmd == 2)
		{
			command = new AddCircleCommand(v);
			command->execute();
			undo_stack.push(command);
		}
		else if (cmd == 9)
		{
			command = new DrawCommand(v);
			command->execute();
			undo_stack.push(command);
		}
		else if (cmd == 0)
		{
			if (!undo_stack.empty())
			{
				command = undo_stack.top();
				undo_stack.pop();

				if (command->can_undo())
				{
					command->undo();

					delete command; // redo 도 지원하려면 지우지 말고
									// redo_stack.push(command) 하면 됩니다.
				}
			}
		}
	}
}

// C# 의 WPF 라이브러리는 "메뉴 선택시" 해야할일을 
// => ICommand 로 부터 상속받는(구현한) 클래스로 만들기를 권장합니다.
// => 함수로 만들어도 가능

// C++ QT에는 "QUndoManager" 클래스도 있습니다.





