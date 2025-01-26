#include <iostream>
#include <vector>
using namespace std;
void bit(int &n,int &k ,int len,int one, vector<int> &sol , vector<bool> &used){
    if(len < n){
        sol[len] = 0;
        if(one >= k){
            bit(n,k,len+1,one,sol,used);
        }
        else{
            bit(n,k,len+1,0,sol,used);
        }
        sol[len] = 1;
        bit(n,k,len+1,one+1,sol,used);
    }
    else{
        if(one >= k){
            for(auto &x : sol){
                cout << x;
            }
            cout << endl;
        }
    }
}
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> sol(n,3);
    vector<bool> used(2,false);
    bit(n,k,0,0,sol,used);
}