#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,k,finish;
    cin >> n >> m >> k;
    cin >> finish;
    int ans = 1e9;
    vector<int> dist(n,1e9);
    int ask;
    for(int i =0;i<k;i++){
        cin >> ask;
        dist[ask] = 0;
    }
    vector<pair<pair<int,int> ,int>> e;
    int v1,v2,ww;
    for(int i =0;i<m;i++){
        cin >> v1 >> v2 >> ww;
        e.push_back({{v1,v2},ww});
    }
    for(int i =1;i<=n-1;i++){
        for(auto &x : e){
            int a = x.first.first;
            int b = x.first.second;
            int w = x.second;
            if(dist[b] > dist[a] + w){
                dist[b] = dist[a] + w;
            }
        }
    }

   cout << dist[finish]<< endl;
}