#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int r,c;
    cin >> r >> c;
    vector<vector<int>> map(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> map[i][j];
        }
    }
    int offset[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    //dijkstra
    vector<vector<int>> dist(r,vector<int>(c,1e9));
    set<pair<pair<int,int>,int>> s;
    dist[0][0] = 0;
    s.insert({{0,0},0});
    while(!s.empty()){
        auto b = *s.begin();
        int x = b.first.first;
        int y = b.first.second;
        s.erase(b);
        for(int i=0;i<4;i++){
            int adjx = x+offset[i][0];
            int adjy = y+offset[i][1];
            if(adjx < 0 || adjx >= r || adjy < 0 || adjy>=c)continue;
            if(dist[adjx][adjy] > b.second + map[adjx][adjy]){
                if(s.find({{adjx,adjy},dist[adjx][adjy]})!=s.end()) s.erase({{adjx,adjy},dist[adjx][adjy]});
                dist[adjx][adjy] = b.second + map[adjx][adjy];
                s.insert({{adjx,adjy},dist[adjx][adjy]});
            }
        }
    }

    for(auto &x : dist){
        for(auto &y : x){
            cout << y << " ";
        }
        cout << endl;
    }
    
    
    
    
}