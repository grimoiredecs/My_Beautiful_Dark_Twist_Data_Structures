#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <memory>

using namespace std;

typedef struct block
{
    int *arr;
    int size;
    block(int n) : size(n)
    {
        arr = new int[n];
    }
    ~block()
    {
        delete[] arr;
    }
} block;

int main()
{
    shared_ptr<block> p1;
    shared_ptr<block> p2 = p1;
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;

    return 0;
}