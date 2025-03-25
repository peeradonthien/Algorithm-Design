#include <iostream>
#include <vector>
using namespace std;
int sum = 0;
vector<int> beauty,day;
void dfs(int a , vector<vector<int>> &adj , vector<bool> &visited){
    visited[a] = true;
    sum -= beauty[a];
    beauty[a] = 0;
    for(auto &x : adj[a]){
        if(!visited[x]){
            dfs(x,adj,visited);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    beauty.resize(n);
    for(int i =0;i<n;i++){
        cin >> beauty[i];
        sum += beauty[i];
    }
    day.resize(k);
    for(int i =0;i < k;i++){
        cin >> day[i];
    }
    vector<vector<int>> adj(n);
    int v1,v2;
    for(int i=0;i<m;i++){
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
    }
    vector<bool> visited(n,false);
    for(auto &x :day){
        if(!visited[x]){
            dfs(x,adj,visited);
        }
        cout << sum << " ";
    }
    cout << "\n";
}