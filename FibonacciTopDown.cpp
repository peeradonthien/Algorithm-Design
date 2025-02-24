#include <iostream>
#include <vector>
using namespace std;
vector<int> table;
int fibo(int n ){
    if(n==0 || n==1) return n;
    if(table[n] > 0){
        return table[n];
    }
    int result = fibo(n-1)+ fibo(n-2);
    table[n] = result;
    return result;

}
int main(){
    int n;
    cin >> n;
    table.resize(n+1);
    cout << fibo(n) << endl;
}