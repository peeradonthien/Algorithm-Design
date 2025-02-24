#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    vector<int> dp(n+1,-1);
    //initial
    dp[0] = 0;
    
    for(int i =1;i<=n;i++){
        if(i>=a && dp[i-a] != -1) dp[i] = max(dp[i-a]+1,dp[i]);
        if(i>=b && dp[i-b] != -1) dp[i] = max(dp[i-b]+1,dp[i]);
        if(i>=c && dp[i-c] != -1) dp[i] = max(dp[i-c]+1,dp[i]);
    }
    cout << dp[n] << endl;
}