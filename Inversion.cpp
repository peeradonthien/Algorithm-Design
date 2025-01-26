#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &v,int start , int m , int stop , vector<int> &tmp , int &ans){
    int li = start;
    int ri = m+1;
    for(int i = start;i<= stop;i++){
        if(ri > stop){ // right empty
            tmp[i] = v[li];
            li++;
            continue;
        }
        if(li > m){ //left empty
            tmp[i] = v[ri];
            ri++;
            continue;
        }
        if(v[li] <= v[ri]){
            tmp[i] = v[li];
            li++;
        }
        else{
            tmp[i] = v[ri];
            ri++;
            ans+= m-li+1; // ตัวที่เหลือของครึ่งเเรกทั้ง้หมดมากกว่าตัวเเรกของกล่องหลังเเน่
        }
    }
    for(int i = start;i<=stop;i++){
        v[i] = tmp[i];
    }
}
void inversion(vector<int> &v,int start , int stop,vector<int> &tmp ,int &ans){
    if(start >= stop) return;
    if(start < stop){
        int m = (start+stop) >> 1;
        inversion(v,start,m,tmp,ans);
        inversion(v,m+1,stop,tmp,ans);
        merge(v,start,m,stop,tmp,ans);
    }
}

int main(){
    int n,in;
    cin >> n;
    vector<int> v(n) , tmp(n);
    int ans = 0;
    for(int i=0;i<n;i++){
        cin >> in;
        v[i] = in;
    }
    inversion(v,0,n-1,tmp,ans);
    cout << ans << endl;
    /*
    for(auto &x : v){
        cout << x << " ";
    }
    cout << endl;
    return 0;
    */
    

}