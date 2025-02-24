#include <iostream>
#include <vector>
using namespace std;
int mod(int x , int n , int k){
    if(n==1) return x % k;
    if(n % 2 == 0){
        int v = mod(x,n/2,k);
        return (v*v)%k;
    }
    else{
        int v = mod(x,n/2,k);
        v = (v*v) % k;
        return (v*(x%k))%k;
    }

}
int main(){
    int x ,n ,k;
    cin >> x >> n >> k;
    cout << mod(x,n,k) << endl;
}