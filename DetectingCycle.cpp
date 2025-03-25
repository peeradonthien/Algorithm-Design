#include <iostream>
#include <vector>
using namespace std;
bool dfs(int a , vector<bool> &visited , int parent , vector<vector<int>> &adj){
    visited[a] = true;
    for(int &x : adj[a]){
        if(!visited[x]){
            if(dfs(x,visited,a,adj)){
                return true;
            }
        }
        else if(x != parent){
            return true;
        }
    }
    return false;
}
bool cycle(int n , vector<vector<int>> &adj){
    vector<bool> visited (n,false);
    for(int i =0;i<n;i++){
        if(!visited[i]){
            if(dfs(i,visited,-1 , adj)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int t;
    cin >> t;
    int n,e;
    for(int i = 0;i<t;i++){
        cin >> n >> e;
        if(e == 0){
            cout << "NO" << endl;
            continue;
        }
        vector<vector<int>> adj(n);
        int v1,v2;
        for(int j =0;j<e;j++){
            cin >> v1 >> v2;
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
        if(cycle(n,adj)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    
}