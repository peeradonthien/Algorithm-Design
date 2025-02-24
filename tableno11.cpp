#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    //length 1
    int state0 = 1; //00
    int state1 = 1; //01
    int state2 = 1; //10

    int s0,s1,s2;
    for(int i =2;i<=n;i++){
        s0 = (state0%100000007 + state1%100000007 + state2%100000007)%100000007;
        s1 = (state0%100000007 + state2%100000007)%100000007;
        s2 = (state0%100000007 + state1%100000007)%100000007;
        state0 = s0;
        state1 = s1;
        state2 = s2;
    }
    cout << (state0+state1+state2)%100000007 << endl;
}