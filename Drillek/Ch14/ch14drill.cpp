#include "std_lib_facilities.h"

using namespace std;

class B1 {
public:
	virtual void vf() const
		{ cout << "B1::vf\n"; }
	void f() { cout << "B1::f\n"; }
	virtual void pvf() =0;

};

class D1 : B1 {
public:
	void vf() { cout << "D1::vf\n";}
};

class D2 : D1 {
public:
	void pvf() { cout << "D2::pvf\n"; }
};

class B2 {
public:
	virtual void pvf() =0;
};

class D21 {
public:
	void pvf() { cout << z << endl; }
	string z;
};

class D22 {
public:
	void pvf() { cout << r << endl; }
	int r;
};

void call(const B1& b1)
{
	b1.vf();
	b1.f();
}


int main()
{
	//B1 b1;
	//b1.vf();
	//b1.f();

	//D1 d1;
	//d1.vf();
	//d1.f();

	//B1& bref = d1;
	//bref.vf();
	//bref.f();

	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();

	D21 d21;
	d21.z = "d21.z";
	D22 d22;
	d22.r = 22;
	f(d21);
	f(d22);
}