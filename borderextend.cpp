#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int r, c, k;
    cin >> r >> c >> k;
    vector<vector<int>> v(r, vector<int>(c));
    int offset[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> visited(r, vector<int>(c, false));

    // รับ input และเก็บจุดที่เป็น 1 ลงใน queue (เริ่ม BFS จากทุกจุด)
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
            if (v[i][j] == 1) {
                q.push({{i, j}, 0}); // ใส่ค่าเริ่มต้นของ BFS
                visited[i][j] = true;
            }
        }
    }
    vector<vector<int>> temp = v;

    // ทำ BFS จากทุกจุดที่เป็น 1 พร้อมกัน
    while (!q.empty()) {
        auto a = q.front();
        q.pop();

        if (a.second >= k) continue; // ถ้า depth เกิน k ให้ข้าม

        for (int i = 0; i < 4; i++) {
            int rr = a.first.first + offset[i][0];
            int cc = a.first.second + offset[i][1];

            if (rr < 0 || rr >= r || cc < 0 || cc >= c) continue; // ขอบเขตของตาราง
            if (visited[rr][cc]) continue; // ถ้าเคยไปแล้วข้าม

            if (temp[rr][cc] == 0) {
                temp[rr][cc] = 2;
                visited[rr][cc] = true;
                q.push({{rr, cc}, a.second + 1}); // เพิ่มเข้า queue พร้อม depth ใหม่
            }
        }
    }

    // แสดงผลลัพธ์
    for (auto &x : temp) {
        for (auto &y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}
