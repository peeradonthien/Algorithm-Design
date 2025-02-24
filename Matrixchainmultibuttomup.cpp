#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
vector<vector<int>> b;
int main(){
    int n;
    cin >> n;
    b.resize(n,vector<int>(n,0));
    a.resize(n+2);
    for(int i =0;i<=n;i++){
        cin >> a[i];
    }
    /*
    0 0 0 0 0
    0 0 0 0 0
    0 0 0 0 0
    0 0 0 0 0
    0 0 0 0 0
    */
    //เติมตัวที่อยู่ติดกันก่อน
    for(int i =0;i<n;i++){
        b[i][i+1] = a[i] * a[i+1] * a[i+2];
    }
    // 0 50 0 0  0 
    // 0 0 25 0  0 
    // 0 0 0  50 0 
    // 0 0 0  0  100 
    // 0 0 0  0  0 

    //เติมตัวที่เหลือ
    for(int i = )

    // for(auto &x : b){
    //     for(auto &y : x){
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
}



