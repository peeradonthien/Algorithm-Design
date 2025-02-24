#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> v,table;
int maxnum = -1000;
int n;
int main(){
    cin >> n;
    int maxone = -1000;
    v.resize(n,vector<int>(n));
    table.resize(n-1,vector<int>(n-1));
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> v[i][j];
            maxone = max(maxone,v[i][j]);
        }
    }
    for(int i =1;i<n;i++){
        for(int j=1;j<n;j++){
            v[i][j] = max(v[i][j],(v[i-1][j-1]+v[i][j]));
            maxone = max(maxone,v[i][j]);
        }
    }
    cout << maxone << endl;

}
