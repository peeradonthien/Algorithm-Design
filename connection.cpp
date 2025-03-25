#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n,e,k;
    cin >> n >> e >> k;
    vector<vector<int>> adj(n);
    int v1,v2;
    for(int i =0;i<e;i++){
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    vector<bool> visited(n,false);
    int maxi = 0;
    for(int i =0;i<n;i++){
        int friends = 0;
        vector<bool> visited(n,false);
        queue<pair<int,int>> q; // node depth
        q.push(make_pair(i,0));
        visited[i] = true;
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            if(u.second > k) continue;
            friends++;
            for(auto &x : adj[u.first]){
                if(!visited[x]){
                    visited[x] = true;
                    q.push(make_pair(x,u.second+1));
                }
            }
        }
        maxi = max(maxi , friends);

    }
    cout << maxi << endl;
}