// function1.cpp
#include <iostream>
#include <functional>
using namespace std::placeholders; // _1, _2, _3, ... 10�� ���� 
void f1(int n1) {}
void f2(int n1, int n2) {}

void f4(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	f4(1, 2, 3, 4); // 4�� �Լ�

	// std::bind : �Լ��� ���ڸ� ������ ���ο� �Լ��� ����� ����
	// ���� : std::bind(M���Լ��ּ�, M�� ���� )

	auto a1 = std::bind(&f4, 1, 2, 3, 4); // 4���Լ� => 0���Լ�

	a1(); // f4(1,2,3,4)


	auto a2 = std::bind(&f4, 5, _1, 7, _2);

	a2(3, 8); // f4(5, 3, 7, 8);


	auto a3 = std::bind(&f4, _2 , _3, 4, _1); // ? ��ġ ä�켼��(4��..)

	a3(7, 3, 8); // f4(3, 8, 4, 7) �������� ? ä�켼��


	// ���� std::bind �� ��ȯ Ÿ���� ��� ����ϳĿ� ���� ��� �ٸ��ϴ�.
	// ����, a1, a2, a3 �� Ÿ���� ��� �ٸ��ϴ�.
	// �׷��� auto �� �������Դϴ�.

	// std::bind ���� ������ ���̽㿡�� �ֽ��ϴ�
	// => functools.partial() �Դϴ�.
}