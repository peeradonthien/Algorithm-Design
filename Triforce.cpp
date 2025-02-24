#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> v;
bool checkS(int rowstart , int rowend , int costart , int coend ,int n){
    if(n==2){
        if(v[rowstart][costart] == 0 && v[rowstart][costart+1] == 0 && v[rowstart+1][costart] == 0 && v[rowstart+1][costart+1]== 0) return true; 
        return false;
    }
    int m = n/2;
    bool x1 = checkS(rowstart,rowstart+m-1,costart,costart+m-1,m);
    bool x2 = checkS(rowstart,rowstart+m-1,costart+m,coend,m);
    bool x3 = checkS(rowstart+m,rowend,costart,costart+m,m);
    bool x4 = checkS(rowstart+m,rowend,costart+m,coend,m);
    return x1 && x2 && x3 && x4;
}
int divide(int rowstart , int rowend , int costart , int coend ,int n){
    if(n==2){
        if(v[rowend][coend] != 0) return 0;
        if(v[rowstart][costart] == 0 || v[rowstart][costart+1] == 0 || v[rowstart+1][costart] == 0) return 0; 
        if(v[rowstart][costart] == v[rowstart][costart+1]) return v[rowstart][costart];
        if(v[rowstart][costart] == v[rowstart+1][costart]) return v[rowstart][costart];
        if(v[rowstart+1][costart] == v[rowstart][costart+1]) return v[rowstart+1][costart]; 
        return 0;
    }
    int m = n/2;
    int x1 = divide(rowstart,rowstart+m-1,costart,costart+m-1,m);
    int x2 = divide(rowstart,rowstart+m-1,costart+m,coend,m);
    int x3 = divide(rowstart+m,rowend,costart,costart+m,m);
    bool s = checkS(rowstart+m,rowend,costart+m,coend,m);
    if(!s) return 0;
    if(x1 == x2 || x1 == x3)return x1;
    if(x2 == x3) return x2;
    if(x1 == 0 || x2 == 0 || x3 == 0) return 0;
}
int main(){
    int n;
    ios_base::sync_with_stdio(false); cin.tie(0);
    for(int count =0 ; count < 3;count++){
        cin >> n;
        v.resize(n, vector<int>(n));
        for(int i =0;i<n;i++){
            for(int j = 0 ;j<n;j++){
                cin >> v[i][j];
            }
        }
        cout << divide(0,n-1,0,n-1,n) << "\n";
    }
}