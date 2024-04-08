#include <iostream>
#include <string>
#include <vector>
#include <queue>

typedef struct
{
    std::string id;
    /* data */
} key;

template <typename T>
class SplayTree
{
private:
    class Node
    {
    public:
        key key;
        T data;
        Node *left;
        Node *right;
        Node *parent;
    };
    Node *root;
    int size;
    int height;
    void printBinaryTree(string prefix, const Node *root, bool isLeft, bool hasRightSibling)
    {
        if (!root && isLeft && hasRightSibling)
        {
            cout << prefix << "├──\n";
        }
        if (!root)
            return;
        cout << prefix;
        if (isLeft && hasRightSibling)
            cout << "├──";
        else
            cout << "└──";
        cout << root->val << '\n';
        printBinaryTree(prefix + (isLeft && hasRightSibling ? "|  " : "   "), root->pLeft, true, root->pRight);
        printBinaryTree(prefix + (isLeft && hasRightSibling ? "|  " : "   "), root->pRight, false, root->pRight);
    }
    void printPreorder(Node *p)
    {
        if (!p)
        {
            return;
        }
        cout << p->val << ' ';
        printPreorder(p->pLeft);
        printPreorder(p->pRight);
    }

public:
    SplayTree()
    {
        root = nullptr;
    }
    ~SplayTree()
    {
        Node *p = root;
        if (p)
        {
            queue<Node *> q;
            q.push(p);
            while (!q.empty())
            {
                p = q.front();
                q.pop();
                if (p->pLeft)
                {
                    q.push(p->pLeft);
                }
                if (p->pRight)
                {
                    q.push(p->pRight);
                }
                delete p;
            }
        }
    }

    void printBinaryTree()
    {
        printBinaryTree("", root, false, false);
    }

    void printPreorder()
    {
        printPreorder(root);
        cout << "\n";
    }

    void splay(Node *p)
    {
        // To Do
    }

    void insert(int val)
    {
        // To Do
    }
};