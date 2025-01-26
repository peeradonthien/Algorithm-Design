#include <iostream>
#include <vector>
using namespace std;
void perm(int n, vector<string> &sol , int len,vector<bool> &used,vector<string> &ans , vector<char> &charac , int total){
    int pos = 0;
    if(len < n){
        for(int i = 0;i<total;i++){
            if(used[i] == false){
                used[i] = true;
                sol[len] = charac[i];
                perm(n,sol,len+1,used,ans,charac,total);
                used[i] = false;
            }
        }
    }
    else{
        string kum = "";
        for(auto &x :sol){
            kum += x;
        }
        ans.push_back(kum);
    }
}

int main(){
    int n,i,j,k;
    cin >> n >> i >> j >> k;
    vector<bool> used(i+j+k,false);
    vector<string> sol(n,"");
    vector<string> ans;
    vector<char> charac(i+j+k);
    for(int z = 0;z<i;z++){
        charac[z] = 'A';
    }
    for(int z = i;z<i+j;z++){
        charac[z] = 'B';
    }
    for(int z = i+j;z<i+j+k;z++){
        charac[z] = 'C';
    }
    perm(n,sol,0,used,ans,charac, i+j+k);
    cout << ans.size() << endl;
    for(auto &x : ans){
        cout << x << endl;
    }
}

