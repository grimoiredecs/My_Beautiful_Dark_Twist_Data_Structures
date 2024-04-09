#include <iostream>

using namespace std;

template <typename A, typename B>
class tuple
{
private:
    const A a;
    const B b;
    () : a(), b() {}

public:
    tuple(A a, B b) : a(a), b(b) {}
};