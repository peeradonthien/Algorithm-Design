#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate maximum contiguous sum (Kadane’s algorithm)
vector<int> maxContiguousSum(vector<int>& arr) {
    int n = arr.size();
    vector<int> maxSum(n);
    int best = arr[0], sum = arr[0];
    maxSum[0] = best;
    
    for (int i = 1; i < n; i++) {
        sum = max(arr[i], sum + arr[i]); // Extend or start new subarray
        best = max(best, sum);
        maxSum[i] = best; // Store best sum up to index i
    }
    
    return maxSum;
}

//มันให้เวกเตอร์ทของคำตอบทที่ดีที่สุดตั้งเเต่ 0 ถึง i
//เเต่เราต้องการหา i-n ดังนั้นเราเลยใช้ reverse

//a = [97 -4 8 76 -50 3]
//             ---------
// re = [3 -50 76 8 -4 97]  มันก็จะได้ ตัวบวกตั้งเเต่  i ถึง n
//       --------

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> A;
    int n;
    cin >> n;
    A.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Compute max contiguous sum from left to right
    vector<int> maxFromStart = maxContiguousSum(A);
 //-------------------------------------------------------------------mcs ปกติ


    // Reverse array and compute max contiguous sum from right to left
    reverse(A.begin(), A.end());
    vector<int> maxFromEnd = maxContiguousSum(A);
    reverse(maxFromEnd.begin(), maxFromEnd.end()); // Restore order

    // Find the maximum sum of two non-overlapping subarrays
    int best = maxFromStart[n - 1]; //อันนี้ช่วงเดียว เหมือนmcs ปกติ
    for (int i = 0; i < n - 1; i++) {
        best = max(best, maxFromStart[i] + maxFromEnd[i + 1]);
    }

    cout << best << endl;
    return 0;
}