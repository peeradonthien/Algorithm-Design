#include <iostream>
#include <vector>
using namespace std;
vector<int> multi(const vector<int> &m , const vector<int> &n , int k){
    return {(m[0]*n[0]+ m[1]*n[2])%k , (m[0]*n[1]+ m[1]*n[3])%k ,(m[2]*n[0]+ m[3]*n[2])%k ,(m[2]*n[1]+ m[3]*n[3])%k};
}
vector<int> mod(const vector<int> &data , int n ,int k){
    if (n == 0) return {1, 0, 0, 1}; 
    if(n%2 == 0){
        vector<int> v1 = mod(data,n/2,k);
        return multi(v1,v1,k);
    }
    return multi(mod(data , n-1, k),data,k); // a**5 = a**2 * a**2 * a
    
}
int main(){
    int n , k;
    cin >> n >> k;
    vector<int> data(4);
    for(int i =0 ;i<4;i++){
        cin >> data[i];
    }
    vector<int> ans = mod(data,n,k);
    for(auto &x : ans){
        cout << x << " "; 
    }
    cout << endl;
}