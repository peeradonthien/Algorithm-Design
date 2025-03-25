#include <iostream>
#include <vector>
using namespace std;

vector<int> l, r;
vector<vector<int>> dp;
int w;

int side(int idx, int isleft) {  
    if (idx == 0) return isleft ? l[0] : r[0];
    if (idx < 0) return 0;
    
    if (dp[idx][isleft] != -1) return dp[idx][isleft];

    int r1 = 0, r2 = 0;
    if (isleft) {
        r1 = (idx - w - 1 >= 0 ? side(idx - w - 1, false) : 0) + l[idx]; // เอา
        r2 = side(idx - 1, true); // ไม่เอา
    } else {
        r1 = (idx - w - 1 >= 0 ? side(idx - w - 1, true) : 0) + r[idx]; // เอา
        r2 = side(idx - 1, false); // ไม่เอา
    }

    return dp[idx][isleft] = max(r1, r2);
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);

    int n, k;
    cin >> n >> w >> k;
    
    l.resize(n);
    r.resize(n);
    dp.assign(n, vector<int>(2, -1)); 

    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 0; i < n; i++) cin >> r[i];

    int left = side(n - 1, true);
    int right = side(n - 1, false);

    cout << max(left, right) << endl;
}
