// helper.h
#pragma once

#define MAKE_SINGLETON(classname)			\
private:									\
	classname() {}							\
public:										\
	static classname& getInstance()			\
	{										\
	static classname instance;				\
		return instance;					\
	}										\
public:										\
	classname(classname&) = delete;			\
	void operator=(classname&) = delete;	\
private:

