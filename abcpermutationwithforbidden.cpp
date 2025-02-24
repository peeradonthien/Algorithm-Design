#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;
int n,i,j,k,total,amount;
vector<bool> used;
vector<char> charac;
set<string> ans;
map<char,vector<char>> m;
vector<int> cannotuse(3,0);
void perm(vector<string> &sol, int len) {
    if (len < n) {
        for (int x = 0; x < total; x++) {
            if (!used[x]) {
                if (x > 0 && charac[x] == charac[x - 1] && !used[x - 1]) continue;

                if(m.find(charac[x]) != m.end()){
                    string thisone = "";
                    //convert char to string
                    if(m[charac[x]].size() == 1) thisone += m[charac[x]][0]; 
                    vector<char> v = m[charac[x]];
                    if(len > 0){
                        char before = sol[len-1][0];
                        auto it = find(v.begin(),v.end(),before);
                        if(it != v.end()) continue; 
                    }
                }
                used[x] = true;
                sol[len] = charac[x];
                perm(sol, len + 1);
                used[x] = false;
            }
        }
    } else {
        string kum = "";
        for (auto &x : sol) {
            kum += x;
        }
        ans.insert(kum); 
    }
}

int main() {
    cin >> n >> i >> j >> k;
    cin >> amount;
    string x;
    for(int z = 0;z<amount;z++){
        cin >> x;
        m[x[1]].push_back(x[0]);

    }
    total = i+j+k;
    for (int z = 0; z < i; z++) charac.push_back('A');
    for (int z = 0; z < j; z++) charac.push_back('B');
    for (int z = 0; z < k; z++) charac.push_back('C');
    used.resize(total);
    vector<string> sol(n, "");
    perm(sol, 0);
    cout << ans.size() << endl;
    for (const auto &x : ans) {
        cout << x << endl;
    }
}
