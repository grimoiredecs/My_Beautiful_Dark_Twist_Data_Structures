#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Node
{
public:
    char data;
    bool isEnd;
    vector<Node *> children;
    Node(char c) : data(c), isEnd(false)
    {
        children.resize(26, nullptr);
    }
};

class tries
{
private:
    Node *root;
    void insert(Node *root, string key);
    bool search(Node *root, string key);
    void remove(Node *root, string key);
    void print(Node *root, string key);

public:
    tries();
    ~tries();
    void insert(string key);
    bool search(string key);
    void remove(string key);
    void print();
};

tries::tries()
{
    root = new Node(' ');
}
