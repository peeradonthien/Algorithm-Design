#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> c(n+1);
    c[0] = 0;
    for(int i = 1;i<=n;i++){
        cin >> c[i];
    }
    vector<int> v(n+1);
    //initial
    v[0] = 0;
    v[1] = c[1];
    v[2] = c[2];
    for(int i =3;i<=n;i++){
        v[i] = max(v[i-2]+c[i],max(v[i],v[i-3]+c[i]));
    }
    // for(auto &x : v) cout << x << " ";
    // cout << endl;
    cout << v[n] << endl;


}