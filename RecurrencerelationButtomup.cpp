#include <iostream>
#include <vector>
using namespace std;
vector<int> c,a;
vector<int> table;
int k;
int relation(int n){
    //initial
    for(int i =0;i<k;i++){
        table[i] = a[i]%32717;
    }
    int result =0;
    for(int i =k;i<=n;i++){
        for(int j=0;j<k;j++){
            result += (c[j]*table[i-1-j])%32717;
        }
        table[i] = result%32717;
        result = 0;
    }
    return table[n];

}
int main(){
    int n;
    cin >> k >> n;
    c.resize(k);
    a.resize(k);
    table.assign(n+1,-1);
    for(int i =0;i<k;i++){
        cin >> c[i];
    }
    for(int i =0;i<k;i++){
        cin >> a[i];
    }
    cout << relation(n) << endl;

}