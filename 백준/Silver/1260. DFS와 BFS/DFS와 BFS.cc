#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

//--------------------------------------------------------------------
class Graph
{
public:
    Graph(int node);
    void addEdge(int a, int b);
    void printAdjList();
    void BFS(int start);
    void DFS(int start);
    void sortAdjList();

private:
    int node;
    vector<vector<int>> adjList; 
};

Graph::Graph(int node)
{
    this->node = node;
    adjList.resize(node);
}

void Graph::addEdge(int from, int to)
{
    adjList[from].push_back(to);
    // 유향 그래프일 경우 삭제
    adjList[to].push_back(from);
}

void Graph::printAdjList()
{
    for (int i = 0; i < node; i++)
    {
        cout << "adjList[" << i << "]: ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] << " ";
        }
        cout << "\n";
    }
}

void Graph::DFS(int start)
{
    vector<bool> visited(node, false);
    stack<int> stack;

    stack.push(start);

    while (!stack.empty())
    {
        int current = stack.top();
        stack.pop();

        if (!visited[current])
        {
            visited[current] = true;
            cout << current + 1 << " ";

            for (int i = adjList[current].size() - 1; i >= 0; i--)
            {
                stack.push(adjList[current][i]);
            }
        }
    }
}

void Graph::BFS(int start)
{
    vector<bool> visited(node, false);
    queue<int> queue;

    queue.push(start);

    while (!queue.empty())
    {
        int current = queue.front();
        queue.pop();

        if (!visited[current])
        {
            visited[current] = true;
            cout << current + 1 << " ";

            for (int i = 0; i < adjList[current].size(); i++)
            {
                queue.push(adjList[current][i]);
            }
        }
    }
}

void Graph::sortAdjList()
{
    for (int i = 0; i < node; i++)
    {
        sort(adjList[i].begin(), adjList[i].end());
    }
}

//--------------------------------------------------------------------

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M, V;
    cin >> N >> M >> V;

    Graph Graph(N);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        Graph.addEdge(a - 1, b - 1);
    }
    Graph.sortAdjList();
    Graph.DFS(V - 1);
    cout << "\n";
    Graph.BFS(V - 1);

    return 0;
}