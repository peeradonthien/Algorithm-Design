#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool divide(vector<int> &v  ,int start , int stop){
    if(start+1 == stop) return true; // length 2 always true
    int m = (start+stop)/2;
    bool left = divide(v,start,m);
    bool right = divide(v,m+1,stop);
    int one = 0;
    for(int i = start;i<=m;i++){
        one += v[i];
    }
    for(int i = m+1;i<=stop;i++){
        one -= v[i];
    }
    if(one > 1 || one < -1) return false;
    return left && right;
}
int main(){
    int n,k;
    cin >> n >> k;
    int amount = pow(2,k);
    vector<int> v(amount);
    int ask;
    for(int i =0;i<n;i++){
        for(int j = 0;j<amount;j++){
            cin >> ask;
            v[j] = ask;
        }
        if(divide(v,0,amount-1)){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
}