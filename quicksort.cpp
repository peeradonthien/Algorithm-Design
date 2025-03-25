#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int partition(int start , int stop){
    int pivot = v[start];
    int left = start-1;
    int right = stop+1;
    while(left < right){
        while(v[left] < pivot){
            left ++;
        }
        while(v[right] > pivot){
            right --;
        }
        if(left < right){
            swap(v[left],v[right]);
        }
        else {
            return right;
        }
    }
    return right;
}
void quicksort(int start , int stop){
    if(start >= stop) return;
    int p = partition(start , stop);
    quicksort(start,p);
    quicksort(p+1,stop);
}
int main(){
    int n;
    cin >> n;
    v.resize(n);
    for(int i =0;i<n;i++){
        cin >> v[i];
    }
    quicksort(0,n-1);
    for(auto &x : v){
        cout << x << " ";
    }
    cout << endl;
}
