#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<pair<int,int>> v(n);
    for(int i =0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
    vector<pair<int,int>> vpos(n);
    sort(v.begin(),v.end());
    int before = 0;
    for(int i =0;i<n;i++){
        vpos[i].first = v[i].second + before;
        before += v[i].second;
        vpos[i].second = v[i].first;
    }
    /*
    for(auto &x : vpos){
        cout << x.first << " " << x.second << endl;
    }
    */
    int ask;
    for(int i = 0;i<q;i++){
        cin >> ask;
        auto it = lower_bound(vpos.begin(),vpos.end(),make_pair(ask, 0));
        cout << it->second << "\n";
    }
    
}