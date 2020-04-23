#include <bits/stdc++.h>

using namespace std;
const int size = 1000000000;

int processInstruction(const string &program, int i0, pair<int, int> &position, int times) {
    int i = i0;
    while (i < program.size() and program[i] != ')') {
        if (program[i] == 'S') {
            position.second += times;
        } else if (program[i] == 'N') {
            position.second -= times;
        } else if (program[i] == 'E') {
            position.first += times;
        } else if (program[i] == 'W') {
            position.first -= times;
        } else if (program[i] >= '2' and program[i] <= '9') {
            i = processInstruction(program, i + 2, position, times * (program[i] - '0'));
        }
        i++;
    }
    return i;
}

pair<int, int> finalPosition(const string &program) {
    pair<int, int> position = {1,1};
    processInstruction(program, 0, position, 1);
    if (position.first <= 0) {
        position.first += size;
    }
    if (position.second <= 0) {
        position.second += size;
    }
    return position;
}

int main() {
    int T;
    string program;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> program;
        pair<int, int> position = finalPosition(program);
        cout << "Case #" << t << ": " << position.first << " " << position.second << "\n";
    }
}
