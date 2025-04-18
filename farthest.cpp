#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> v[i][j];
        }
    }
    vector<int> dist(n);
    set<pair<int,int>> s;
    s.insert(0,0); //w start
    while(!s.empty()){
        auto [t,u] = *s.begin();
        for(int i=0;i<n;i++){
            if(i==u) continue;
            if(dist[i] > t+v[u][i]){
                if(s.find() != s.end()) s.erase();
                dist[i] = t + v[]
            }
        }
    }
}