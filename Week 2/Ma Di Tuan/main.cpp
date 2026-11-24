#include <bits/stdc++.h>

using namespace std;

int N, startX , startY ;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int board[1001][1001];

bool isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == 0);
}

int countDegree(int x, int y) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (isValid(x + dx[i], y + dy[i])) {
            count++;
        }
    }
    return count;
}

struct Move {
    int x, y, degree;
};

bool compareMoves(const Move &a, const Move &b) {
    return a.degree < b.degree;
}

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(3) << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool solveKnightTourWarnsdorff(int x, int y, int step) {
    if (step == N * N) return true;
    vector<Move> nextMoves;
    for (int i = 0; i < 8; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (isValid(nextX, nextY)) {
            nextMoves.push_back({nextX, nextY, countDegree(nextX, nextY)});
        }
    }
    sort(nextMoves.begin(), nextMoves.end(), compareMoves);

    for (const auto &move : nextMoves) {
        board[move.x][move.y] = step + 1;

        if (solveKnightTourWarnsdorff(move.x, move.y, step + 1)) {
            return true;
        }

        board[move.x][move.y] = 0; // Quay lui
    }

    return false;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> startX >> startY;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    board[startX][startY] = 1;

    if (solveKnightTourWarnsdorff(startX, startY, 1)) {
        printBoard();
    } else {
        cout << "-1" <<'\n';
    }

    return 0;
}