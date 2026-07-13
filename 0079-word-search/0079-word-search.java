class Solution {
    public boolean exist(char[][] board, String word) {
        int m = board.length;
        int n = board[0].length;

        for(int i = 0; i < m; i++){
          for(int j = 0; j < n; j++){
            if(board[i][j] == word.charAt(0)){
              if(dfs(board, word, 0, i, j)) {
                return true;
              }
            }
          }
        }
        return false;
    }

    private boolean dfs(char[][] b, String word, int start, int row, int col){
      if(word.length() <= start){
        return true;
      }

      if(row < 0 || col < 0 || row >= b.length || col >= b[0].length ||
        b[row][col] == '#' || b[row][col] != word.charAt(start)) {
          return false;
      }

      char temp = b[row][col];
      b[row][col] = '#';

      if(dfs(b, word, start + 1, row+1, col) ||
        dfs(b, word, start + 1, row-1, col) ||
        dfs(b, word, start + 1, row, col+1) ||
        dfs(b, word, start + 1, row, col-1)) {
          return true;
      }

      b[row][col] = temp;
      return false;
    }
}