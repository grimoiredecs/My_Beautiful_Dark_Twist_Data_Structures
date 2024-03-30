#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

static const int balanced = 1;
enum BalanceFactor
{
    LH = 1,
    RH = -1,
    EH = 0
};

template<typename T>
class AVL
{
    private:
    class Node
    {
        public:
        T data;
        std::string key;
        Node *left;
        Node *right;
        BalanceFactor balance;
        Node(T da, std::string ke)
        {
            data = da;
            key = ke;
            left = nullptr;
            right = nullptr;
            balance = EH;
        }
        Node()
        {
            left=right=nullptr;
            balance = EH;
        }
        ~Node()
        {
            delete left;
            delete right;
        }
    

    };
    Node<T>* root;
    int size;
    int height;
    public:
    AVL()
    {
        root = nullptr;
        height = 0;
        size=0;
    }
    ~AVL()
    {
       
    }
    

    void balance(Node*& root)
    {
        if (root == nullptr)
        {
            return;
        }
    }

};