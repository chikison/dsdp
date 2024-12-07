// 정리. - 교재 마지막 페이지 참고해서 보세요..

// 핵심 #1. 변하지 않은 코드에서 변하는 것을 분리해라
// => 변하는 것을 어떻게 분리할것인가 ??

// 1.1 변하는 것을 가상함수로 
// => 가상함수로 정책이나 알고리즘 결정 : template method 
// => 가상함수로 객체의 타입 결정      : factory method

// 1.2 변하는 것을 다른 클래스로
// 
// strategy : 객체가 사용하는 알고리즘을 실행시간에 교체 가능하게
//				(Edit/IValidator)
// 
// state : 객체의 상태에 따라 모든 동작 교체 
//			(캐릭터 아이템에 따른 동작 교체, 
//			 자판기 동전 유무에 따른 모든 동작 교체)
// 
// 
// builder : 복잡한객체를 만들때 동일 공정으로, 각 공정의 표현은 다르게
//    

// policy base design : 객체가 사용하는 알고리즘(정책)을 교체 하는데, 인터페이스가 아닌
//		템플릿 인자로, vector 의 allocator 교체 

// 핵심 #2. 재귀적 포함을 사용하는 패턴
// => A는 B를 포함하지만 A 도 포함할수 있다.
// => A, B는 공통의 기반 클래스 필요

// 왜?, 어떤의도로 재귀적 포함을 하는가 ?
// composite : 재귀적 포함으로 복합객체 만들기, Folder/File, PopupMenu/MenuItem
// decorator : 재귀적 포함으로 동적 기능추가   FileStream /ZipDecorator예제

// 핵심 #3. 간접층으로 문제 해결
// adapter : 인터페이스 변경, list를 stack 처럼 보이게
// bridge  : 구현과 사용계층의 분리, update 를 독립적으로 
// proxy   : 대신할것을 만들자, Remote 서버에 대한 CalcProxy
// facade  : 사용하기 쉽게, TCPServer


// 핵심 #4. undo/redo 가 가능하게 
// memento : 객체 상태의 저장에 따른 undo
// command : 명령을 클래스로 설계. undo 와 필요한 데이타 보관


// 핵심 #5. 열거, 방문, 통보, 전달
// observer : 1의 변화를 N에 통보
// chain of responsibility : 차례대로 옆으로 전달
// iterator : 복합객체를 동일하게 열거
// visitor : 복합객체의 모든 요소에 적용될 연산을 전달


// 디자인 패턴은 용도에 따라 3가지로 분류 합니다.

// 생성 패턴 5개
// => singleton,
// => prototype
// => abstract factory
// => factory method
// => builder 

// 구조 패턴 7개
// 재귀적 포함 : composite, decorator
// 간접층      : adapter, proxy, bridge, facade
// 속성이동일하면 공유 : flyweight

// 행위 패턴 11개
// 열거방문 : iterator, visitor
// undo/redo : command, memento
// 통보, 전달 : observer, chain of responsibility
// 중재		 : mediator
// 변화의 분리 : template method, strategy, state 
// 컴파일러 만들때 사용했던 패턴(지금은 거의 사용안함) : iterpreter





