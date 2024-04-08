#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
template <typename T>
class Heaps
{
private:
    void operator=(const Heaps &){};
    Heaps(const Heaps &){};
    vector<T> arr;
    int size;
    void reheapUp(int position);
    void reheapDown(int position);
    void buildHeap();

public:
    Heaps(int n);
    ~Heaps();
    void insert(T item);
    T remove();
    void print();
};

template <typename T>
Heaps<T>::Heaps(int n)
{
    arr.resize(n);
    size = 0;
}
template <typename T>
Heaps<T>::~Heaps()
{
    arr.clear();
}
template <typename T>
void Heaps<T>::insert(T item)
{
    arr[size] = item;
    reheapUp(size);
    size++;
}

template <typename T>
void Heaps<T>::reheapUp(int position)
{
    int parent = (position - 1) / 2;
    while (position > 0 && arr[position] > arr[parent])
    {
        swap(arr[position], arr[parent]);
        position = parent;
        parent = (position - 1) / 2;
    }
}

template <typename T>
void Heaps<T>::reheapDown(int position)
{
    int child = 2 * position + 1;
    while (child < size)
    {
        if (child < size - 1 && arr[child] < arr[child + 1])
        {
            child++;
        }
        if (arr[position] >= arr[child])
        {
            break;
        }
        swap(arr[position], arr[child]);
        position = child;
        child = 2 * position + 1;
    }
}

template <typename T>
void Heaps<T>::buildHeap()
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        reheapDown(i);
    }
}

template <typename T>
T Heaps<T>::remove()
{
    T temp = arr[0];
    arr[0] = arr[size - 1];
    size--;
    reheapDown(0);
    return temp;
}
