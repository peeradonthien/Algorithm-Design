#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end());
    int left = v[0].first;
    int right = v[0].second;
    for(int i =1;i<n;i++){
        if(right+1 >= v[i].first){   //(1,4) (2,7) --> 1,7
            right = max(right,v[i].second);
        }
        else{ // (1,7) (8,11) --> print (1,7) and set (8,11)
            cout << left << " " << right << " ";
            left = v[i].first;
            right = v[i].second;
        }
    }
    cout << left << " " << right << " ";
}