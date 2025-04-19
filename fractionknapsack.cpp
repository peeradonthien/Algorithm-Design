#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(){
    int n;
    double W;
    cin >> W >> n;
    vector<double> v(n),w(n);
    for(int i =0;i<n;i++){
        cin >> v[i];
    }
    for(int i =0;i<n;i++){
        cin >> w[i];
    }
    vector<pair<double,int>> ratio(n);
    for(int i = 0;i<n;i++){
        ratio[i] = {v[i]/w[i],i};
    }
    sort(ratio.begin(),ratio.end(),greater<pair<double,int>>());
    double ans = 0;
    for(auto &x : ratio){
        if(w[x.second] < W){
            W -= w[x.second];
            ans += v[x.second];
        }
        else{
            ans += (W*v[x.second])/w[x.second];
            break;
        }
    }
    cout << fixed << setprecision(4) << ans << endl;
}