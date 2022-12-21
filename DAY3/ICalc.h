// ICalc.h
#pragma once

// Proxy 객체의 수명을 "참조계수"로 관리한다면
// 참조 계수 함수도 인터페이스에서 노출해 주어야 합니다!!!

// 다양한 서버에 다양한 Proxy 가 존재 할수 있지만
// 모두 참조계수 함수가 필요 합니다.

// 참조계수 기능만 가진 별도의 인터페이스를 제공합니다.

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

