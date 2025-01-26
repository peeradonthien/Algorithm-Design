#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n ,m;
    cin >> n >> m;
    vector<int> v(n);
    int x;
    for(int i = 0 ;i<n;i++){
        cin >> x;
        v[i] = x;
    }
    int ask;
    for(int i = 0 ; i<m;i++){
        cin >> ask;
        int pos = 0;
        int ans = 0;
        while(v[pos] != ask){
            if(v[pos] > ask) ans++;
            pos++;
        }
        cout << ans << endl;
    }
}         


// 3 4 6 2 1 5
// 1 2 3 4 5 6