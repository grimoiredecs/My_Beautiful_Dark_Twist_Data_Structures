#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>
using namespace std;

typedef struct Edge
{
    int vertex;
    int weight;
} Edge;

class Graphl
{
private:
    list<Edge> *edges;
    int numVertex;
    int numEdge;
    vector<bool> mark;

public:
    Graphl(int num)
    {
        Init(num);
    }

    void Init(int n)
    {
        numVertex = n;
        numEdge = 0;
        edges = new list<Edge>[numVertex];
        mark.resize(numVertex);
    }
    ~Graphl()
    {
        delete[] edges;
    }
    int n() const
    {
        return numVertex;
    }
    int e() const
    {
        return numEdge;
    }
    int first(int v)
    {
        if (edges[v].empty())
            return numVertex;
        return edges[v].front().vertex;
    }
    int next(int v, int w)
    {
        for (auto it = edges[v].begin(); it != edges[v].end(); it++)
        {
            if (it->vertex == w)
            {
                it++;
                if (it == edges[v].end())
                    return numVertex;
                return it->vertex;
            }
        }
        return numVertex;
    }
    void setEdge(int v1, int v2, int wt)
    {
        Edge edge;
        edge.vertex = v2;
        edge.weight = wt;
        edges[v1].push_back(edge);
        numEdge++;
    }
    void delEdge(int v1, int v2)
    {
        for (auto it = edges[v1].begin(); it != edges[v1].end(); it++)
        {
            if (it->vertex == v2)
            {
                edges[v1].erase(it);
                numEdge--;
                return;
            }
        }
    }

    bool isEdge(int v1, int v2)
    {
        for (auto it = edges[v1].begin(); it != edges[v1].end(); it++)
        {
            if (it->vertex == v2)
                return true;
        }
        return false;
    }
    int weight(int v1, int v2)
    {
        for (auto it = edges[v1].begin(); it != edges[v1].end(); it++)
        {
            if (it->vertex == v2)
                return it->weight;
        }
        return 0;
    }
    int getMark(int v)
    {
        return mark[v];
    }
    void setMark(int v, int val)
    {
        mark[v] = val;
    }
    void print()
    {
        for (int i = 0; i < numVertex; i++)
        {
            cout << i << " : ";
            for (auto it = edges[i].begin(); it != edges[i].end(); it++)
            {
                cout << it->vertex << " ";
            }
            cout << endl;
        }
    }

