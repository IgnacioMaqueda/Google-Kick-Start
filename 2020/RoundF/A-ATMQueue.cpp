#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, N, X, Ai;
    pair<int, int> AiP;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> X;
        queue<pair<int, int> > A;
        for (int i = 1; i <= N; ++i) {
            cin >> Ai;
            A.push({Ai, i});
        }
        cout << "Case #" << t << ": ";
        while (not A.empty()) {
            AiP = A.front();
            A.pop();
            AiP.first -= X;
            if (AiP.first <= 0) {
                cout << AiP.second << " ";
            } else {
                A.push(AiP);
            }
        }
        cout << "\n";
    }
    return 0;
}
