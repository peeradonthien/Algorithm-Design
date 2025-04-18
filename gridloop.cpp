#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int ans = 0;
int round = 0;
bool dfs(int rr , int cc , vector<vector<bool>> &visited ,vector<vector<vector<pair<int,int>>>> &adj , int parentr,int parentc ,int depth, vector<vector<int>> &sequence){
    visited[rr][cc] = true;
    sequence[rr][cc] = depth;
    for(auto &x : adj[rr][cc]){
        int adjr = x.first;
        int adjc = x.second;
        if(!visited[adjr][adjc]){
             dfs(adjr,adjc,visited,adj,rr,cc,depth+1,sequence);
        }
        else if(!(adjr == parentr && adjc == parentc)){
            if(find(adj[adjr][adjc].begin(),adj[adjr][adjc].end(),make_pair(rr,cc)) == adj[adjr][adjc].end()) continue;
            ans = max(ans,sequence[rr][cc]-sequence[adjr][adjc]+1);
            return true;
        }
    }
    return false;
}
int main(){
    int r,c;
    cin >> r >> c;
    vector<vector<vector<pair<int,int>>>> adj(r+1,vector<vector<pair<int,int>>>(c+1));
    int ask;
    int offset1 [7][2] = {{0,0},{0,-1},{-1,0},{-1,0},{0,1},{1,0},{0,-1}};
    int offset2 [7][2] = {{0,0},{0,1},{1,0},{0,1},{1,0},{0,-1},{-1,0}};
    for(int i =1;i<=r;i++){ 
        for(int j = 1;j<=c;j ++){
            cin >> ask;
            int adjx1 = i+offset1[ask][0];
            int adjx2 = i+offset2[ask][0];
            int adjy1 = j+offset1[ask][1];
            int adjy2 = j+offset2[ask][1];
            if(adjx1 < 1 || adjx1 > r || adjy1 < 1 || adjy1 > c) continue;
            if(adjx2 < 1 || adjx2 > r || adjy2 < 1 || adjy2 > c) continue;
            adj[i][j].push_back({adjx1,adjy1});
            adj[i][j].push_back({adjx2,adjy2});
        }
    }
    
    vector<vector<bool>> visited(r+1,vector<bool>(c+1));
    vector<vector<int>> sequence(r+1,vector<int>(c+1));
    for(int i = 1 ;i<=r;i++){
        for(int j = 1;j<=c;j++){
            if(!visited[i][j]){
                if(dfs(i,j,visited,adj,-1,-1,0,sequence)){
                    round += 1;
                }
            }
        }
    }

    cout << round << " " << ans << endl;
}
