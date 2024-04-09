#include <vector>
#include <queue>
#include <string>
#include <list>
#include <unordered_map>
#include <iostream>

using namespace std;

typedef struct Less
{
    bool operator()(int a, int b)
    {
        return a < b;
    }
} Less;

typedef struct Greater
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
} Greater;

template <typename T, typename Compare>
class Sorting
{
private:
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

public:
    void bubbleSort(vector<T> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (Compare()(arr[j], arr[j + 1]))
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
    void bubbleSort(list<T> &lst)
    {
        int n = lst.size();
        for (int i = 0; i < n - 1; i++)
        {
            auto it = lst.begin();
            for (int j = 0; j < n - i - 1; j++)
            {
                auto it1 = it;
                it1++;
                if (Compare()(*it, *it1))
                {
                    swap(*it, *it1);
                }
                it++;
            }
        }
    }
};