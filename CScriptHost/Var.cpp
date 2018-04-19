#include "StdAfx.h"
#include "Var.h"


CVar::CVar(void):m_type(CType::_void)
{
}


CVar::CVar(char v):m_type(CType::_char)
{
	*((char*)(&m_type+1)) = v;
}

CVar::CVar(short v):m_type(CType::_char)
{
	*((short*)(&m_type+1)) = v;
}

CVar::CVar(int v):m_type(CType::_int)
{
	*((int*)(&m_type+1)) = v;
}

CVar::CVar(long v):m_type(CType::_long)
{
	*((long*)(&m_type+1)) = v;
}

CVar::CVar(float v):m_type(CType::_float)
{
	*((float*)(&m_type+1)) = v;
}

CVar::CVar(double v):m_type(CType::_double)
{
	*((double*)(&m_type+1)) = v;
}

CVar::CVar(const CVar& v):m_type(v.m_type)
{
	*this=v;
}

CVar::~CVar(void)
{
}

CVar CVar::operator=(const CVar& src)
{
	static char CTbl[][6]=
	{
		{1,1,1,1,2,3},//char to |char |short |int |long |float |double
		{1,1,1,1,2,3},//short
		{1,1,1,1,2,3},//int
		{1,1,1,1,2,3},//long
		{4,4,4,4,1,5},//float
		{6,6,6,6,7,1}//double
	};
	if(m_type.TypeOf()==CType::_void) m_type=src.m_type;//void convert
	switch(CTbl[src.m_type.TypeOf()][m_type.TypeOf()])
	{
	case 1:
		memcpy(&m_type+1,&src.m_type+1,m_type.SizeOf());//if src is bigger than *this then only copy lower bytes
		break;
	case 2://int to float
		mov(r1,src);
		r2=r1;
		mov(*this,r2);
		break;
	case 3://int to double
		mov(r1,src);
		r4=r1;
		mov(*this,r4);
		break;
	case 4://float to int
		mov(r3,src);
		r0=r3;
		mov(*this,r0);
		break;
	case 5://float to double
		mov(r3,src);
		r4=r3;
		mov(*this,r4);
		break;
	case 6://double to int
		mov(r5,src);
		r0=r5;
		mov(*this,r0);
		break;
	case 7://double to float
		mov(r5,src);
		r2=r5;
		mov(*this,r2);
		break;
	}

	return *this;
}

CVar  CVar::operator+(const CVar& v) const
{
	static char CTbl[][6]=
	{
		{1,1,1,1,2,3},//char to |char |short |int |long |float |double
		{1,1,1,1,2,3},//short
		{1,1,1,1,2,3},//int
		{1,1,1,1,2,3},//long
		{4,4,4,4,5,6},//float
		{7,7,7,7,8,9}//double
	};

	switch(CTbl[v.m_type.TypeOf()][m_type.TypeOf()])
	{
	case 1://int+int
		mov(r0,*this);
		mov(r1,v);
		return r0+r1;
	case 2://float+int
		mov(r2,*this);
		mov(r1,v);
		return r2+r1;
	case 3://double+int
		mov(r4,*this);
		mov(r1,v);
		return r4+r1;
	case 4://int+float
		mov(r0,*this);
		mov(r3,v);
		return r0+r3;
	case 5://float+float
		mov(r2,*this);
		mov(r3,v);
		return r2+r3;
	case 6://double+float
		mov(r4,*this);
		mov(r3,v);
		return r4+r3;
	case 7://int+double
		mov(r0,*this);
		mov(r5,v);
		return r0+r5;
	case 8://float+double
		mov(r2,*this);
		mov(r5,v);
		return r2+r5;
	case 9://double+double
		mov(r4,*this);
		mov(r5,v);
		return r4+r5;
	}

	return 0;
}

double CVar::r5;

double CVar::r4;

float CVar::r3;

float CVar::r2;

long CVar::r1;

long CVar::r0;
