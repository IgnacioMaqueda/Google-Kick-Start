#include <bits/stdc++.h>

using namespace std;

int lengthLongestSubarray(int N, vector<int> &A) {
    int res = 0;
    int difference = A[1] - A[0];
    int currentLength = 2;
    for (int i = 2; i < N; ++i) {
        if (A[i - 1] + difference == A[i]) {
            currentLength++;
        } else {
            res = max(res, currentLength);
            difference = A[i] - A[i - 1];
            currentLength = 2;
        }
    }
    return max(res, currentLength);
}

int main() {
    int T, N;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N;
        vector<int> A(N);
        for (int j = 0; j < N; ++j) {
            cin >> A[j];
        }
        cout << "Case #" << i << ": " << lengthLongestSubarray(N, A) << "\n";
    }
    return 0;
}
