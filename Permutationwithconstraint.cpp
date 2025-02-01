#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
void perm(int n , int m ,int len , vector<int> &sol , vector<int> &v, vector<bool> &used){
    if(len < n){
        for(int i=0;i<n;i++){
            if(!used[i]){
                if(v[i] != -1 && find(sol.begin(), sol.begin() + len, v[i]) == sol.begin() + len) continue;
                used[i] = true;
                sol[len] = i;
                perm(n, m ,len+1,sol,v,used);
                used[i] = false;
            }
        }
    }
    else{
        for(auto &x : sol) cout << x << " ";
        cout << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    int x1,x2;
    vector<int> v(n,-1);
    for(int i =0;i<m;i++){
        cin >> x1  >> x2;
        v[x2] = x1;
    }
    vector<int> sol(n,0);
    vector<bool> used(n,false);
    perm(n, m ,0,sol,v,used);
}