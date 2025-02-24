#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int> &v, int n) {
    int max_sum = v[0];
    int current_sum = v[0];

    for (int i = 1; i < n; i++) {
        current_sum = max(v[i], current_sum + v[i]);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << maxSubarraySum(v, n) << endl;
}
