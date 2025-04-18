#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> r(n,vector<int>(n));
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin >> r[i][j];
        }
    }
    vector<int> dist(n,1e9);
}