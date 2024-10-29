// decorator 와 object adapter 는 코드가 유사해 보입니다.

// decorator
class ZipDecorator : public Stream
{
	Stream* origin;
public:
	ZipDecorator(Stream* s) : origin(s) {}

	void write(const std::string& s)
	{
		auto s2 = "[ " + s + "] 압축됨"; 

		origin->write(s2);				
	}
};

// adapter
class ObjectAdapter : public Shape
{
	TextView* tview; 
public:
	ObjectAdapter(TextView* t) : tview(t) {}

	void draw()
	{
		tview->show();
	}
};

int main()
{
	// 패턴을 정확히 이해하기 시작하면서 느끼게 되는 것은
	// 다양한 패턴이 "동일(유사)"해 보이기 시작합니다.
	// 그럴때는 각 패턴의 의도를 항상 생각하세요

	// decorator 목적 : 기능의 추가
	FileStream fs("a.txt");
	ZipDecorator zd(&fs);

	fs.write("abcd");
	zd.write("abcd");	// 원본과 동일한 함수 이름이지만
						// 압축 기능의 추가

	// adapter 목적 : 인터페이스의 변경
	TextView tv("hello");
	ObjectAdapter oa(&tv);

	tv.show(); // 원래 함수의 이름을
	oa.draw(); // 이렇게 변경하는 것(기능은 동일)
}
