#include "main.hpp"

typedef struct point
{
    vector<double> coord;
    int dim;
    point(int d) : dim(d)
    {
        coord.resize(dim);
    }
    ~point()
    {
        coord.clear();
    }
    double operator[](int i)
    {
        return coord[i];
    }
    double distance(point p)
    {
        double sum = 0;
        for (int i = 0; i < dim; i++)
        {
            sum += pow(coord[i] - p[i], 2);
        }
        return sqrt(sum);
    }

    bool operator==(point p)
    {
        for (int i = 0; i < dim; i++)
        {
            if (coord[i] != p[i])
            {
                return false;
            }
        }
        return true;
    }
    bool operator!=(point p)
    {
        return !(*this == p);
    }

} point;

class kd
{
private:
    class Node
    {
    public:
        point data;
        Node *left;
        Node *right;
        Node(point p) : data(p), left(nullptr), right(nullptr) {}
    };
    Node *root;
    int size;
};