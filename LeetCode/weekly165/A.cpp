// URL: https://leetcode.com/contest/weekly-contest-165/problems/find-winner-on-a-tic-tac-toe-game/
// TYPE: Ad-Hoc

class Solution {
public:

    int board[3][3] = {};

    string checkState(int player, string name) {
        // Check diagonals
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return name;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return name;

        // Check horizontal bars
        if (board[0][0] == player && board[1][0] == player && board[2][0] == player) return name;
        if (board[0][1] == player && board[1][1] == player && board[2][1] == player) return name;
        if (board[0][2] == player && board[1][2] == player && board[2][2] == player) return name;

        // Check vertical bars
        if (board[0][0] == player && board[0][1] == player && board[0][2] == player) return name;
        if (board[1][0] == player && board[1][1] == player && board[1][2] == player) return name;
        if (board[2][0] == player && board[2][1] == player && board[2][2] == player) return name;

        return "";
    }

    string tictactoe(vector<vector<int>>& moves) {
        int turn = 0;
        // X: 1
        // O: 2
        string fs = "";
        for (auto m : moves) {
            board[m[0]][m[1]] = turn + 1;
            turn += 1;
            turn %= 2;

            fs = checkState(1, "A");
            if (fs != "") {
                return fs;
            }
            fs = checkState(2, "B");
            if (fs != "") {
                return fs;
            }
        }
        if (moves.size() == 9) {
            fs = "Draw";
        } else {
            fs = "Pending";
        }

        return fs;
    }
};
