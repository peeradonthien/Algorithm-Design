#include <iostream>
#include <vector>
using namespace std;
int search(vector<int> &v , int k , int start ,int stop){
    if(start == stop){
        if(v[start] != k){
            return start-1;
        }
        while(v[start] == k){
            start++;
        }
        return start-1;
    }
    int m = (start+stop)/2;
    if(v[m] >= k) return search(v,k,start,m);
    else return search(v,k,m+1,stop);
}
int main(){
    int n , m;
    cin >> n >> m;
    vector<int> data(n);
    for(int i=0;i<n;i++){
        cin >> data[i];
    }
    int ask;

    for(int i =0;i<m;i++){
        cin >> ask;
        if(ask < data[0]){
            cout << -1 << endl;
        }
        else{
            cout << search(data,ask,0,data.size()-1) << endl;
        }
        
    }
}