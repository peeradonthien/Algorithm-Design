#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,l;
    cin >> n >> l;
    vector<int> v(n);
    int range=0;
    for(int i =0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(auto &x : v){
        if(x>range){
            ans++;
            range = x+l-1;
        }
    }
    cout << ans << endl;

}