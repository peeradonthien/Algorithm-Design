#include <iostream>
#include <vector>
using namespace std;
int ans = 1001;
void brute(int ischoose , int personuse , int person , vector<vector<int>> &v , int n , int m ,vector<bool> &used){
    if(ischoose == n) {
        ans = min(ans,personuse);
        return;
    }
    if(person == m) return;
    if(personuse == ans) return;

    for(auto &x : v[person]){
        if(!used[x]) personuse++;
        used[x] = true;
    }
    brute(ischoose,personuse+1,person+1,v,n,m,used);

    for(auto &x : v[person]){
        used[x] = false;
        if(!used[x]) ischoose--;
    }
    brute(ischoose,personuse,person+1,v,n,m,used);


}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(m);
    int amount,x;
    for(int i =0 ;i<m;i++){
        cin  >> amount;
        for(int j=0;j<amount;j++){
            cin >> x;
            v[i].push_back(x);
        }
    }
    vector<bool> used(n);
    brute(0,0,0,v,n,m,used);
    cout << ans << endl;
}