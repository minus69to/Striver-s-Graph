#include <bits/stdc++.h>
using namespace std;

class Solution // O(n)
{
    void dfs(int node, vector<int> adjLs[], int vis[])
    {
        vis[node] = 1;
        for(auto it : adjLs[node])
        {
            if(!vis[it])
            {
                dfs(it, adjLs, vis);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        vector<int> adjLs[V];
        // Change matrix to list
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if(adj[i][j] == 1 && i != j)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        
        int vis[V] = {0};
        int count = 0;

        for (int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                count++; 
                dfs(i, adjLs, vis);
            }
        }
        
        return count;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, x;
        cin >> V;

        vector<vector<int>> adj;

        for (int i = 0; i < V; i++)
        {
            vector<int> temp;
            for (int j = 0; j < V; j++)
            {
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.numProvinces(adj, V) << endl;
    }
    return 0;
}