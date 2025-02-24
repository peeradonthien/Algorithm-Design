#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n+1);
    v[0]=0;
    for(int i =1;i<=n;i++){
        cin >> v[i];
    }
    vector<int> b(n+1);
    b[0] = 0;
    //initial
    b[1] = v[1];
    b[2] = b[1] + v[2];
    b[3] = max(b[1],b[2]) + v[3];
    for(int i =4;i<=n;i++){
        b[i] = max(b[i-3] , max(b[i-2] , b[i-1]))+v[i];
    }
    cout << b[n] << endl;
}