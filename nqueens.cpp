#include<iostream>
using namespace std;
int board[10];
int n;
bool isSafe(int row,int col){
    for(int i=0;i<row;i++){
        if(board[i]==col||
        board[i]-i==col-row||
        board[i]+i==col+row)
        return false;
    }
    return true;
}
void printSolution() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}
bool solve(int row) {
    if (row == n) {
        printSolution();
        return true;
    }
for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            if (solve(row + 1)) 
                return true;
            board[row] = -1;
        }
    }
    return false;
}
int main() {
    cout << "Enter value of N (<=10): ";
    cin >> n;

    for (int i = 0; i < n; i++) board[i] = -1;

    if (!solve(0))
        cout << "No solution exists for N = " << n << endl;

    return 0;
}
