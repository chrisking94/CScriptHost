// CScriptHost.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Var.h"
#include "Stack.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//С��ģʽ
	//intתuint��ֱ�Ӹ����ڴ�

	float a=1.1;
	unsigned long k=a;
	
	CStack s;
	int addr=s.push(CType(CType::_int),"king");
	int addr2=s.push(CType(CType::_int),"is");
	s.alloc();
	CVar *p,*q;
	*p=10;
	*q=11;
	s.getVar(addr2,q);
	s.getVar(addr,p);
	*p=*p+*q;
	printf("%u\n",*(int*)(p->ptr()));
	//printf("%02X",*(char*)((&a)+1));
	getchar();
	return 0;
}

