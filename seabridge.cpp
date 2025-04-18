#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int r,c;
    cin >> r >> c;
    vector<vector<int>> v(r+1,vector<int>(c+1));
    v[0][0] = 0;
    queue<pair<pair<int,int> , int>> q; //(x,y) depth
    for(int i =1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> v[i][j];
            if(v[i][j] == 1) q.push({{i,j},1});
        }
    }
    int offset [4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int ans = 1e9;
    vector<vector<int>> visited(r+1,vector<int>(c+1,false));
    while(!q.empty()){
        auto [pos,d] = q.front();
        q.pop();
        for(int i =0;i<4;i++){
            int adjx = pos.first + offset[i][0];
            int adjy = pos.second + offset[i][1];
            if(adjx < 1 || adjx >r || adjy < 1 || adjy >c) continue;
            if(v[adjx][adjy] == 3) continue;
            if(visited[adjx][adjy]) continue;
            if(v[adjx][adjy] == 2) ans= min(ans,d+1);
            if(v[adjx][adjy] == 1) q.push({{adjx,adjy},d});
            else q.push({{adjx,adjy},d+1});
            visited[adjx][adjy] = true;
        }
    }
    cout << ans << endl;

}