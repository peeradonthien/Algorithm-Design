#include <iostream>
#include <vector>
using namespace std;
vector<int> desk;
int countnum(int time){
    int total = 0;
    for(auto &x : desk){
        total += time/x;
    }
    return total;
}
int search(int start , int stop , int ask){
    if(start == stop) return start;
    int m = (start+stop)/2;
    if(countnum(m) >= ask){
        return search(start,m,ask);
    }
    else{
        return search(m+1,stop,ask);
    }
}
int main(){
    int n,a;
    cin >> n >> a;
    desk.resize(n);
    int min = INT_MAX;
    for(int i =0;i<n;i++){
        cin >> desk[i];
        if(desk[i] < min)min = desk[i];
    }
    int ask;
    for(int i =0;i<a;i++){
        cin >> ask;
        cout << search(1,(ask-1)*min , ask) << endl;
    }
}