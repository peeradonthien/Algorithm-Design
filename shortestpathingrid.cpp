#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int r,c;
    cin >> r >> c;
    vector<vector<int>> v(r,vector<int>(c));
    string x;
    for(int i =0;i<r;i++){
        cin >> x;
        for(int j = 0 ; j < c;j++){
            if(x[j] == '.') v[i][j] = 0;
            if(x[j] == '#') v[i][j] = 1;
        }
    }
    vector<vector<int>> dist(r,vector<int>(c,-1));
    queue<pair<int,int>> q;
    int offset [4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    dist[0][0] = 0;
    q.push(make_pair(0,0));
    while(!q.empty()){
        auto a = q.front();
        q.pop();
        for(int i =0;i<4;i++){ //adjacent มี 4node ทุกอันคือซ้ายขวาหน้าหลัง
            pair<int,int> b = make_pair(a.first+offset[i][0] , a.second+offset[i][1]);
            //check out of range
            if(b.first < 0 || b.first >=r || b.second < 0 || b.second >=c) continue;
            //check visited
            if(dist[b.first][b.second] != -1) continue;
            //check obstacle
            if(v[b.first][b.second] == 1) continue;
            dist[b.first][b.second] = dist[a.first][a.second] +1;
            q.push(b);
        }
    }
    cout << dist[r-1][c-1] << endl;
}