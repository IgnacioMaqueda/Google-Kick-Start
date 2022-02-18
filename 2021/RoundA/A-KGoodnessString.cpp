#include <bits/stdc++.h>

using namespace std;

int minimumOperations(int N, int K, string &S) {
    int goodness = 0;
    for (int i = 0; i < N / 2; ++i) {
        goodness += S[i] != S[N - i - 1];
    }
    return abs(K - goodness);
}

int main() {
    int T, N, K;
    string S;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N >> K;
        cin >> S;
        cout << "Case #" << i << ": " << minimumOperations(N, K, S) << "\n";
    }
    return 0;
}
