#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Graph
{
private:
    void operator=(const Graph &){};
    Graph(const Graph &){};

public:
    Graph(){};
    virtual ~Graph(){};

    virtual void Init(int n) = 0;

    virtual int n() = 0;
    virtual int e() = 0;

    virtual int first(int v) = 0;
    virtual int next(int v, int w) = 0;
    virtual void setEdge(int v1, int v2, int wght) = 0;
    virtual void delEdge(int v1, int v2) = 0;
    virtual bool isEdge(int i, int j) = 0;

    virtual int weight(int v1, int v2) = 0;
    virtual int getMark(int v) = 0;
    virtual void setMark(int v, int val) = 0;

    virtual void bfs(int start) = 0;
    virtual void dfs(int start) = 0;

    void printPath(int start, int end, vector<int> &parent);
    virtual vector<int> dijkstra(int start) = 0;
    void prim(int start);
    void kruskal();
    void floyd();
    void topoSort();
    void criticalPath();
    void isBipartite();
    void eulerCircuit();
    void hamiltonianCycle();
    void tsp();
};

class Graphm : public Graph
{
private:
    vector<vector<int>> matrix;
    vector<int> mark;
    int numVertex;
    int numEdge;

public:
    Graphm(int n)
    {
        Init(n);
    }
    ~Graphm() override
    {
        for (int i = 0; i < numVertex; i++)
        {
            matrix[i].clear();
        }
        matrix.clear();
        mark.clear();
    }
    void Init(int n) override
    {
        numVertex = n;
        numEdge = 0;
        mark.resize(n);
        matrix.resize(n);
        for (int i = 0; i < n; i++)
        {
            matrix[i].resize(n);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = 0;
            }
        }
        mark.assign(n, 0);
    }
    int n() override
    {
        return numVertex;
    }
    int e() override
    {
        return numEdge;
    }
    int first(int v) override
    {
        for (int i = 0; i < numVertex; i++)
        {
            if (matrix[v][i] != 0)
            {
                return i;
            }
        }
        return numVertex;
    }
    int next(int v, int w) override
    {
        for (int i = w + 1; i < numVertex; i++)
        {
            if (matrix[v][i] != 0)
            {
                return i;
            }
        }
        return numVertex;
    }
    void setEdge(int v1, int v2, int wght) override
    {
        if (wght <= 0)
        {
            cout << "Illegal weight value" << endl;
            return;
        }
        if (matrix[v1][v2] == 0)
        {
            numEdge++;
        }
        matrix[v1][v2] = wght;
    }
    void delEdge(int v1, int v2) override
    {
        if (matrix[v1][v2] != 0)
        {
            numEdge--;
        }
        matrix[v1][v2] = 0;
    }
    bool isEdge(int i, int j) override
    {
        return (matrix[i][j] != 0);
    }
    int weight(int v1, int v2) override
    {
        return matrix[v1][v2];
    }
    int getMark(int v) override
    {
        return mark[v];
    }
    void setMark(int v, int val) override
    {
        mark[v] = val;
    }

    void bfs(int start) override
    {
        queue<int> q;
        q.push(start);
        mark[start] = 1;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            cout << v << " ";
            for (int w = first(v); w < numVertex; w = next(v, w))
            {
                if (mark[w] == 0)
                {
                    q.push(w);
                    mark[w] = 1;
                }
            }
        }
    }
    void dfs(int start) override
    {
        stack<int> s;
        s.push(start);
        mark[start] = 1;
        cout << start << " ";
        while (!s.empty())
        {
            int v = s.top();
            int w = first(v);
            while (w < numVertex)
            {
                if (mark[w] == 0)
                {
                    s.push(w);
                    mark[w] = 1;
                    cout << w << " ";
                    break;
                }
                w = next(v, w);
            }
            if (w == numVertex)
            {
                s.pop();
            }
        }
    }
};