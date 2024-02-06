// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> v;
        bool visited[10005];
        memset(visited, false, sizeof(visited));
        
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        while (!q.empty())
        {
            int parent = q.front();
            q.pop();
            v.push_back(parent);
            
            for (int child : adj[parent])
            {
                if (!visited[child])
                {
                    q.push(child);
                    visited[child] = true;
                }
            }
        }
        return v;
    }
};