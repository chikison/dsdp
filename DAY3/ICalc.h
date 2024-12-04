// ICalc.h
#pragma once

// 레퍼런스 카운팅(참조계수) 기법으로 Proxy의 수명을 관리하는 경우
// 참조계수 관련 함수는 인터페이스에도 있어야 합니다.

struct IRefCount
{
	virtual void AddRef() = 0;
	virtual void Release() = 0;

	virtual ~IRefCount() {}
};

struct ICalc : public IRefCount
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

/*
struct IMoterServerProxy : public IRefCount
{
	// 모터 서버 관련 함수
};
*/




ICalc* load_proxy()
{
	// #1. DLL 을 Load 합니다
	void* addr = ec_load_module("CalcProxy.dll");
	// linux : dlopen()    windows : LoadLibrary()

// #2. DLL 에서 약속된 함수를 찾습니다.
	typedef ICalc* (*F)();

	F f = (F)ec_get_function_address(addr, "create");
	// linux : dlsym()		windows : GetProcAddress()

// #3. 약속된 함수로 Proxy 객체 생성후 반환

	return f();
}
