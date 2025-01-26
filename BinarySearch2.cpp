#include <iostream>
#include <vector>
using namespace std;
int bsearch(vector<int> &v , int k , int start, int stop){
    if(start == stop) return v[start] <= k ? v[start] : -1;
    int m = (start+stop) / 2;
    if(v[m] >= k || (v[m] < k && v[m+1] > k)){
        return bsearch(v,k,start,m);
    }
    else{
        return bsearch(v,k,m+1,stop);
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> data(n);
    for(int i=0;i<n;i++){
        cin >> data[i];
    }
    int ask;
    for(int i=0;i<m;i++){
        cin >> ask;
        if(ask < data[0]){
            cout << -1 << endl;
        }
        else{
            cout << bsearch(data,ask,0,data.size()-1) << endl;
        }
    }
}