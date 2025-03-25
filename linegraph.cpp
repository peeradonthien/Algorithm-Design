#include <iostream>
#include <vector>
using namespace std;
bool dfs(int a , vector<vector<int>> & adj , vector<bool> &visited ,int parent){
    visited[a] = true;
    bool checkcycle = false;
    bool checkchild = false;
    for(auto &x : adj[a]){
        if(!visited[x]){
            if (!dfs(x, adj, visited, a)) {
                return false;
            }

        }
        else if(x != parent){
            checkcycle = true;
        }
    }
    if(adj[a].size() > 2) checkchild = true;
    return !(checkcycle || checkchild);

}
int main(){
    int v,e;
    cin >> v >> e;
    if(e == 0){
        cout << v << endl;
        return 0;
    }
    int v1,v2;
    int ans = 0;
    vector<vector<int>> adj(v);
    for(int i =0;i<e;i++){
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    vector<bool> visited(v,false);
    for(int i =0;i<v;i++){
        if(!visited[i]){
            if(dfs(i,adj,visited,-1)){
                ans += 1;
            }
        }

    }
    cout << ans << endl;

}