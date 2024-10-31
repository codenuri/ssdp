#include <iostream>
#include <list>
#include <vector>




class TwiceVisitor
{
public:
	void visit(int& e) { e *= 2; }
};

template<typename T> class MyList : public std::list<T>
{
public:

	using std::list<T>::list;  

	void accept(TwiceVisitor* visitor)
	{
		for (auto& e : *this)  
			visitor->visit(e);
	}
};

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor tv;
	s.accept(&tv);
}





