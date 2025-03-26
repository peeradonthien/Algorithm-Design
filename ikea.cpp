#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,e;
    cin >> n >> e;
    vector<pair<int,int>> ed(e);
    int v1,v2;
    for(int i =0;i<e;i++){
        cin >> v1 >> v2;
        ed.push_back(make_pair(v1,v2));
    }
    int x;
    for(int i = 0;i<5;i++){
        bool check=false;
        vector<int> pos(n+1);
        for(int j =0;j<n;j++){
            cin >> x;
            pos[x] = j;
        }

        //check
        for(auto&k : ed){
            if(pos[k.first] > pos[k.second]){
                check = true;
            }
        }

        if(check){
            cout << "FAIL" << endl;
        }
        else{
            cout << "SUCCESS" << endl;
        }
    }
    
}