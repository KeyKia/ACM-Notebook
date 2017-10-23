int mat[MAX_N][MAX_N],R,C;

void swap(int row1, int row2,int col) {
    for (int i = 0; i < col; i++) {
        int temp = mat[row1][i];
        mat[row1][i] = mat[row2][i];
        mat[row2][i] = temp;
    }
}

int rankOfMatrix() {
    int rank = C; 
    for (int row = 0; row < rank; row++) {
        if (mat[row][row]) {
           for (int col = 0; col < R; col++) {
               if (col != row) {
                 double mult = (double)mat[col][row] /
                                       mat[row][row];
                 for (int i = 0; i < rank; i++)
                   mat[col][i] -= mult * mat[row][i];
              }
           }
        }
        else {
            bool reduce = true;
            for (int i = row + 1; i < R;  i++) {
                if (mat[i][row]) {
                    swap(row, i, rank);
                    reduce = false;
                    break ;
                }
            }
            if (reduce) {
                rank--;
                for (int i = 0; i < R; i ++)
                    mat[i][row] = mat[i][rank];
            }
            row--;
        }
    }
    return rank;
}