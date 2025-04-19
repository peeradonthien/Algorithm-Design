#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int d,e,l;
    vector<vector<int>> v(k,vector<int>(3));
    for(int i =0;i<k;i++){
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    sort(v.begin(),v.end());
    queue<int> plant;
    queue<int> store;
    for(int i =0;i<k;i++){
        if(v[i][1] == 0){
            if(store.empty()) { //ไม่มีร้านไหนขอ
                plant.push(v[i][2]); //stock
                cout << 0 << endl;
            }
            else{
                cout << store.front() << endl;
                store.pop();
            }
        }
        else{
            if(plant.empty()){
                store.push(v[i][2]);
                cout << 0 << endl;
            }
            else{
                cout << plant.front() << endl;
                plant.pop();
            }
        }
    }
}