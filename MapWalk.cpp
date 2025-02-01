#include <iostream>
#include <vector>
using namespace std;
void walk(vector<vector<int>> &data , vector<char> &sol , int &row , int &column , int nowr , int nowc ,vector<vector<bool>> &used){
    
    if(nowr == row-1 && nowc == column-1){
        for(auto &x : sol){
            cout << x ;
        }
        cout << endl;
        return;
    }
    else{
        used[nowr][nowc] = true;
        if(nowc+1 < column && data[nowr][nowc+1] != 1 && !used[nowr][nowc + 1]){
            sol.push_back('A'); // nowr=0 nowc=0 row=2 column=3
            walk(data,sol,row,column,nowr,nowc+1,used);
            sol.pop_back();
        }
        if(nowr+1 < row && data[nowr+1][nowc] != 1 && !used[nowr+1][nowc]){
            sol.push_back('B');
            walk(data,sol,row,column,nowr+1,nowc,used);
            sol.pop_back();
        }
        if(nowr-1 >=0 && data[nowr-1][nowc] != 1 && !used[nowr-1][nowc]){
            sol.push_back('C');
            walk(data,sol,row,column,nowr-1,nowc,used);
            sol.pop_back();
        }
        used[nowr][nowc] = false;
    }
}
int main(){
    int r,c,x;
    cin >> r >>c;
    vector<vector<int>> data(r,vector<int>(c,0));
    for(int i=0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin >> data[i][j];
        }
    }
    vector<vector<bool>> used(r, vector<bool>(c, false));
    vector<char> sol; 
    walk(data,sol,r,c,0,0,used);
    cout << "DONE" << endl;

}
