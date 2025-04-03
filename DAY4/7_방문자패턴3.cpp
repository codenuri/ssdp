#include <iostream>
#include <list>
#include <vector>


int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;
	s.Accept(&tv);			


	ShowVisitor<int> sv;	
	s.Accept(&sv);


}





