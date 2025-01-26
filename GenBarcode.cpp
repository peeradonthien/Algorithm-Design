#include <iostream>
#include <vector>
using namespace std;
void genbar(int &a , int &b , int len , int count , vector<int> &sol){
    if(len < b){
        sol[len] = 0;
        genbar(a,b,len+1,count,sol);
        sol[len] = 1;
        genbar(a,b,len+1,count+1,sol);
    }
    else{
        if(count == a){
            for(auto &x : sol){
                cout << x;
            }
            cout << endl;
        }
    }
}
int main(){
    int a,b;
    cin >> a >> b;
    vector<int> sol(b,0);
    genbar(a,b,0,0,sol);
}