#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

ull calculateMinDifficulty(ull K, priority_queue<ull> &difficulties) {
    ull top, newD1, newD2;
    for (int i = 0; i < K; ++i) {
        top = difficulties.top();
        difficulties.pop();
        newD1 = top / 2;
        newD2 = top - newD1;
        difficulties.push(newD1);
        difficulties.push(newD2);
    }
    return difficulties.top();
}

int main() {
    int T, N, K;
    ull Mj, M0, minDifficulty;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N >> K >> M0;
        priority_queue<ull> difficulties;
        for (int j = 1; j < N; ++j) {
            cin >> Mj;
            difficulties.push(Mj - M0);
            M0 = Mj;
        }
        minDifficulty = calculateMinDifficulty(K, difficulties);
        cout << "Case #" << i << ": " << minDifficulty << "\n";
    }
    return 0;
}
