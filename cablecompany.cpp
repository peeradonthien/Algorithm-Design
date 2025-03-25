#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> edgeprice(n,vector<int>(n));
    vector<vector<int>> adj(n);
    int count = n-1;
    int x;
    for(int i =0;i<n-1;i++){
        for(int j =0;j<count--;j++){
            cin >> x;
            edgeprice[i].push_back(x);
            adj[i].push_back(j);
        }
    }


    //prim
    vector<int> cost(n,1e9),prev(n,-1);
    vector<bool> taken(n,false);
    set<pair<int,int>> s;
    s.insert({0,0});
    while(!s.empty()){
        pair<int,int> b = *s.begin();
        s.erase(b);
        taken[b.second] = true;
        for(auto &x : adj[b.second]){
            if(cost[x] > edgeprice[b.second][x] && taken[x] == false){
                if(s.find({cost[x],x}) != s.end()) s.erase({cost[x],x});
                cost[x] = edgeprice[b.second][x];
                prev[x] = b.second;
                s.insert({cost[x],x});
            }
        }
    }


}