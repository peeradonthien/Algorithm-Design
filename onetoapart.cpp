#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n+1);
    v[0] = 0;
    v[1] = 3;
    v[2] = 7;
    v[3] = 15;
    for(int i =4;i<=n;i++){
        //กรณีลงท้ายด้วย 0 ได้หมด
        //กรณีลงท้ายด้วย1 2 ตัวหน้าห้ามเป็น 1
        //คูณ 2 คือ กรณี0กับตัวมันเอง
        v[i] = ((v[i-1]*2) + v[i-3])%100000007;
    }
    cout << v[n] << endl;
}