#include <iostream>
#include <vector>
using namespace std;
vector<int> v = {1,11,111,1111,11111,111111,1111111,11111111,111111111,1111111111};
int one(int x,int len,int ans){
    if(abs(v[len-1]-x) > abs(v[len]-x)){

    }
}
int main(){
    string x;
    cin >> x;
    int len = x.size();
    int ask = stoi(x);
    cout << one(ask,len) << endl;
}