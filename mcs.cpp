#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    int sum = 0;
    int ask;
    int max = -1000000;
    for(int i =0;i<n;i++){
        cin >> ask;
        if(ask > max) max = ask;
        if(sum+ask >=0){
          sum+=ask;
          max = std::max(sum,max);
        }
        else{
          sum = 0;
        }
    }
    cout << max << endl;
}