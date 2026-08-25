class Dialog
{
public:
	void close(int a) {}
};

void foo(int a) {}

int main()
{
	void(*f1)(int) = &foo; // ok
	void(*f1)(int) = &Dialog::close; // ?? 될까요 ?
}