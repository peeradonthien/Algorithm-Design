#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> table;
int binomial(int n, int r){
    if(r == n) return 1;
    if(r==0) return 1;
    if(table[n][r] != -1) return table[n][r]; // ถ้าเคยคิดมาเเล้ว
    int result = binomial(n-1,r) + binomial(n-1,r-1);
    table[n][r] = result; // remember
    return result;
}
int main(){
    int n,r;
    cin >> n >> r;
    table.resize(n+1,vector<int>(n+1,-1));
    cout << binomial(n,r) << endl;
}