class Solution {
    public boolean isValidSudoku(char[][] board) {
         Set<Character> rows = null;
         Set<Character> cols = null;

         // check rows and colums:
         for(int i = 0; i< 9; i++){
             rows = new HashSet<>();
             cols = new HashSet<>();
             for(int j = 0; j<9; j++){
                if(board[i][j] != '.' && !rows.add(board[i][j]))
                    return false;
                if(board[j][i] != '.' && !cols.add(board[j][i]))
                    return false;
             }

         }

         // check boxes by iterating thru board again
         for(int i = 0; i<9; i +=3){// +3 to jump in each box
            for(int j = 0; j<9; j +=3){
                if(!checkBox(i, j, board))//check if dupes in boxes
                    return false;
            }

         }
         
         return true;
    }


    //help for checking boxes
    public boolean checkBox(int idxI, int idxJ, char[][] board){
        Set<Character> boxes = new HashSet<>();

        int rows = idxI + 3;
        int cols = idxJ + 3;

        for(int i = idxI; i < rows; i++){
            for(int j = idxJ; j < cols; j++){
                if(board[i][j] == '.')
                    continue;
                
                if(boxes.contains(board[i][j]))
                    return false;

                boxes.add(board[i][j]);
            }
        }

        return true; // if no dupes
    }
}
