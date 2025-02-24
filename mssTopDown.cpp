#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> table;
vector<bool> done;
int max_suffix(vector<int> &s , int stop){
    if(stop == 1) return s[1];
    if(done[stop]) return table[stop];
    table[stop] = max(s[stop] , s[stop] + max_suffix(s,stop-1));
    done[stop] = true;
    return table[stop];
    //return max(s[stop],s[stop]+max_suffix(s,stop-1));
}
int mss(vector<int> &s , int stop){
    if(stop == 1) return s[1];
    int r1 = mss(s,stop-1);
    int r2 = s[stop];
    int r3 = max_suffix(s,stop-1);
    return max({r1,r2,r3});
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n+1);
    int sum = 0;
    int ask;
    for(int i =1;i<=n;i++){
        cin >> v[i];
    }
    table.assign(n+1,0);
    done.assign(n+1,false);
    cout << mss(v,n) << endl;
}