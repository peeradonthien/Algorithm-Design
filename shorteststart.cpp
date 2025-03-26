#include <iostream>
#include <vector>
#include <set>
using namespace std;
// vector<int> dijkstra(vector<vector<int>> &adj, vector<vector<int>> &w , int start , int n, int v){
//     vector<int> dist(n);
//     vector<int> prev(n);
//     for(int i=0;i<n;i++){
//         dist[i] = 1e9;
//         prev[i] = -1;
//     }
//     set<pair<int,int>> s;
//     s.insert({0,start});
//     while(!s.empty()){
//         pair<int,int> b = *s.begin();
//         int T = b.first;
//         int u = b.second;
//         if(u == v) break;
//         for(auto &v : adj[u]){
//             if(dist[v] > T + w[u][v]){
//                 if(s.find({dist[v],v}) != s.end()) s.erase({dist[v],v});
//                 dist[v] = T + w[u][v];
//                 prev[v] = u;
//                 s.insert({dist[v],v});
//             }
//         }
//     }
//     return dist;
// }
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,k,v;
    cin >> n >> m >> k;
    cin >> v;
    vector<int> start(k);
    vector<vector<int>> adj(n);
    for(int i =0;i<k;i++){
        cin >> start[i];
    }
    vector<vector<int>> w(n,vector<int>(n));
    int v1,v2,ww;
    for(int i =0;i<m;i++){
        cin >> v1 >> v2 >> ww;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        w[v1][v2] = ww;
        w[v2][v1] = ww;
    }

    vector<int> dist(n,1e9);
    vector<int> prev(n);
    dist[v] = 0;
    for(int i=0;i<n;i++){
        dist[i] = 1e9;
        prev[i] = -1;
    }
    set<pair<int,int>> s;
    s.insert({0,v});
    while(!s.empty()){
        pair<int,int> b = *s.begin();
        int T = b.first;
        int u = b.second;
        if(u == v) break;
        for(auto &v : adj[u]){
            if(dist[v] > T + w[u][v]){
                if(s.find({dist[v],v}) != s.end()) s.erase({dist[v],v});
                dist[v] = T + w[u][v];
                prev[v] = u;
                s.insert({dist[v],v});
            }
        }
    }
}