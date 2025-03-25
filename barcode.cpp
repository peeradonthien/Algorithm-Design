#include <iostream>
#include <vector>
using namespace std;
int n,m,k;
vector<vector<vector<int>>> dp;
int barcode(int idx , int nowm , int nowk , int color){
    // ติดกันเกิน m     เปลี่ยนเกิน k    ไม่เหลือที่พอให้เปลี่ยนk
    if(nowm > m   ||  nowk > k  || k-nowk > n-idx) return 0;
    if(dp[idx][nowm][nowk] != -1) return  dp[idx][nowm][nowk];
    if(idx == n && nowk == k)return 1;
    //เลือกสีเดิม + เปลี่ยนสี
    dp[idx][nowm][nowk] = barcode(idx+1,m+1,nowk ,color)+barcode(idx+1,m,nowk+1,abs(color-1));
    return dp[idx][nowm][nowk];
}
int main(){
    cin >> n >> m >> k;
    dp.resize(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
    cout << barcode(n,m,k,0) << endl; //เริ่มดำ(0)
}