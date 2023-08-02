#include <iostream>
using namespace std;
const int N = 4;
bool isSafe(int row, int col, bool cell[N][N], bool rowflag[N], bool colflag[N], bool pdiagflag[2*N-1], bool sdiagflag[2*N-1]) {
    return !rowflag[row] && !colflag[col] && !pdiagflag[row + col] && !sdiagflag[N - 1 + row - col];
}
bool tryQueen(int col,bool cell[N][N],bool colflag[],bool rowflag[][], int pdiagflag, int sdiagflag){
 if (col >= N)
        return true;

    for (int row = 0; row < N; row++) {
        if (isSafe(row, col, cell, rowflag, colflag, pdiagflag, sdiagflag)) {
            cell[row][col] = true;
            rowflag[row] = true;
            colflag[col] = true;
            pdiagflag[row + col] = true;
            sdiagflag[N - 1 + row - col] = true;

            if (tryQueenUtil(col + 1, cell, rowflag, colflag, pdiagflag, sdiagflag))
                return true;

            cell[row][col] = false;
            rowflag[row] = false;
            colflag[col] = false;
            pdiagflag[row + col] = false;
            sdiagflag[N - 1 + row - col] = false;
        }
    }

    return false;
}

int main()
{
    bool cell[N][N] = {false};
    bool rowflag[N] = {false}; 
    bool colflag[N] = {false}; 
    bool pdiagflag[2*N-1] = {false}; 
    bool sdiagflag[2*N-1] = {false};
    cout<<tryQueen(0,cell,colflag,rowflag,pdiagflag,sdiagflag);
    
}