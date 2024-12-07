
#include <iostream>
#include <vector>


struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}
};

// Table 의 데이타의 종류에 상관없이
// 관찰자 패턴의 기본 로직은 동일합니다.
// 관찰자 패턴의 기본 로직을 제공하는 기반 클래스를 설계
// 디자인 패턴에 관찰의 대상을 "Subject" 라고 합니다.
class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int data)
	{
		for (auto p : v)
			p->update(data);
	}
};

// 앞으로 다양한 형태의 관찰의 대상(Table) 을 만들때는
// Subject 에서 상속 받으면 됩니다.
class Table : public Subject
{
	int value; 
public:

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





