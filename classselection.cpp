#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> s(n),e(n);
    for(int i =0;i<n;i++){
        cin >> s[i];
    }
    for(int i =0;i<n;i++){
        cin >> e[i];
    }
    vector<pair<int,int>> v(n);
    for(int i =0;i<n;i++){
        v[i] = {e[i],s[i]};
    }
    sort(v.begin(),v.end());
    int start = 0;
    int stop = 0;
    int ans = 0;
    for(int i =0;i<n;i++){ // v end start
        if(v[i].second >= stop){
            ans++;
            start = v[i].second;
            stop = v[i].first;
        }
    }
    cout << ans << endl;

}