    void bfs(int start)
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
                if (!mark[w])
                {
                    q.push(w);
                    mark[w] = 1;
                }
            }
        }
        cout << endl;
    }

    void dfs(int start)
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
                if (!mark[w])
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
        cout << endl;
    }
    void clearMarks()
    {
        fill(mark.begin(), mark.end(), 0);
    }
    void kruskal()
    {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < numVertex; i++)
        {
            for (auto it = this->edges[i].begin(); it != this->edges[i].end(); it++)
            {
                edges.push_back({it->weight, {i, it->vertex}});
            }
        }
        sort(edges.begin(), edges.end());
        vector<int> parent(numVertex);
        for (int i = 0; i < numVertex; i++)
        {
            parent[i] = i;
        }
        int cost = 0;
        for (int i = 0; i < edges.size(); i++)
        {
            int v1 = edges[i].second.first;
            int v2 = edges[i].second.second;
            int w = edges[i].first;
            if (parent[v1] != parent[v2])
            {
                cost += w;
                int oldParent = parent[v2];
                for (int j = 0; j < numVertex; j++)
                {
                    if (parent[j] == oldParent)
                    {
                        parent[j] = parent[v1];
                    }
                }
            }
        }
        cout << "Cost of MST: " << cost << endl;
    }

    void dijkstra(int start)
    {
        vector<int> dist(numVertex, INT_MAX);
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            for (auto it = edges[u].begin(); it != edges[u].end(); it++)
            {
                int v = it->vertex;
                int weight = it->weight;
                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        for (int i = 0; i < numVertex; i++)
        {
            cout << "Distance from " << start << " to " << i << " is " << dist[i] << endl;
        }
    }

    void bellman(int start)
    {
        vector<int> dist(numVertex, INT_MAX);
        dist[start] = 0;
        for (int i = 0; i < numVertex - 1; i++)
        {
            for (int j = 0; j < numVertex; j++)
            {
                for (auto it = edges[j].begin(); it != edges[j].end(); it++)
                {
                    int v = it->vertex;
                    int weight = it->weight;
                    if (dist[v] > dist[j] + weight)
                    {
                        dist[v] = dist[j] + weight;
                    }
                }
            }
        }
        for (int j = 0; j < numVertex; j++)
        {
            for (auto it = edges[j].begin(); it != edges[j].end(); it++)
            {
                int v = it->vertex;
                int weight = it->weight;
                if (dist[v] > dist[j] + weight)
                {
                    cout << "Negative cycle detected" << endl;
                    return;
                }
            }
        }
        for (int i = 0; i < numVertex; i++)
        {
            cout << "Distance from " << start << " to " << i << " is " << dist[i] << endl;
        }
    }

    void floyd()
    {
        vector<vector<int>> dist(numVertex, vector<int>(numVertex, INT_MAX));
        for (int i = 0; i < numVertex; i++)
        {
            dist[i][i] = 0;
            for (auto it = edges[i].begin(); it != edges[i].end(); it++)
            {
                dist[i][it->vertex] = it->weight;
            }
        }
        for (int k = 0; k < numVertex; k++)
        {
            for (int i = 0; i < numVertex; i++)
            {
                for (int j = 0; j < numVertex; j++)
                {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        for (int i = 0; i < numVertex; i++)
        {
            for (int j = 0; j < numVertex; j++)
            {
                cout << "Distance from " << i << " to " << j << " is " << dist[i][j] << endl;
            }
        }
    }
    void prim()
    {
        vector<int> parent(numVertex, -1);
        vector<int> key(numVertex, INT_MAX);
        vector<bool> mstSet(numVertex, false);
        key[0] = 0;
        for (int i = 0; i < numVertex - 1; i++)
        {
            int u = -1;
            for (int j = 0; j < numVertex; j++)
            {
                if (!mstSet[j] && (u == -1 || key[j] < key[u]))
                {
                    u = j;
                }
            }
            mstSet[u] = true;
            for (auto it = edges[u].begin(); it != edges[u].end(); it++)
            {
                int v = it->vertex;
                int weight = it->weight;
                if (!mstSet[v] && weight < key[v])
                {
                    parent[v] = u;
                    key[v] = weight;
                }
            }
        }
        for (int i = 1; i < numVertex; i++)
        {
            cout << parent[i] << " - " << i << " : " << key[i] << endl;
        }
    }

    void topologicalSort()
    {
        vector<int> inDegree(numVertex, 0);
        for (int i = 0; i < numVertex; i++)
        {
            for (auto it = edges[i].begin(); it != edges[i].end(); it++)
            {
                inDegree[it->vertex]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < numVertex; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        int count = 0;
        vector<int> topOrder;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            topOrder.push_back(u);
            for (auto it = edges[u].begin(); it != edges[u].end(); it++)
            {
                if (--inDegree[it->vertex] == 0)
                {
                    q.push(it->vertex);
                }
            }
            count++;
        }
        if (count != numVertex)
        {
            cout << "Graph contains cycle" << endl;
            return;
        }
        for (int i = 0; i < topOrder.size(); i++)
        {
            cout << topOrder[i] << " ";
        }
        cout << endl;
    }

    bool bipartite()
    {
        vector<int> color(numVertex, -1);
        queue<int> q;
        for (int i = 0; i < numVertex; i++)
        {
            if (color[i] == -1)
            {
                color[i] = 1;
                q.push(i);
                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    for (auto it = edges[u].begin(); it != edges[u].end(); it++)
                    {
                        if (color[it->vertex] == -1)
                        {
                            color[it->vertex] = 1 - color[u];
                            q.push(it->vertex);
                        }
                        else if (color[it->vertex] == color[u])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    bool isCyclic(int v, vector<bool> &visited, int parent)
    {
        visited[v] = true;
        for (auto it = edges[v].begin(); it != edges[v].end(); it++)
        {
            if (!visited[it->vertex])
            {
                if (isCyclic(it->vertex, visited, v))
                    return true;
            }
            else if (it->vertex != parent)
                return true;
        }
        return false;
    }

    bool ford(int start)
    {
        vector<int> dist(numVertex, INT_MAX);
        dist[start] = 0;
        for (int i = 0; i < numVertex - 1; i++)
        {
            for (int j = 0; j < numVertex; j++)
            {
                for (auto it = edges[j].begin(); it != edges[j].end(); it++)
                {
                    int v = it->vertex;
                    int weight = it->weight;
                    if (dist[v] > dist[j] + weight)
                    {
                        dist[v] = dist[j] + weight;
                    }
                }
            }
        }
        for (int j = 0; j < numVertex; j++)
        {
            for (auto it = edges[j].begin(); it != edges[j].end(); it++)
            {
                int v = it->vertex;
                int weight = it->weight;
                if (dist[v] > dist[j] + weight)
                {
                    return true;
                }
            }
        }
        return false;
    }
};