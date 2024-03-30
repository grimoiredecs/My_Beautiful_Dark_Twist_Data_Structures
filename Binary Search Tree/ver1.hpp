#include <iostream>
#include <string>
#include <queue>
using namespace std;

template<typename T>
class BST
{
    private:
    class BSTNode
    {
        public:
        T data;
        std::string key;
        BSTNode *left;
        BSTNode *right;
        BSTNode(T da, std::string ke)
        {
            data = da;
            key = ke;
            left = nullptr;
            right = nullptr;
        }
        BSTNode()
        {
            left=right=nullptr;
        }
        ~BSTNode()
        {
            delete left;
            delete right;
        }
    };

    BSTNode *root;
    int size;
    int height;
    public:
    BST()
    {
        root = nullptr;
        height = 0;
    }
    T finddataRec(std::string key, BSTNode *p)
    {
        if(p==nullptr)
            return T();
        if(p->key == key)
            return p->data;
        if(p->key > key)
            return finddataRec(key, p->left);
        return finddataRec(key, p->right);
    }
    T finddata(std::string key)
    {
        return finddataRec(key, root);
    }
    T findkeyRec(T data, BSTNode *p)
    {
        if(p==nullptr)
            return T();
        if(p->data == data)
            return p->key;
        if(p->data > data)
            return findkeyRec(data, p->left);
        return findkeyRec(data, p->right);
    }
    std::string findkey(T data)
    {
        return findkeyRec(data, root);
    }

    void insertRec(T& data, std::string &key, BSTNode* &p)
    {
        if(p->key == key)
            return;
        if(p->key > key)
        {
            if(p->left == nullptr)
            {
                p->left = new BSTNode(data, key);
                return;
            }
            insertRec(data, key, p->left);
        }
        else
        {
            if(p->right == nullptr)
            {
                p->right = new BSTNode(data, key);
                return;
            }
            insertRec(data, key, p->right);
        }
        
    }
    void insert(T data, std::string key)
    {
        if(root == nullptr)
        {
            root = new BSTNode(data, key);
            return;
        }
        insertRec(data, key, root);
    }
    bool contains(Node* &root, T data)
    {
        if(root == nullptr)
            return false;
        else if ( root->data == data)
        {
            return true;
        }
        else if (root->data > data)
        {
            return contains(root->left, data);
        }
        else
        {
            return contains(root->right, data);
        }
    }
    void successor(Node* root)
    {
        Node* current = root;
        while(current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }
    void removeRec(T data, Node* &root)
    {

        if(root == nullptr)
            return;
        if(root->data > data)
        {
            removeRec(data, root->left);
        }
        else if(root->data < data)
        {
            removeRec(data, root->right);
        }
        else
        {
            if(root->left == nullptr && root->right == nullptr)
            {
                delete root;
                root = nullptr;
            }
            else if(root->left == nullptr)
            {
                Node* temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right == nullptr)
            {
                Node* temp = root;
                root = root->left;
                delete temp;
            }
            else
            {
                Node* temp = successor(root->right);
                root->data = temp->data;
                removeRec(temp->data, root->right);
            }
        }
    }

    void remove(T data)
    {
        removeRec(data, root);
    }
    void printInOrderRec(Node* root)
    {
        if(root == nullptr)
            return;
        printInOrderRec(root->left);
        std::cout << root->data << " ";
        printInOrderRec(root->right);
    }
    void printInOrder()
    {
        printInOrderRec(root);
    }
    void printPreOrderRec(Node* root)
    {
        if(root == nullptr)
            return;
        std::cout << root->data << " ";
        printPreOrderRec(root->left);
        printPreOrderRec(root->right);
    }
    void printPreOrder()
    {
        printPreOrderRec(root);
    }

    void printPostOrderRec(Node* root)
    {
        if(root == nullptr)
            return;
        printPostOrderRec(root->left);
        printPostOrderRec(root->right);
        std::cout << root->data << " ";
    }
    void printPostOrder()
    {
        printPostOrderRec(root);
    }
    void printLevelOrder()
    {
        if(root == nullptr)
            return;
        std::queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* current = q.front();
            q.pop();
            std::cout << current->data << " ";
            if(current->left != nullptr)
                q.push(current->left);
            if(current->right != nullptr)
                q.push(current->right);
        }
    }

    void clearRec(Node* &root)
    {
        if(root == nullptr)
            return;
        clearRec(root->left);
        clearRec(root->right);
        delete root;
        root = nullptr;
    }
    void clear()
    {
        clearRec(root);
    }


    T getMin()
    {
        auto getMinRec = [](Node* &root)-> T
        {
            if(root->left == nullptr)
                return root->data;
            return getMinRec(root->left);
        };
        return getMinRec(this->root);
    }
    inline T getMaxRec(Node*& root)
    {
        if(root->right == nullptr)
            return root->data;
        return getMaxRec(root->right);
    }
    T getMax()
    {
        return getMaxRec(root);
    }

    bool find(T i)
    {
        return contains(root, i);
    }
    T sum (T l, T r)
    {
        auto sumRec = [](Node* &root, T l, T r)-> T
        {
            if(root == nullptr)
                return 0;
            if (root->data < l && root->data > r)
                return root->data + sumRec(root->left, l, r) + sumRec(root->right, l, r);
            if(root->data < l)
                return sumRec(root->right, l, r);
            if(root->data > r)
                return sumRec(root->left, l, r);
            return sumRec(root->left, l, r) + sumRec(root->right, l, r);
        };
        return sumRec(root, l, r);
    }
    ~BST()
    {
        clear();
    }

    
};