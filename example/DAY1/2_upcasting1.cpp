// 7 page

class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog d;
	Dog* p1 = &d; 
	int* p2 = &d; 
	Animal* p3 = &d; 

}











