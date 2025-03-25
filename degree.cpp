#include <iostream>
#include <vector>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,x;
    cin >> n;
    vector<int> data(n+1);
    int maxdegree = 0;
    for(int i = 0 ; i<n;i++){
        int count = 0;
        for(int j=0;j<n;j++){
            cin >> x;
            if(x == 1) count++;
        }
        data[count]++;
        maxdegree = max(maxdegree,count);
    }
    for(int i =0;i<=maxdegree;i++){
        cout << data[i] << " ";
    }
    cout << "\n";
}