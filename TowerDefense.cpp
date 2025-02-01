#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,k,w,ans;
vector<int> towerpos;
vector<pair<int,int>> monster; //pos power
void fight(int nowpos){
    if(nowpos == k){
        int nowpower=0;
        for(auto &x : monster){
            nowpower += x.second;
        }
        ans = min(ans,nowpower);
        return;
    }
    int tower_x = towerpos[nowpos]; 
    vector<int> affected_indices;

    for (int i = 0; i < m; i++) {
        if (abs(monster[i].first - tower_x) <= w && monster[i].second > 0) {
            monster[i].second--; 
            affected_indices.push_back(i); 
        }
    }

    fight(nowpos + 1);

    for (int i : affected_indices) {
        monster[i].second++;
    }

}

int main(){
    cin >> n >> m >> k >> w;
    ans = 1000*m;
    monster.resize(m);
    for(int i =0;i< m;i++){
        cin >> monster[i].first;
    }
    
    for(int i =0;i<m;i++){
        cin >> monster[i].second;
    }
    sort(monster.begin(),monster.end());
    towerpos.resize(k);
    for(int i =0;i<k;i++){
        cin >> towerpos[i];
    }
    fight(0);
    cout << ans << endl;
}