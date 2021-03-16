// g++ ch14.cpp -o ch

#include "std_lib_facilities.h"

class B {
public:
	virtual void pvf() =0;
};

class B1 : public B{	//B kiterjesztése
public:
    virtual void vf() const { cout << "B1::vf()\n"; }
    void f() const { cout << "B1::f()\n"; }
    void pvf() override { cout << "B1::pvf()\n"; };
};

class D1 : public B1 {	//B1 kiterjesztése
public:
    void vf() const { cout << "D1::vf()\n"; }
    void f() { cout << "D1::f()\n"; }
    void pvf() override { cout << "D1::pvf()\n"; };
};

class D2 : public D1 {	//D1 kiterjesztése
public:
    void pvf() override { cout << "D2::pvf()\n"; };
};

class B2 {
public:
    virtual void pvf() =0;
};

class D21 : public B2 {	//B2 kiterjesztése
public:
    void pvf() override { cout << s << endl; }
    string s;
};

class D22 : public B2 {	//B2 kiterjesztése
public:
    void pvf() override { cout << n << endl;}
    int n;
};

void f(B2& b2)	//kiír attól függően, hogy melyik osztályban vagyunk
{
    b2.pvf();
}

int main() 
try {	//példányok
    B1 b1;	//B típusó objektum tagjainak meghívása
    b1.vf();
    b1.f();
    b1.pvf();

    cout << endl;

    D1 d1;	//ez is egy B
    d1.vf();	
    d1.f();
    d1.pvf();

    cout << endl;

    B1& bref = d1;
    bref.vf();	//b2 obj vf tagját hívom --> Dvf, B1-ben ez virtuális
    bref.f();	//nem virtuális, nem overrideol, ezért marad B1f
    bref.pvf();

    cout << endl;

    D2 d2; //ez is egy B
    d2.f();
    d2.vf();
    d2.pvf();

    cout << endl;

    D21 d21;
    d21.s = "d21.s";
    D22 d22;
    d22.n = 22;
    f(d21);
    f(d22);

    return 0;
} catch (exception& e){
    cerr << e.what() << endl;
    return 1;
} catch (...){
    cerr << "Something went wrong!" << endl;
    return 2;
}