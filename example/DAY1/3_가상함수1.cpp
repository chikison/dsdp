#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal cry" << std::endl; } 
};
class Dog : public Animal
{
public:
	void cry() { std::cout << "Dog cry" << std::endl; } 
};
int main()
{
	Dog d;
	Animal* p = &d; 

	p->cry();
}


