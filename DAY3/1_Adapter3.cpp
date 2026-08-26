// 디자인 패턴을 열심히 학습하다 보면
// => 어느 순간 "여러 패턴이 동일하게 보이게 됩니다."
// => 이런 순간이 오면 항상 "의도"를 생각하세요

// Decorator vs Adaptor
// => 2개 패턴은 코드가 유사해 보입니다

class ZipDecorator : public Stream
{
	Stream* origin;
public:
	ZipDecorator(Stream* s) : origin(s) {}

	void write(const std::string& s) override
	{
		auto s2 = "[ " + s + "] 압축됨";

		origin->write(s2);
	}
};

class ObjectAdapter : public Shape
{
	TextView* origin; 
public:
	ObjectAdapter(TextView* tv) : origin(tv) {}

	void draw() override
	{
		origin->show();
	}
};



FileStream fs("a.txt");
ZipDecorator zd(&fs);

fs.write("hello");
zd.write("hello");


