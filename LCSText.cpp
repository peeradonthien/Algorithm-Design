#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    string text1,text2;
    cin >> text1 >> text2;
    vector<vector<int>> v(n+1,vector<int>(m+1));
    for(int i =0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cin >> v[i][j];
        }
    }
    stack<char> word;
    int x = m; //5
    int y = n; // 4
    while(y!=0 && x!=0){
        if(text1[y-1] == text2[x-1]){
            word.push(text1[y-1]);
            y--;
            x--;
        }
        else{
            if(v[y-1][x] > v[y][x-1]){
                y--;
            }
            else{
                x--;
            }
        }
    }
    while(!word.empty()){
        cout << word.top();
        word.pop();
    }
    cout << endl;


}