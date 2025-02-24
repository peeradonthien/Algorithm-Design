#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
vector<vector<int>> table;
int mcm(int l , int r){
    if(l<r){
        int mincost = INT_MAX;
        for(int i =l;i<r;i++){
            int mycost = mcm(l,i) + mcm(i+1,r) + (a[l] * a[i+1] * a[r+1]);
            mincost = min(mycost,mincost);
        }
        return mincost;
    }
    else{
        return 0;
    }
}
int main(){
    int n;
    cin >> n;
    a.resize(n+2);
    a[0] = 0;
    table.resize(n+1,vector<int>(n+1));
    for(int i =1;i<=n+1;i++){
        cin >> a[i];
    }
    cout << mcm(1,n) << endl; 
}