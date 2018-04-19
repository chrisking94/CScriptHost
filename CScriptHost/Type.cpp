#include "StdAfx.h"
#include "Type.h"


unsigned char CType::SizeOf() const
{
	//basic type
	switch((TYPE)(m_t&0x0f))
	{
	case _char:
		return 1;
		break;
	case _short:
		return 2;
		break;
	case _int:
	case _float:
		return 4;
		break;
	case _long:
	case _double:
		return 8;
		break;
	}

	return 0;
}

CType::TYPE CType::TypeOf() const
{
	return (TYPE)(m_t&0x0f);
}

CType::CType(void)
{
}


CType::CType(const char &t)
{
	m_t = t;
}

CType::CType(TYPE t,int ptrLv/*=0*/,char _signed)
{
	m_t=t;
	m_t|=ptrLv<<4;
	m_t|=_signed<<7;
}

CType::~CType(void)
{
}
