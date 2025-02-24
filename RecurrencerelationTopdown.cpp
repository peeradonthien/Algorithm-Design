//TopDown
#include <iostream>
#include <vector>
using namespace std;
vector<int> c,a;
vector<int> table;
int k;
int relation(int n){
    if(n<k) return a[n];
    if(table[n] != -1) return table[n];
    int result = 0;
    for(int i=0;i<k;i++){
        result += (c[i]*relation(n-1-i))%32717;
    }
    table[n] = result%32717;
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