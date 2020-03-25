#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

int main() {
    int T, N;
    ull A, B, C;
    bool guessed;
    string answer;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> A >> B;
        cin >> N;
        guessed = false;
        while (not guessed) {
            C = (A + B + 1) / 2;
            cout << C << endl;
            cin >> answer;
            if (answer == "CORRECT") {
                guessed = true;
            } else if (answer == "TOO_SMALL") {
                A = C;
            } else {
                B = C;
            }
        }
    }
    return 0;
}
