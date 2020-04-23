#include <bits/stdc++.h>

using namespace std;

int numberOfPeaks(vector<int> &H, const int N) {
    int res = 0;
    for (int i = 1; i < N - 1; ++i) {
        if (H[i] > H[i - 1] and H[i] > H[i + 1]) {
            res++;
        }
    }
    return res;
}

int main() {
    int T, N;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        vector<int> H(N);
        for (int i = 0; i < N; ++i) {
            cin >> H[i];
        }
        cout << "Case #" << t << ": " << numberOfPeaks(H, N) << "\n";
    }
}
