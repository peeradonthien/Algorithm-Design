#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> a;
vector<vector<int>> table;  // Memoization table

int mcm(int l, int r) {
    if (l >= r) return 0; // กรณีฐาน

    if (table[l][r] != -1) return table[l][r]; // คืนค่าถ้าคำนวณไปแล้ว

    int mincost = INT_MAX;
    for (int i = l; i < r; i++) {
        int mycost = mcm(l, i) + mcm(i + 1, r) + (a[l] * a[i + 1] * a[r + 1]);
        mincost = min(mycost, mincost);
    }

    return table[l][r] = mincost; // เก็บค่าไว้และคืนค่า
}

int main() {
    int n;
    cin >> n;
    
    a.resize(n + 2);
    table.resize(n + 1, vector<int>(n + 1, -1)); // ตั้งค่า -1 เพื่อใช้เป็นค่าที่ยังไม่ถูกคำนวณ

    for (int i = 1; i <= n + 1; i++) {
        cin >> a[i];
    }

    cout << mcm(1, n) << endl;
}
