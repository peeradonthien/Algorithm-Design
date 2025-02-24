#include <iostream>
#include <map>
using namespace std;
int main(){
    int n;
    cin >> n;
    map<int,int> m;
    int ans = -1000;
    int sum = 0;
    int x;
    for(int i =0;i<n;i++){
        cin >> x;
        ans = max(ans,x);
        if(m.find(x) != m.end()){
            ans = max(ans,sum+x-m[x]);
            m[x] = min(m[x],sum);
        }
        else{
            m[x] = sum;
        }
        sum += x;
    }
    cout << ans << endl;
}