#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int n,e,start;
    cin >> n >> e >> start;
    vector<vector<int>> w(n,vector<int>(n));
    vector<vector<int>> adj(n);
    int v1,v2,weight;
    for(int i=0;i<e;i++){
        cin >> v1 >> v2 >> weight;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        w[v1][v2] = weight;
        w[v2][v1] = weight;
    }
    vector<int> dist(n);
    vector<int> prev(n);
    for(int i=0;i<n;i++){
        dist[i] = 1e9;
        prev[i] = -1;
    }
    set<pair<int,int>> s;
    s.insert(make_pair(0,start));
    while(!s.empty()){
        pair<int,int> b = *s.begin();
        for(auto &x : adj[b.second]){
            if(dist[x] > b.first + w[b.second][x]){
                s.erase(make_pair(dist[x],x));
                dist[x] = b.first + w[b.second][x];
                prev[x] = b.second;
                s.insert(make_pair(dist[x],x));
            }
        }
    }
    for(auto &x : dist){
        cout << x << " ";
    }
    cout << endl;

}