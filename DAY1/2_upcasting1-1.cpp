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
	Dog d;

//	Animal* p = &d;	
	Animal* p = &a;

	// static_cast vs dynamic_cast

	Dog* p1 = static_cast<Dog*>(p);


}











