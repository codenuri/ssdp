// this1.cpp
class Point
{
	int x, y;
public:
	void set(int a, int b) // void set(Point* this, int a, int b)
	{
		x = a;		// this->x = a;
		y = b;		// this->y = b;
	}
};

int main()
{
	Point p1;
	Point p2;
	p1.set(1, 2); // set(&p1, 1, 2)  이 한줄의 원리를 생각해 봅시다
	p2.set(1, 2); // set(&p2, 1, 2)
}