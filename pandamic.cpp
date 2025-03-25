#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int r, c ,t;
    cin >> r >> c >> t;
    vector<vector<int>> data(r,vector<int>(c));
    for(int i =0;i<r;i++){
        for(int j =0;j<c;j++){
            cin >> data[i][j];
        }
    }
    int ans = 0;
    int offset[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> depth(r,vector<int>(c,0));
    vector<vector<bool>> visited(r,vector<bool>(c,false));
    for(int i =0;i<r;i++){
        for(int j =0;j<c;j++){
            if(data[i][j] == 0 || data[i][j] == 2)continue;
            if(visited[i][j]) continue;
            queue<pair<int,int>> q;
            q.push(make_pair(i,j));
            visited[i][j] = true;
            ans += 1;
            while(!q.empty()){
                auto a = q.front();
                q.pop();
                if(depth[a.first][a.second] >= t) continue;
                for(int m =0;m<4;m++){
                    pair<int,int> b = make_pair(a.first+offset[m][0],a.second+offset[m][1]);
                    if(b.first < 0 || b.first >= r || b.second <0 || b.second >= c) continue;
                    if(data[b.first][b.second] != 0) continue;
                    if(visited[b.first][b.second]) continue;
                    visited[b.first][b.second] = true;
                    data[b.first][b.second] = 1;
                    ans ++;
                    depth[b.first][b.second] = depth[a.first][a.second]+1;
                    q.push(make_pair(b.first,b.second));
                }
            }

        }
    }
    cout << ans << endl;
}