#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> vsort(n);
    int x;
    for(int i =0;i<n;i++){
        cin >> x;
        v[i] = x;
        vsort[i] = x;
    }
    sort(vsort.begin() , vsort.end());
    vector<vector<int>> data(n+1,vector<int>(n+1,0));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(v[i-1] == vsort[j-1]){
                data[i][j] = data[i-1][j-1]+1;
            }
            else{
                data[i][j] = max(data[i][j-1],data[i-1][j]);
            }
        }
    }
    cout << data[n][n] << endl;
    
}