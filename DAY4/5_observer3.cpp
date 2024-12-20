﻿#include <iostream>
#include <vector>

class Subject;	// 클래스 전방 선언
				// 완전한 선언이 없어도, 포인터 변수는 만들수 있다.

struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}

	// 모든 그래프는 자신과 연결된 Table(Subject) 이 있습니다.
	Subject* subject = nullptr;
};



class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) 
	{ 
		v.push_back(p); 

		p->subject = this;
	}

	void detach(IGraph* p) {}
	void notify(int data)
	{
		for (auto p : v)
			p->update(data);
	}
};

class Table : public Subject
{
	int value;

	int data[5];
public:
	int* get_data() { return data; }


	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;
			notify(value);
		}
	}
};



//----------------------
class BarGraph : public IGraph
{
public:
	void update(int n) override
	{
		// Table 의 상태가 변경되었다고 통보가 왔다.
		// 1. 인자로 전달된 값으로만으로도 그릴수 있다면 그리면 된다.
		// 2. 더 많은 데이타가 필요하면 Table에 접근해서 data 를 얻어 온다.

//		int* data = subject->get_data(); // error.
										 // subject 는 Table 의 주소지만
										 // 타입이 "Subject*" 입니다
		int* data = static_cast<Table*>(subject)->get_data();

		// 이제 data 를 사용해서 Graph 를 update 하면 됩니다.

		std::cout << "Bar Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "*";

		std::cout << std::endl;
	}
};




class PieGraph : public IGraph
{
public:
	void update(int n) override
	{
		std::cout << "Pie Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << ")";

		std::cout << std::endl;
	}
};

int main()
{
	Table t;
	PieGraph pg; t.attach(&pg);
	BarGraph bg; t.attach(&bg);

	t.edit();
}





