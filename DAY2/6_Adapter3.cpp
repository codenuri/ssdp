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


TextView tv("hello");
ObjectAdapter oa(&tv);



FileStream fs("a.txt");
ZipDecorator zd(&fs);