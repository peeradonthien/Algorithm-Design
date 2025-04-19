#include <iostream>
#include <queue>
#include <algorithm>
#include <iomanip>  
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(m);
    int x;
    for(int i =0;i<m;i++){
        cin >> v[i];
    }
    double sum = 0;
    sort(v.begin(),v.end());
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i =0;i<n;i++){
        pq.push(v[i]);
        sum += v[i];
    }
    for(int i =n;i<m;i++){
        int now = pq.top()+v[i];
        pq.pop();
        pq.push(now);
        sum += now;
    }
    double ans = sum/m;
    cout << fixed << setprecision(3) << ans << endl;
}