#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> dp(n+1,vector<int>(2)); //dp[i][j] i คือความยาว j คือเลขที่ต่อท้ายมี 0 กับ 1
    //initial ที่ความยาว1 มี1เคสเเน่ๆ
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i =2;i<=n;i++){
        //เติม0 ตัวก่อนหน้าเป็น 0 หรือ 1 ก็ได้ เลยได้จำนวน2อันมาบวกกัน
        dp[i][0] = (dp[i-1][0] + dp[i-1][1])%100000007;
        //เติม1 ต้องห่างจากตัวก่อนหน้า k
        int len = max(i-k+1 , 1); 
        dp[i][1] = dp[len][0]; // ถ้ามีเลข1ก่อนหน้า i ต้องอยู่ที่ i-k เป็นต้นไป  ตั้งเเต่ i-k+1มีเเต่0
    }
    //ที่ความยาว n
    cout << (dp[n][0] + dp[n][1]) % 100000007;
    

}