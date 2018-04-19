#pragma once
#include "Var.h"
#include <string.h>
class CStack
{
public:
	CStack(void);
	~CStack(void);

	void sign(void);//sign a new namespace
	int push(CType &type,char *szVarName);//increase stack size by var type,return a virtual address
	void pop();//move top to sign
	void alloc(void);//allocate memory by size,so when pushing finished,it's neccessary to invoke allocate
	void free(void);//free memory

	void getVar(int virtualAddr,CVar *&pv);//get var address in memory by virtual address(in stack)
	uint getVarVirtualAddress(char *szVarName);
private:
	typedef struct Node
	{
		char *szVarName;
		int nVirtualAddr;
		Node *next;
	}Node,*List;
	int m_nSize;//bytes
	char *m_pBottom;
	int m_top;
	int m_sign;
	Node m_head;//a link list with head node
};

