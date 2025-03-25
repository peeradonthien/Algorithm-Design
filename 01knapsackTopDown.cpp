#include <iostream>
#include <vector>
using namespace std;
vector<int> w,p;
vector<vector<int>> table;
vector<int> ans;
int knapsack(int idx , int remain){
    if(idx == 0) return 0;
    int r1,r2;
    if(table[idx][remain] != -1){
        return table[idx][remain];
    }
    if(remain >= w[idx]){
        int r1 = knapsack(idx-1,remain);
        int r2 = knapsack(idx-1,remain-w[idx]) + p[idx];
        table[idx][remain] = max(r1,r2);
    }
    else{
        table[idx][remain] = knapsack(idx-1,remain);
    }
    return table[idx][remain];

}
int main(){
    int n,m;
    cin >> n >> m;
    w.resize(n+1);
    p.resize(n+1);
    table.resize(n+1,vector<int>(m+1,-1));
    for(int i =1;i<=n;i++){
        cin >> p[i];
    }
    for(int i =1;i<=n;i++){
        cin >> w[i];
    }

    cout << knapsack(n,m) << endl;
    for(auto &x : ans)cout << x << " ";
    cout << endl;


    for(auto &x : table){
        for(auto &y : x){
            cout << y << " ";
        }
        cout << endl;
    }
}