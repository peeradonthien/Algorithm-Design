#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
vector<vector<int>> dp;
int coinchange(int idx , int remain){
    if(remain==0)return 0;
    if(idx==0)return 100000;
    if(dp[idx][remain] != -1)return dp[idx][remain];
    if(v[idx] <= remain){ //พอ
        int r1,r2;
        r1 = coinchange(idx , remain-v[idx])+1; //เอา
        r2 = coinchange(idx-1,remain); //ไม่เอา
        dp[idx][remain] = min(r1,r2);
    }
    else{ //ไม่พอ
        dp[idx][remain] =  coinchange(idx-1,remain);
    }
    return dp[idx][remain];
}
int main(){
    int n,m;
    cin >> n >> m;
    v.resize(n+1);
    dp.assign(n+1,vector<int>(m+1,-1));
    for(int i =1;i<=n;i++){
        cin >> v[i];
    }
    int ans = coinchange(n,m);
    cout << ans << endl;
    for(auto &x : dp){
        for(auto&y : x){
            cout << y << " ";
        }
        cout << endl;
    }
}