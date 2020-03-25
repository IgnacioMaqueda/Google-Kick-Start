#include <bits/stdc++.h>

using namespace std;

int calculateMaxBeautyDP(int P, int n, int k, const int N, const int K, vector<vector<int> > &plates, vector<vector<vector<int> > > &mem) {
    if (P == 0) {
        return 0;
    }
    if (k == K) {
        k = 0;
        n++;
    }
    if (n == N) {
        return 0;
    }
    if (mem[P][n][k] < 0) {
        mem[P][n][k] = max(calculateMaxBeautyDP(P - 1, n, k + 1, N, K, plates, mem) + plates[n][k], calculateMaxBeautyDP(P, n + 1, 0, N, K, plates, mem));
    }
    return mem[P][n][k];
}

int calculateMaxBeauty(int N, int K, int P, vector<vector<int> > &plates) {
    vector<vector<vector<int> > > mem(P + 1, vector<vector<int> >(N, vector<int>(K, -1)));
    return calculateMaxBeautyDP(P, 0, 0, N, K, plates, mem);
}

int main() {
    int T, N, K, P, Pjk, maxBeauty;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N >> K >> P;
        vector<vector<int> > plates(N, vector<int>(K));
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < K; ++k) {
                cin >> Pjk;
                plates[j][k] = Pjk;
            }
        }
        maxBeauty = calculateMaxBeauty(N, K, P, plates);
        cout << "Case #" << i << ": " << maxBeauty << "\n";
    }
    return 0;
}
