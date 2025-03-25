#include <iostream>
#include <vector>
using namespace std;
void combi(int n,vector<int> &sol,int len) {
    if(len < n){
        sol[len] = 0;
        combi(n,sol,len+1);
        sol[len] = 1;
        combi(n,sol,len+1);
    }
    else {
        for(int i =0;i<n;i++){
            if(sol[i] == 1){
                cout << i+1 ;
            }
        }
        cout << endl;
    }
}

void perm(int len , int n , vector<int> &sol , vector<int> &used){
    if(len < n){
        for(int i =1;i<=n;i++){
            if(!used[i-1]){
                used[i-1] = true;
                sol[len] = i;
                perm(len+1,n,sol,used);
                used[i-1] = false;
            }
        }
    }
    else {
        for(auto &x : sol){
            cout << x ;
        }
        cout << endl;
    }
}
int main(){
    vector<int> sol(3);
    combi(3,sol,0);
}

