#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
void perm(int n , int m ,int len , vector<int> &sol , map<int,int> &data , vector<bool> &used , vector<int> &condi){
    if(len < n){
        for(int i =0;i<n;i++){
            if(used[i] == false){
                if(find(condi.begin(),condi.end(),i) != condi.end()) return;
                used[i] = true;
                sol[len] = i;
                if(data.find(i) != data.end()){
                    condi.push_back(data[i]);
                }
                perm(n,m,len+1,sol,data,used,condi);
                condi.clear();
                used[i] = false;
            }
        }
    }
    else{
        for(auto &x :sol){
            cout << x << " ";
        }
        cout << "\n" ;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    int x1,x2;
    map<int,int> data;
    for(int i =0;i<m;i++){
        cin >> x1  >> x2;
        data[x2] = x1;
    }
    vector<int> sol(n,0);
    vector<bool> used(n,false);
    vector<int> condi;
    perm(n, m ,0,sol,data,used,condi);
}