#include "std_lib_facilities.h"

template<class T> struct S {
    S() : val(T()) { }
    S(T d) : val(d) { }     // 2
    T& operator=(const T&); // 10
    T& get();               // 5
    const T& get() const;   // 11
    void set(const T& d);   // 9
private:
    T val;
};

template<class T> T& S<T>::operator=(const T& d)	// 10. feladat
{
    val = d;
    return val;
}

// 6. feladat
template<class T> T& S<T>::get() { return val; }	// get definíciója a classon kívül

template<class T> const T& S<T>::get() const { return val; }

template<class T> void S<T>::set(const T& d) { val = d; }

// -----------------------------------------------------------------------------

// 12. feladat
template<class T> istream& operator>>(istream& is, S<T>& ss)
{
    T v;
    cin >> v;
    if (!is) return is;
    ss = v;
    return is;
}

template<class T> void read_val(T& v)
{
    cin >> v;
}

// -----------------------------------------------------------------------------

// Drill 14
template<class T> ostream& operator<<(ostream& os, const vector<T>& d)
{
    os << "{ ";
    for (int i = 0; i<d.size(); ++i) {
        os << d[i];
        if (i<d.size()-1) os << ',';
        os << ' ';
    }
    os << "}";
    return os;
}

template<class T> istream& operator>>(istream& is, vector<T>& d)
{
    char ch1;
    char ch2;
    T temp;
    vector<T> v_temp;
    is >> ch1;
    if (!is) return is;
    if (ch1!='{') {
        is.clear(ios_base::failbit);
        return is;
    }
    while (cin>>temp>>ch2 && ch2==',') {
        v_temp.push_back(temp);
    }
    if (ch2!='}') {
        is.clear(ios_base::failbit);
        return is;
    }
    v_temp.push_back(temp); // ch2=='}', utolsó érték olvasása

    // temp vector másolása csak, így d nem változik, ha a bemenet rossz
    d = v_temp;
}

// -----------------------------------------------------------------------------

int main()
try {
    // 3. feladat
    S<int> s_int(27);
    S<char> s_char('z');
    S<double> s_dbl(3.14);
    S<string> s_strg("Zotya");
    vector<int> vi;
    vi.push_back(1);
    vi.push_back(2);
    vi.push_back(3);
    S< vector<int> > s_v_int(vi);

    // 4. feladat - értékek kiíratása
//    cout << "s_int: " << s_int.val << "\n";
//    cout << "s_char: " << s_char.val << "\n";
//    cout << "s_dbl: " << s_dbl.val << "\n";
//    cout << "s_strg: " << s_strg.val << "\n";
//    for (int i = 0; i<s_v_int.val.size(); ++i)
//        cout << "s_v_int[" << i << "]: " << s_v_int.val[i] << "\n";

    // 8. feladat - kiíratás gettel
    cout << "s_int: " << s_int.get() << "\n";
    cout << "s_char: " << s_char.get() << "\n";
    cout << "s_dbl: " << s_dbl.get() << "\n";
    cout << "s_strg: " << s_strg.get() << "\n";
    for (int i = 0; i<s_v_int.get().size(); ++i)
        cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << "\n";
    cout << s_v_int.get() << "\n";

    // 9. feladat
    s_int.set(55);
    s_char.set('y');
    s_dbl.set(4.14);
    s_strg.set("String2");
    vi[1] = 22;
    s_v_int.set(vi);
    cout << "\ns_int: " << s_int.get() << "\n";
    cout << "s_char: " << s_char.get() << "\n";
    cout << "s_dbl: " << s_dbl.get() << "\n";
    cout << "s_strg: " << s_strg.get() << "\n";
    for (int i = 0; i<s_v_int.get().size(); ++i)
        cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << "\n";
    cout << s_v_int.get() << "\n";

    // 10. feladat
    s_int = 66;
    s_char = 'z';
    s_dbl = 5.14;
    s_strg = "String3";
    vi[1] = 33;
    s_v_int = vi;
    cout << "\ns_int: " << s_int.get() << "\n";
    cout << "s_char: " << s_char.get() << "\n";
    cout << "s_dbl: " << s_dbl.get() << "\n";
    cout << "s_strg: " << s_strg.get() << "\n";
    for (int i = 0; i<s_v_int.get().size(); ++i)
        cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << "\n";
    cout << s_v_int.get() << "\n";

    // 11. feladat - get() const és non-cost verziói
    const S<int> c_s_int(5);
    cout << "\nc_s_int: " << c_s_int.get() << "\n"; // const gettert igényel

    // 13. feladat - beolvasás a változóba
    cout << "\ns_int: ";
    read_val(s_int);
    cout << "s_char: ";
    read_val(s_char);
    cout << "s_dbl: ";
    read_val(s_dbl);
    cout << "s_strg: ";
    read_val(s_strg);
    cout << "\ns_int: " << s_int.get() << "\n";
    cout << "s_char: " << s_char.get() << "\n";
    cout << "s_dbl: " << s_dbl.get() << "\n";
    cout << "s_strg: " << s_strg.get() << "\n\n";

    // Drill 14
    cout << "\ns_v_int: ";
    read_val(s_v_int);
    cout << "\ns_v_int: " << s_v_int.get() << "\n";

}
catch (exception& e) {
    cerr << "Exception: " << e.what() << "\n";
}
catch (...) {
    cerr << "Exception\n";
}