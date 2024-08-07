// 정리
// 객체지향 디자인의 
// 
// 핵심 #1. 공통성과 가변성의 분리
// => 변하지 않은 코드에서 변하는 부분은 분리되어야 한다
// => template method, strategy, policy base design

// 핵심 #2. 공통의 기반 클래스를 만드는 경우가 많다.
// => Folder 는 File 을 보관하지만 Folder도 보관
//    Folder 과 File 는 공통의 기반 클래스 필요 => composite

// => FileStream 에 압축기능을 추가하고, 다시 암호화 기능도 추가
//    "decorator"

// 핵심 #3. 어떤 문제를 해결하기 위해 "중간층(간접층)"을 도입하는 것

// 왜 ? 중간층을 만들었는가 ??
// 의도에 따라 패턴이 달라집니다.
// 항상, "의도" 가 핵심

// 사용자 ============== ZipDecorator =================> FileStream
//								=> 중간층을 만든 의도 : 기능의 추가
//								=> "decorator" 패턴
// 
// 사용자 ============== stack ========================> std::list
//								=> 중간층을 만든 의도 : 인터페이스의 변경
//								=> "adapter" 패턴
// 		
// 사용자 ============== MP3  =========================> IMP3
//							=> 의도 :추상층과구현층을 독립적으로 update 하기위해
//							=> "bridge" 패턴
// 
// 사용자 ============== TCPServer ====================> Socket, IPAddress
//							=> 의도 : 사용하기 쉽게 
//							=> "facade"
// 
// 사용자 ============== Calc  ========================> 계산기서버
//							=> 다양한 용도의 "대신 사용하기 위해"
//							=> "proxy" 패턴.