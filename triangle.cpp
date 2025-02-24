#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    vector<vector<int>> v1(n);
    int x;
    int count =1;
    for(int i =0;i<n;i++){
        for(int j = 0;j<count; j++ ){
            cin >> x;
            v[i].push_back(x);
            v1[i].push_back(x);
        }
        count ++;
    }
    int ans = 0;
    for(int i =0;i<n-1;i++){
        for(int j = 0;j<v[i].size();j++){
            v1[i+1][j] = max(v1[i+1][j] , v[i+1][j]+v1[i][j]);
            v1[i+1][j+1] = max(v1[i+1][j+1] , v[i+1][j+1]+v1[i][j]);
            ans = max({v1[i+1][j] , v[i+1][j+1] , ans});
        }
    }
    cout << ans << endl;




}