#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> adj(n);
    for(int i =0;i<n;i++){
        cin >> adj[i];
    }
    vector<bool> visited(n,false);
    vector<int> cost(n,-1);

    priority_queue<pair<int,int>> q;
    q.push({0,adj[0]});
    long long ans =0;
    while(!q.empty()){
        auto [c,u] = q.top();
        q.pop();
        if(visited[u]) continue;
        visited[u] = true;
        ans += c;
        for(int i =0;i<n;i++){
            if(visited[i]) continue;
            int nowcost = adj[u] ^ adj[i];
            if(nowcost > cost[i]){
                cost[i] = nowcost;
                q.push({cost[i], i});
            }
        }
    }

    cout << ans << endl;


}