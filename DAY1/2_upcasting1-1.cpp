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
	Animal a;
	Dog    d;

	Animal* p = &d;
	
	// static_cast : 
	Dog* dog = static_cast<Dog*>(p);

	std::cout << dog << std::endl;
}











