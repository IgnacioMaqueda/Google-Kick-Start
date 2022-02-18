#include <bits/stdc++.h>

using namespace std;

vector<int> getHIndexScore(int N, vector<int> &C) {
    vector<int> res(N);
    int k = 1;
    priority_queue<int, vector<int>, greater<>> actuales;
    actuales.push(C[0]);
    res[0] = k;
    for (int i = 1; i < N; ++i) {
        if (C[i] > k) {
            actuales.push(C[i]);
            if (actuales.top() > k) {
                ++k;
            } else {
                actuales.pop();
            }
        }
        res[i] = k;
    }
    return res;
}

int main() {
    int T, N;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        vector<int> C(N);
        for (int i = 0; i < N; ++i) {
            cin >> C[i];
        }
        vector<int> answer = getHIndexScore(N, C);
        cout << "Case #" << t << ": ";
        for (int i = 0; i < N; ++i) {
            cout << answer[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
