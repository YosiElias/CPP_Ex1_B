#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;
namespace ariel{

//Checks legality of the input:
void checkingLegality(int col, int row, char a, char b){
    const int MIN = 33; //min legality value char 
    const int MAX = 126; //max legality value char 

    if ((col * row) % 2 == 0){
        throw invalid_argument("Number of rows or colmns is even");
    }
    if (col < 1 || row < 1){
        throw invalid_argument("Number of rows or colmns is negative or 0");
    }
    if (a < MIN || a > MAX || b < MIN || b > MAX ){
         throw invalid_argument("Chars are not legal");
    }
}

//Convert mat to string:
string convert2string(const vector<vector<string> > & mat, const int & col, const int & row){
    string finaAns;
    for ( int i = 0 ; i < row ; i++ ){
        for ( int j = 0 ; j < col ; j++ ){
           finaAns += mat[i][j];
        }
        finaAns += '\n';
    }
    return finaAns;
}

//Main function:
string mat(int col, int row, char a, char b) {
    checkingLegality(col, row, a, b);
    //Initializes a matrix:
    vector<vector<string> > ans(row);
    for (int i = 0; i < row; i++) {
        ans[i].resize(col);
    }
   
    if (row==1) {
        for (int i = 0; i < col; i++) {
            ans.at(0).at(i) = a;
            ans.at(0).at(col -i -1) = a;
        }
    } else {
        if (col == 1) {
            for (int i = 0; i < row; i++) {
                ans.at(i).at(0) = a;
                ans.at(row - i - 1).at(0) = a;
            }
        } else {
            bool isA = true;
            int gap = 0;
            while (gap <= (col / 2) && gap <= (row / 2)) {
                for (int i = 0; i < col - (2 * gap); i++) {
                    if (isA) {
                        ans.at(gap).at(i + gap) = a;
                        ans.at(row - gap - 1).at(i + gap) = a;
                    } else {
                        ans.at(gap).at(i + gap) = b;
                        ans.at(row - gap - 1).at(i + gap) = b;
                    }
                }
                for (int i = 0; i < row - (2 * gap); i++) {
                    if (isA) {
                        ans.at(gap + i).at(gap) = a;
                        ans.at(gap + i).at(col - gap - 1) = a;
                    } else {
                        ans.at(gap + i).at(gap) = b;
                        ans.at(gap + i).at(col - gap - 1) = b;
                    }
                }
                isA = !isA;
                gap = gap + 1;
            }
        }
    }

    //convert to string:
    string finaAns = convert2string(ans, col, row);

    return finaAns;
}
}


