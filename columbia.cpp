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
    vector<pair<int,int>> prev(r*c,{-1,-1});
    set<pair<pair<int,int>,int>> s;
    s.insert({{0,0},0});
    while(!s.empty()){
        auto b = *s.begin();
        int x = b.first.first;
        int y = b.first.second;
        for(int i=0;i<4;i++){
            if(x < 0 || x >= r || y < 0 || y>=c)continue;
            int adjx = x+offset[i][0];
            int adjy = y+offset[i][1];
            if(dist[adjx][adjy] > b.second + map[adjx][adjy]){
                if(s.find()!=s.end()) erase;
                dist[adjx][adjy] = b.second + map[adjx][adjy];
                prev[] = 
                s.insert();
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