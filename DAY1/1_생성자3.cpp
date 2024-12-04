// 1_생성자2.cpp
#include <string>
#include <iostream>

class Person
{
	std::string name;
	int age;
public:
	// 클래스 설계시, 항상 생성자에서 멤버 데이타를 초기화하는 것이
	// 좋습니다.
	Person(const std::string& name, int age)
		: name(name), age(age) {}
};

// 1. Person 에서 상속 받는 Student 만들어 보세요
// 2. int id 멤버 데이타 추가하세요
// 3. Student 생성자 만들어 보세요(id 초기화)
// 4. main 에서 Student 객체 생성해 보세요

class Student : public Person
{
	int id;
public:
	// 이렇게 만들면  컴파일러가					이렇게 변경합니다.
	// Person 에 디폴트 생성자가 없어서 error
//	Student(int id) : id(id) { } // Student(int id) : Person(), id(id) { } 

	// #1. Student 를 만드는 사람은 Person 에 디폴트 생성자가 없다는 것을
	//     알아야 합니다.
	// #2. 아래처럼 만들어야 합니다.

	Student(const std::string& name, int age, int id) 
		: Person(name, age), id(id) {}
};

int main()
{
	Student s("kim", 20, 50);
	Person p1("kim", 20);

//	Person p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체)
}


