#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
void bfs(int start , vector<int> &dist , vector<vector<int>> &adj){
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto &x : adj[u]){
            if(dist[x] > dist[u]+1){
                dist[x] = dist[u]+1;
                q.push(x);
            }
        }
    }
}
int main(){
    int n,t1,t2,t3;
    cin >> n;
    cin >> t1 >> t2 >> t3;
    vector<vector<int>> e(n+1);
    int amount,x;
    for(int i=1;i<=n;i++){
        cin >> amount;
        for(int j =0;j<amount;j++){
            cin >> x;
            e[i].push_back(x);
        }
    }
    vector<int> dist1(n+1,1e9),dist2(n+1,1e9),dist3(n+1,1e9);
    bfs(t1,dist1,e);
    bfs(t2,dist2,e);
    bfs(t3,dist3,e);

    int ans = 1e9;
    //check
    for(int i =1;i<=n;i++){
        ans = min(ans , max({dist1[i] , dist2[i] , dist3[i]}));
    }

    cout << ans << endl;

}