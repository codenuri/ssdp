// 디자인 패턴을 열심히 공부하면, 다양한 패턴이 동일(유사)해 보일때가 있습니다.
// 이럴때는 의도를 생각하세요. 의도가 가장 중요 합니다.

class ObjectAdapter : public Shape
{
	TextView* origin;	
public:
	ObjectAdapter(TextView* p) : origin(p) {}

	void draw() override { origin->show(); }
};

class ZipDecorator : public Stream
{
	Stream* origin; 
public:
	ZipDecorator(Stream* s) : origin(s) {}

	void write(const std::string& s) override
	{
		auto s2 = "[( " + s + " ) 압축됨]";
		origin->write(s2);
	}
};

// adapter : 기능은 동일한데, 함수이름을 변경하려는 것
//			 인터페이스의 변경
TextView tv("hello");
ObjectAdapter oa(&tv);
tv.show();
oa.draw();

// decorator : 인터페이스는 동일한데, 기능이 추가된것
FileStream fs("a.txt");
ZipDecorator zd(&fs);
fs.write("hello");
zd.write("hello");

// 다양한 패턴이 헷갈릴때는 항상 "의도" 를 생각하세요