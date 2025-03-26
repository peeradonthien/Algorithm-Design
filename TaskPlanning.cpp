#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n,amount,v;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> inDegree(n,0);
    for(int i =0;i<n;i++){
        cin >>  amount;
        for(int j =0;j<amount;j++){
            cin >> v;
            adj[v].push_back(i);
            inDegree[i]++;
        }
    }
    vector<int> ans;
    queue<int> q;
    for(int i =0;i<n;i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(auto &x : adj[u]){
            inDegree[x]--;
            if(inDegree[x] == 0){
                q.push(x);
            }

        }
    }
    for(auto &x : ans){
        cout << x << " ";
    }
    cout << endl;
}