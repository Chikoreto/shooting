#pragma once

template <typename _T>
class Singleton 
{
protected:
	Singleton() {}
	virtual ~Singleton() {}
	Singleton(const Singleton& r) {}
	Singleton& operator = (const Singleton&) {}

public:
	static _T* Instace()
	{
		static _T inst;
		return &inst;
	}
};