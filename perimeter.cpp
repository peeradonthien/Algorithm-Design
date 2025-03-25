#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n,e,k;
    cin >> n >> e >> k;
    if(e == 0){
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int>> adj(n+1);
    int v1,v2;
    for(int i =0;i<e;i++){
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    vector<bool> visited(n,false);
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    visited[0] = true;
    int ans =0;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        if(u.second > k) continue;
        if(u.second == k) ans++;
        for(auto &x : adj[u.first]){
            if(!visited[x]){
                visited[x] = true;
                q.push(make_pair(x,u.second+1));
            }
        }
    }
    cout << ans << endl;

}