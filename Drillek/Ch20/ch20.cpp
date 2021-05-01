#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <array>
#include <string>
#include <algorithm>

using namespace std;


template<typename T>
void print(T& t)
{
    for (auto& a : t)
        cout << a <<" ";
    cout << endl;
}

template<typename T>
void increment(T& t, int n)
{
    for(auto& a : t)
        a += n;
}

//6
template<typename Iter1, typename Iter2>
Iter2 my_copy (Iter1 f1, Iter1 e1, Iter2 f2)
{
    for(Iter1 p = f1; p != e1; ++p)
    {   
        *f2 = *p;
        ++f2;
    }
    
    return f2;
}

int main()
try{    
    //1-4
    const int size = 10;

    int ten[size];
    for (int i = 0; i < size; ++i)
    {
        ten[i] = i;
    }
    
    array<int, size> a;
    copy(ten, ten+size, a.begin());

    cout << "Array: ";
    print(a);

    vector<int> v(size);
    copy(ten, ten+size, v.begin());
    cout << "Vector: ";
    print(v);

    list<int> l(size);
    copy(ten, ten+size, l.begin());
    cout << "List: ";
    print(l);

    int a2[size];
    for (int i = 0; i < size; ++i)
    {
        a2[i] = a[i];
    }
    cout <<"\nArray copy: ";
    print(a2);

    vector<int> v2;
    v2 = v;
    cout << "Vector copy: ";
    print(v2);

    list<int> l2;
    l2 = l;
    cout << "List copy: ";
    print(l2);

    //5
    increment(a, 2);
    increment(v, 3);
    increment(l, 5);

    
    cout << "\nArray incremented (by 2): ";
    print(a);
    cout << "Vector incremented (by 3): ";
    print(v);
    cout << "List incremented (by 5): ";
    print(l);


    //7
    my_copy(a.begin(), a.end(), v.begin());
    my_copy(l.begin(), l.end(), a.begin());
    cout << "\nArray after copying to list: ";
    print(a);
    cout << "Vector after copying to array: ";
    print(v);
    cout << "List after copying: ";
    print(l);
    cout << endl;

    //8
    cout << "Finding the number 3 in the vector: ";
    auto p = find(v.begin(), v.end(), 3);
    if(p!=v.end()) cout << "The number has the index of : " << p-v.begin() << endl;
    else
        cout << "Number not found!" << endl;

    cout << "Finding the number 27 in the list: ";
    auto q = find(l.begin(), l.end(), 27);
    if(q!=l.end()) cout << "The number has the index of : " << distance(l.begin(), q) << endl;
    else
        cout << "Number not found!" << endl;

    return 0;

}catch(exception& e){
    cerr << "Exception: " << e.what() << endl;
    return 1;
}catch(...){
    cerr << "Unknown exception\n";
    return 2;
}