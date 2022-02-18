#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, N, M, C, Ci;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> M;
        C = 0;
        for (int i = 0; i < N; ++i) {
            cin >> Ci;
            C += Ci;
        }
        cout << "Case #" << t << ": " << C % M << "\n";
    }
    return 0;
}
