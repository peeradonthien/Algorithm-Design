#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
vector<vector<int>> dp;
int futo(int start , int stop){
    if(stop - start == 1) return max(v[start],v[stop]);
    if(dp[start][stop] != 0) return dp[start][stop];
    int s1 = futo(start+2,stop);
    int s2 = futo(start,stop-2);
    int s3 = futo(start+1,stop-1);
    int value = max({ s1+max(v[start],v[start+1]) , s2+max(v[stop],v[stop-1]) , s3+max(v[start],v[stop])});
    dp[start][stop] = value;
    return value;
    
}
int main(){
    int n;
    cin >> n;
    v.resize(n);
    dp.resize(n,vector<int>(n));
    for(int i =0;i<n;i++){
        cin >> v[i];
    }
    cout << futo(0,n-1) << endl;
}