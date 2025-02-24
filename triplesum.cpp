#include <iostream>
#include <vector>
using namespace std;
bool brute(int index , int count ,int total , int ask ,int n , vector<int> &data){
    if(count == 3){
        return total == ask;
    }
    if(index >= n) return false;    
    if(brute(index+1,count+1,total+data[index],ask,n,data)) return true;
    if(brute(index+1,count,total,ask,n,data)) return true;
    return false;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> data(n);
    for(int i =0;i<n;i++){
        cin >> data[i];
    }
    int ask;
    for(int i =0;i<m;i++){
        cin >> ask;
        if(brute(0,0,0,ask,n,data)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }
    
}
    