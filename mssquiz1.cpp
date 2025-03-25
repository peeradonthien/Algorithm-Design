#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i =0;i<n;i++){
        cin >> v[i];
    }
    if(n==1){
        cout << v[0] << endl;
        return 0;
    }
    int currentsum = v[0];
    int maxsum1 = v[0];
    int currentsum2 = v[1];
    int maxsum2 = v[1];
    currentsum  = currentsum - v[1];
    maxsum1 = max(maxsum1,currentsum);
    for(int i =2;i<n;i++){
        if(i%2!=0){
            currentsum = currentsum-v[i];
            currentsum2 = max(v[i],currentsum2+v[i]);
        }
        else{
            currentsum = max(v[i],currentsum+v[i]);
            currentsum2 = currentsum2-v[i];
        }
        maxsum1 = max(maxsum1,currentsum);
        maxsum2 = max(maxsum2,currentsum2);
    }
    cout << max(maxsum1,maxsum2) << endl;
}