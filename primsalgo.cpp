#include <bits/stdc++.h>
using namespace std;

#define V 5

int minKey(int key[], bool mstSet[])
{
    int min = 99999, min_index;
    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int MST[], int graph[V][V])
{
    int tW = 0;
    cout<<" Edge \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        cout<<(char)(MST[i]+65)<<" - "<<(char)(i+65)<<" \t  "<<graph[i][MST[i]]<<" \n";
        tW += graph[i][MST[i]];
    }
    cout<<"\nTotal Weight: "<<tW<<endl;
}

void primMST(int graph[V][V])
{
    int MST[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = 99999;
        mstSet[i] = false;
    }

    key[0] = 0;
    MST[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                MST[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(MST, graph);
}

int main()
{
    int graph[V][V] =
    {
        { 0, 9, 5, 2, 0 },
        { 9, 0, 0, 6, 5 },
        { 5, 0, 0, 4, 5 },
        { 2, 6, 4, 0, 4 },
        { 0, 5, 5, 4, 0 }
    };

    primMST(graph);

    return 0;
}
