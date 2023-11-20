class Solution {
    // Function to check if a row is valid
    static bool isValidRow(vector<char>& row){
        int checker = 0, num;
        // Iterate through each element in the row
        for(int i = 0; i < 9; i++){
            if(row[i] != '.'){
                // Convert the character to an integer
                num = row[i] - '0';
                // Check if the bit corresponding to the num is already set
                if((checker & (1 << num)) > 0)
                    return false; // If set, the row is not valid
                // Set the bit corresponding to the num
                checker = (checker | (1 << num));
            }
        }
        return true; // If all elements are valid, the row is valid
    };

    // Function to check if a column is valid
    static bool isValidColumn(vector<vector<char>>& board, int j){
        int checker = 0, num;
        // Iterate through each element in the column
        for(int i = 0; i < 9; i++){
            if(board[i][j] != '.'){
                // Convert the character to an integer
                num = board[i][j] - '0';
                // Check if the bit corresponding to the num is already set
                if((checker & (1 << num)) > 0)
                    return false; // If set, the column is not valid
                // Set the bit corresponding to the num
                checker = (checker | (1 << num));
            }
        }
        return true; // If all elements are valid, the column is valid
    };

    // Function to check if a 3x3 cell is valid
    static bool isValidCell(vector<vector<char>>& board, int n, int m){
        int checker = 0, num;
        // Iterate through each element in the 3x3 cell
        for(int i = n; i < n + 3; i++){
            for(int j = m; j < m + 3; j++){
                if(board[i][j] != '.'){
                    // Convert the character to an integer
                    num = board[i][j] - '0';
                    // Check if the bit corresponding to the num is already set
                    if((checker & (1 << num)) > 0)
                        return false; // If set, the cell is not valid
                    // Set the bit corresponding to the num
                    checker = (checker | (1 << num));
                }
            }
        }
        return true; // If all elements are valid, the cell is valid
    };

public:
    // Function to check if the entire Sudoku board is valid
    bool isValidSudoku(vector<vector<char>>& board) {
        int i;
        // Check each row
        for(i = 0; i < 9; i++){
            if(!isValidRow(board[i])){
                return false; // If any row is not valid, the board is not valid
            }
        }
        // Check each column
        for(i = 0; i < 9; i++){
            if(!isValidColumn(board, i)){
                return false; // If any column is not valid, the board is not valid
            }
        }
        // Check each 3x3 cell
        for(i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                if(!isValidCell(board, i, j)){
                    return false; // If any cell is not valid, the board is not valid
                }
            }
        }
        return true; // If all rows, columns, and cells are valid, the board is valid
    }
};
