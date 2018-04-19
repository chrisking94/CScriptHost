#pragma once
#include "stdafx.h"

class CType
{
public:
	typedef enum
	{
		_char,
		_short,
		_int,
		_long,
		_float,
		_double,
		_void,
	}TYPE;
public:
	CType(void);
	CType(const char &t);
	CType(TYPE t,int ptrLv=0,char _signed=1);
	~CType(void);

	uchar SizeOf() const;
	TYPE TypeOf() const;
	uchar PtrLevel() const;
	void IncPtrLevel();
	void DecPtrLevel();
private:
	uchar m_t;
};

