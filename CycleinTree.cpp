#include <iostream>
#include <vector>
using namespace std;
int ans = 0;
void dfs(int a , vector<bool> &visited , vector<vector<int>> &adj , int parent , vector<int> &sequence,int depth){
    visited[a] = true;
    sequence[a] = depth;
    for(auto&x : adj[a]){
        if(!visited[x]){ //ยังไม่เคยไป ให้ไปเรื่อยๆ
            dfs(x,visited,adj,a,sequence,depth+1);
        }
        else{
            if(x != parent){
                if(ans == 0){
                    ans = sequence[a]-sequence[x]+1; //หาlength ของcycle เจอเเล้วคือจบเลย 
                }
                return;
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    int v1,v2;
    for(int i =0;i<n;i++){
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    vector<bool> visited(n,false);
    vector<int> sequence(n,-1);
    dfs(0,visited,adj,-1,sequence,0);
    cout << ans << endl;
   
    
     
}