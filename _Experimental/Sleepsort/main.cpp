#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

void print()
{
    std::cout << "Hello World" << std::endl;
}

void another()
{
    std::cout << "Another Hello World" << std::endl;
}

int main()
{
    std::vector<int> elements;

    elements.push_back(5);
    elements.push_back(3);
    elements.push_back(2);
    elements.push_back(8);
    print();

        // sleepSortMain(elements);

    return 0;
}