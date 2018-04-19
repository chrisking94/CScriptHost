#pragma once
#include "Type.h"

class CVar
{
public:
	//ctor
	CVar(void);
	CVar(char v);
	CVar(short v);
	CVar(int v);
	CVar(long v);
	CVar(float v);
	CVar(double v);
	CVar(const CVar& v);
	~CVar(void);

	//operator
	CVar operator=(const CVar& src);
	CVar operator+(const CVar& v) const;
	CVar &operator-(const CVar& v) const;
	CVar &operator*(const CVar& v) const;
	CVar &operator/(const CVar& v) const;
	CVar &operator%(const CVar& v) const;
	CVar &operator<<(const CVar& v) const;
	CVar &operator>>(const CVar& v) const;
	CVar &operator&(const CVar& v) const;
	CVar &operator|(const CVar& v) const;
	CVar &operator~() const;
	CVar &operator!() const;
	CVar &operator^(const CVar& v) const;
	void operator+=(const CVar &v);
	void operator-=(const CVar &v);
	void operator*=(const CVar &v);
	void operator/=(const CVar &v);
	void operator%=(const CVar &v);
	void operator<<=(const CVar& v) const;
	void operator>>=(const CVar& v) const;
	void operator&=(const CVar& v) const;
	void operator|=(const CVar& v) const;
	bool operator!=(const CVar& v) const;
	bool operator==(const CVar& v) const;
	bool operator>(const CVar& v) const;
	bool operator<(const CVar& v) const;
	bool operator>=(const CVar& v) const;
	bool operator<=(const CVar& v) const;
	CVar &operator*();//only available for _ptr
	long ptr() const{return (long)(&m_type+1);}
private:
	//--virtual register
	static long r0,r1;
	static float r2,r3;
	static double r4,r5;
	static void mov(long &reg,const CVar &v){memcpy(&reg,&v.m_type+1,v.m_type.SizeOf());}
	static void mov(float &reg,const CVar &v){memcpy(&reg,&v.m_type+1,v.m_type.SizeOf());}
	static void mov(double &reg,const CVar &v){memcpy(&reg,&v.m_type+1,v.m_type.SizeOf());}
	static void mov(const CVar &v,long &reg){memcpy((void*)(&v.m_type+1),&reg,v.m_type.SizeOf());}
	static void mov(const CVar &v,float &reg){memcpy((void*)(&v.m_type+1),&reg,v.m_type.SizeOf());}
	static void mov(const CVar &v,double &reg){memcpy((void*)(&v.m_type+1),&reg,v.m_type.SizeOf());}
private:
	CType m_type;
	//data is stored in stack(or heap),and it follows [m_type] imediately
};

