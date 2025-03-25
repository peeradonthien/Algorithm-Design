#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> p(n+1) , w(n+1);
    for(int i =1;i<=n;i++){
        cin >> p[i];
    }
    for(int i =1;i<=n;i++){
        cin >> w[i];
    }
    vector<vector<int>> v(n+1,vector<int>(m+1));
    for(int i =0;i<=n;i++){
        for(int j =0;j<=m;j++){
            cin >> v[i][j];
        }
    }
    vector<int> ans;
    int nowrow = n;
    int nowcolumn = m;
    while(nowrow > 0 && nowcolumn > 0){
        if(v[nowrow][nowcolumn] == v[nowrow-1][nowcolumn]){
            nowrow--;
        }
        else{
            ans.push_back(nowrow);
            nowrow--;
            nowcolumn -= w[nowrow+1];
        }
    }
    cout << ans.size() << endl;
    for(auto &x : ans){
        cout << x << " ";
    }
    cout << endl;
}