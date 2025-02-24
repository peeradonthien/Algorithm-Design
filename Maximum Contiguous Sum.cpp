#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int getsum(vector<int> &sum , int a ,int b){
    return sum[b]-sum[a-1];
}
int mss(vector<int> &a , int start , int stop , vector<int> &sum){
    if(start == stop) return a[start];
    int m = (start+stop)/2;
    int r1 = mss(a,start,m,sum);
    int r2 = mss(a,m+1,stop,sum);
    int maxsumleft = -1e9, maxsumright = -1e9;
    for(int i = start;i<=m-1;i++){
        maxsumleft = max(maxsumleft,getsum(sum,i,m));
    }
    for(int i = m+2;i<=stop;i++){
        maxsumright = max(maxsumright,getsum(sum,m+1,i));
    }
    int r3 = maxsumleft + maxsumright;
    return max(max(r1,r2),r3);

}
int main(){
    int n;
    cin >> n;
    int sum = 0;
    vector<int> sumv(n+1);
    sumv[0] = 0;
    vector<int> a(n);
    int ask;
    for(int i =1;i<=n;i++){
        cin >> ask;
        sum+=ask;
        sumv[i]=sum;
        a[i-1] = ask;
    }
    cout << mss(a,0,n-1,sumv);
    
}