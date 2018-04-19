#include "StdAfx.h"
#include "Stack.h"


CStack::CStack(void):
m_nSize(0)
,m_pBottom(NULL)
{
}


CStack::~CStack(void)
{
}

void CStack::sign(void)
{
	m_sign=m_top;
}

int CStack::push(CType &type,char *szVarName)
{
	int addr=++m_top;//now m_top point [type]
	m_top+=type.SizeOf();

	Node *p=new Node;
	p->nVirtualAddr=addr;
	p->szVarName=new char[strlen(szVarName)+1];
	strcpy(p->szVarName,szVarName);
	p->next=m_head.next;
	m_head.next=p;

	return addr;
}

void CStack::pop()
{
	Node *p=m_head.next,*q;
	while(p&&p->nVirtualAddr>m_sign)
	{
		q=p->next;
		delete []p->szVarName;
		delete p;
		p=q;
	}
	m_head.next=p;
}

void CStack::alloc(void)
{
	m_nSize=m_top+1;
	m_pBottom=new char[m_nSize];
}

void CStack::free(void)
{
	delete []m_pBottom;
}

void CStack::getVar(int virtualAddr,CVar *&pv)
{
	pv=(CVar*)(m_pBottom+virtualAddr);
}

uint CStack::getVarVirtualAddress(char *szVarName)
{
	Node *p=m_head.next;
	while(p)
	{
		if(!strcmp(p->szVarName,szVarName))//found
		{
			return p->nVirtualAddr;
		}
		p=p->next;
	}

	return 0;//not found
}

