#include <iostream>
#include <vector>
using namespace std;
vector<int> dp;
vector<int> v;
int billboard(int idx){
    if(idx == 1) return v[1];
    if(dp[idx] != -1) return dp[idx];
    int r1 = billboard(idx-3)+v[idx]; //เอาถอย2
    int r2 = billboard(idx-4)+v[idx]; //เอาถอย3
    int r3 = billboard(idx-1); //ไม่เอา
    dp[idx] = max(r1,max(r2,r3));
    return dp[idx];
}
int main(){
    int n;
    cin >> n;
    v.resize(n+1);
    dp.resize(n+1,-1);
    v[0]=0;
    for(int i =1;i<=n;i++){
        cin >> v[i];
    }
    dp[0]=0;
    dp[1]=v[1];
    dp[2] = v[2];
    dp[3] =v[3];
    cout << billboard(n) << endl;
}