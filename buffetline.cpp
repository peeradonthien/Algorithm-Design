#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int f,w,n;
    cin >> f >> w >> n;
    vector<int> v(f+1);
    v[0] = -1;
    for(int i =1;i<=f;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int far = 0;
    int ans = 0;
    for(int i =1;i<=f;i++){
        if(far < v[i]){
            int pos = v[i]+w;
            far = pos + w;
            ans++;
        }
    }
    cout << ans << endl;
}