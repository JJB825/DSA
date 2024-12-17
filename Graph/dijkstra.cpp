#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<int>> &edges, vector<int> &weights, int n, int start)
{
  vector<vector<pair<int, int>>> adjlist(n);
  for (int i = 0; i < edges.size(); i++)
  {
    int x = edges[i][0], y = edges[i][1], w = weights[i];
    adjlist[x].push_back({y, w});
    adjlist[y].push_back({x, w});
  }
  set<pair<int, int>> st;
  vector<int> dist(n, 1e9);
  st.insert({0, start});
  dist[start] = 0;
  while (!st.empty())
  {
    auto it = *(st.begin());
    int dis = it.first;
    int node = it.second;
    st.erase(it);
    for (auto it : adjlist[node])
    {
      int adjNode = it.first;
      int w = it.second;
      if (dis + w < dist[adjNode])
      {
        if (dist[adjNode] != 1e9)
          st.erase({dist[adjNode], adjNode});
        dist[adjNode] = dis + w;
        st.insert({dist[adjNode], adjNode});
      }
    }
  }
  return dist;
}
int main()
{
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
  vector<int> weights = {1, 1, 2};
  int n = 3, start = 0;
  vector<int> shortest_distances = dijkstra(edges, weights, n, start);
  for (int i = 0; i < n; i++)
    cout << i << ": " << shortest_distances[i] << endl;
  cout << endl;
  return 0;
}