#include <iostream>
#include <vector>
using namespace std;
int cc_num = 0;
void dfs (int a , vector<vector<int>> &adj, vector<int> &visited){
    visited[a] = cc_num;
    for(int &x : adj[a]){
        if(visited[x] == 0){
            dfs(x,adj,visited);
        }
    }
}
int main(){
    int v,e;
    cin >> v >> e;
    vector<vector<int>> adj(v+1);
    if(e == 0){
        cout << v << endl;
        return 0;
    }
    int v1,v2;
    for(int i =0;i<e;i++){
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    vector<int> visited(v+1,0);
    for(int i = 1;i<= v;i++){
        if(visited[i] == 0){
            cc_num +=1;
            dfs(i,adj,visited);
        }
    }
    cout << cc_num << endl;
}