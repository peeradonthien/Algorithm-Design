#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int distance(int x1,int y1 , int x2, int y2){
    return pow((x1-x2),2) + pow((y1-y2),2);
}
int closetpair(){

}
int main(){
    int n,x,y;
    cin >> n;
    vector<pair<int,int>> vx(n) , vy(n);
    for(int i =0;i<n;i++){
        cin >> x >> y;
        vx[i] = make_pair(x,y);
        vy[i] = make_pair(y,x);
    }
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());

    pair<int,int> result = make_pair(vx[0].first , vy[0].first);
    int min = distance()

}