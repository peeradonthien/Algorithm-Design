#include <iostream>
#include <vector>
using namespace std;
int main(){
    int r,c,k;
    vector<vector<int>> n(r+1,vector<int>(c+1)) , s(r+1,vector<int>(c+1)) , non(r+1,vector<int>(c+1));
    for(int i =1;i<=r;i++){
        for(int j =1;j<=c;j++){
            cin >> n[i][j];
        }
    }
    for(int i =1;i<=r;i++){
        for(int j =1;j<=c;j++){
            cin >> s[i][j];
        }
    }
    for(int i =0;i<k;i++){
        int x,y;
        cin >> x >> y;
        non[x][y] = 1;
    }

    
}