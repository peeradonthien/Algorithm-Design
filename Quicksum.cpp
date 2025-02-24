#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m,k,r1,c1,r2,c2;
    cin >> n >> m >> k;
    vector<vector<int>> v(n,vector<int>(m));
    vector<vector<int>> p(n,vector<int>(m));
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
        }
    }
    p[0][0] = v[0][0];
    for(int i=1;i<m;i++){
        p[0][i] = p[0][i-1] + v[0][i];
    }
    for(int i =1;i<n;i++){
        p[i][0] = p[i-1][0] + v[i][0];
        for(int j=1;j<m;j++){
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + v[i][j];
        }
    }
    for(int i = 0;i<k;i++){
        cin >> r1 >> c1 >> r2 >> c2;
        if(r1-1 < 0 && c1-1 >= 0){
            cout << p[r2][c2] - 0 - p[r2][c1-1] + 0 << endl;
        }
        else if(c1-1 < 0 && r1-1 >=0){
            cout << p[r2][c2] - p[r1-1][c2] - 0 + 0<< endl;
        }
        else if(c1-1 < 0 && r1-1 < 0){
            cout << p[r2][c2] << endl;
        }
        else{
            cout <<  p[r2][c2] - p[r1-1][c2] - p[r2][c1-1] + p[r1-1][c1-1] << endl;
        }
    }
    // for(auto &x : p){
    //     for(auto &y : x) cout<< y << " ";
    //     cout << endl;
    // }
}