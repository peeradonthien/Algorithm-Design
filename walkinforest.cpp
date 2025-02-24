#include <iostream>
#include <vector>
using namespace std;
int main(){
    int r,c;
    cin >> r >> c;
    vector<vector<int>> v(r,vector<int>(c));
    vector<vector<int>> v1(r,vector<int>(c));
    int ask;
    for(int i = 0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> ask;
            v[i][j] =ask;
            v1[i][j] =ask;
        }
    }
    for(int i = 0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i+1 < r){
                v1[i+1][j] = max(v1[i+1][j] , v1[i][j]+v[i+1][j]);
            }
            if(j+1 < c){
                v1[i][j+1] = max(v1[i][j+1] , v1[i][j]+v[i][j+1]);
            }
            if(i+1 < r && j+1 < c){
                v1[i+1][j+1] = max(v1[i+1][j+1] , v1[i][j]+ 2*v[i+1][j+1]);
            }
        }
    }


    cout << v1[r-1][c-1] << endl;
}
