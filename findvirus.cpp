#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool checkVirus(int start, int end, vector<int> &data) {
    if (start + 1 == end) { //เหลือ 2 
        return data[start] == 0 && data[end] == 1;
    }
    int mid = (start + end) / 2;
    bool rightValid = checkVirus(mid + 1, end, data);
   // cout << rightValid << endl;
    if (!rightValid) return false;

    bool leftValid = checkVirus(start,mid,data);
    if(!leftValid){
        vector<int> reverse = data;
        for(int i = 0;i<mid;i++){
            reverse[i] = data[mid-i-1];
        }
        leftValid = checkVirus(0,mid-start,reverse);
    }
    return leftValid && rightValid;
}

int main() {
    int n, k;
    cin >> n >> k;
    int size = pow(2, k);  // ขนาดของอาเรย์
    vector<int> data(size);
    vector<int> datainverse(size);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < size; j++) {
            cin >> data[j];
        }
        
        if (checkVirus(0, size - 1, data)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
        
    }

    return 0;
}
