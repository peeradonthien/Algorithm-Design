#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n,a,b;
    cin >> n >> a >> b;
    vector<vector<int>> obstacle(1001,vector<int>(1001));
    int x,y;
    for(int i =0;i<n;i++){
        cin >> x >> y;
        obstacle[x][y] = 1;
    }
    int offset[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    queue<pair<int,int>> q; //(x,y)
    vector<vector<bool>> visited(1001,vector<bool>(1001,false));
    vector<vector<int>> tom(1001,vector<int>(1001,0));
    q.push({a,b});
    visited[a][b] = true;
    int ans = 100000;
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        if(x == 1 || x == 1000 || y == 1 || y == 1000){
            ans = min(ans , tom[x][y]);
        }
        for(int i =0;i<4;i++){
            int adjx = x+offset[i][0];
            int adjy = y+offset[i][1];
            if(adjx <= 0 || adjx > 1000 || adjy <= 0 || adjy > 1000) continue;
            if(visited[adjx][adjy]) continue;
            if(obstacle[adjx][adjy] == 1) tom[adjx][adjy] = tom[x][y]+1;
            else tom[adjx][adjy] = tom[x][y];
            visited[adjx][adjy] = true;
            q.push({adjx,adjy});
        }
    }
    cout << ans << endl;
}