#include <iostream>
#include <vector>
using namespace std;
vector<int> table;
int fibo(int n){
    table[0]=0;
    table[1]=1;
    for(int i =2;i<=n;i++){
        table[i] = table[i-1]+table[i-2];
    }
    return table[n];
}
int main(){
    int n;
    cin >> n;
    table.resize(n);
    cout << fibo(n) << endl;

}