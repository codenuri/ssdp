// 방문자 정리
// 1. 결국 방문자는 "요소 한개에 적용할 연산을 정의" 하고

template<typename T>
class TwiceVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { e *= 2; }	// 요소 한개에 대한 정의
};


// 2. 복합객체가 자신의 모든 요소를 방문자에 전달 하는 것

template<typename T> class MyList : public std::list<T>
{
public:
	using std::list<T>::list;

	void accept(IVisitor<T>* visitor)
	{
		// 모든 요소를 방문자에 전달.
		for (auto& e : *this)
			visitor->visit(e);
	}
};
