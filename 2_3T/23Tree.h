#include <iostream>
#include <vector>
#include <queue>
#include <string>


typedef struct 
{
    std::string id;

}   Key;

template<typename T>
class TTTree
{
    private:
    //may be preferrable to use composition here!
    
    class TTNode<T>
    {
        public:
        T data;
        Key key;
        TTNode<T> *left;
        TTNode<T> *middle;
        TTNode<T> *right;

        TTNode(T da, Key ke)
        {
            data = da;
            key = ke;
            left = nullptr;
            middle = nullptr;
            right = nullptr;
        }
        TTNode()
        {
            left=right=middle=nullptr;
            data = NULL;
        }

        ~TTNode()
        {
            delete left;
            delete middle;
            delete right;
        }
        bool isLeaf(){return left==nullptr && middle==nullptr && right==nullptr;}

    };
    int size;
    TTNode<T> *root;
    int height;
    public:
    TTTree()
    {
        root = nullptr;
        height = 0;
    }
    T findkey(Key key)
    {
        TTNode<T> *current = root;
        while(current!=nullptr)
        {
            if(current->key.id == key.id)
            {
                return current->data;
            }
            else if(key.id < current->key.id)
            {
                current = current->left;
            }
            else if(key.id > current->key.id)
            {
                current = current->right;
            }
        }
        return NULL;
    }

    T findData(T &data)
    {
        TTNode<T> *current = root;
        while(current!=nullptr)
        {
            if(current->data == data)
            {
                return current->data;
            }
            else if(data < current->data)
            {
                current = current->left;
            }
            else if(data > current->data)
            {
                current = current->right;
            }
        }
        return NULL;
    }

    TTNode* insertRec(T Data, TTNode<T>* &current)
    {
        if(current == nullptr)
        {
            current = new TTNode<T>(Data);
            return current;
        }
        if(current->isLeaf())
        {
            if(current->data < Data)
            {
                current->right = new TTNode<T>(Data);
            }
            else if(current->data > Data)
            {
                current->left = new TTNode<T>(Data);
            }
            else
            {
                current->middle = new TTNode<T>(Data);
            }
            return current;
        }
        if(current->data < Data)
        {
            insertRec(Data, current->right);
        }
        else if(current->data > Data)
        {
            insertRec(Data, current->left);
        }
        else
        {
            insertRec(Data, current->middle);
        }
        return current;
    }
    void insert(T data)
    {
        root = insertRec(data, root);

    }


};


int main()
{

}