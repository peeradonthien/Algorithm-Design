#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int r,c,k;
    cin >> r >> c >> k;
    vector<vector<int>> v(r,vector<int>(c));
    vector<pair<int,int>> one;
    int offset[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    for(int i =0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> v[i][j];
            if(v[i][j] == 1)one.push_back({i,j});
        }
    }
    vector<vector<int>> temp = v;
    vector<vector<int>> visited(r,vector<int>(c,false));
    for(auto &node : one){
        queue<pair<pair<int,int>,int>> q; // x y and depth
        q.push({node,0});
        visited[node.first][node.second] = true;
        while(!q.empty()){
            auto a = q.front();
            q.pop();
            if(a.second >= k) continue;
            for(int i=0;i<4;i++){
                int rr = a.first.first + offset[i][0];
                int cc = a.first.second + offset[i][1];
                if(rr < 0 || rr >= r || cc < 0 || cc >= c) continue;
                if(visited[rr][cc]) continue;
                if(temp[rr][cc] == 0){
                    temp[rr][cc] = 2;
                    visited[rr][cc] = true;
                    q.push({{rr,cc},a.second +1});
                } 
            }
        }
    }

    for(auto &x : temp){
        for(auto &y : x){
            cout << y << " ";
        }
        cout << endl;
    }

    

}