#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

ull latestPossibleDay(vector<ull> &X, const int N, ull D) {
    for (int i = X.size() - 1; i >= 0; --i) {
        D = D - (D % X[i]);
    }
    return D;
}

int main() {
    int T, N;
    ull D;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> D;
        vector<ull> X(N);
        for (int i = 0; i < N; ++i) {
            cin >> X[i];
        }
        cout << "Case #" << t << ": " << latestPossibleDay(X, N, D) << "\n";
    }
}
