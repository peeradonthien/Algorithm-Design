#include <iostream>
#include <vector>
using namespace std;
int main(){
    string in1 , in2;
    cin >> in1 >> in2;
    vector<vector<int>> v(in2.size()+1 , vector<int>(in1.size()+1,0));
    for(int i =1;i<=in2.size();i++){
        for(int j = 1; j<=in1.size();j++){
            if(in2[i-1] == in1[j-1]){
                v[i][j] = v[i-1][j-1]+1;
            }
            else{
                v[i][j] = max(v[i-1][j],v[i][j-1]);
            }
        }
    }
    cout << v[in2.size()][in1.size()] << endl;
    /*
    for(auto &t : v){
        for(auto &j : t){
            cout << j << " ";
        }
        cout << endl;
    }
        */
        
}