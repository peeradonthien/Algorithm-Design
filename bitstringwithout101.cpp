#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long n;
    cin >> n;
    long long state0 = 1; // ลงท้ายด้วย 0
    long long state1 = 1; // ลงท้ายด้วย 1
    long long state2 = 0; // ลงท้ายด้วย 10
    long long s0,s1,s2;
    for(int i = 1;i<n;i++){
        s0 = (state0 % 100000007 + state2%100000007)%100000007;
        s1 = (state0 % 100000007+ state1 % 100000007)%100000007;
        s2 = state1% 100000007;

        state0 = s0;
        state1 = s1;
        state2 = s2;
    }
    return (s0+s1+s2)% 100000007;

}