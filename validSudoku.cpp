class Solution {
private:
    inline void clear(vector<bool>& visited) {
        for(int i=0;i<visited.size();i++) {
            visited[i]=false;
        }
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows=board.size();
        int cols=board[0].size();
        if(rows==0) {
            return true;
        }
        vector<bool> visited(10, false);
        // Traverse column by column
        for(int i=0;i<cols;i++) {
            for(int j=0;j<rows;j++) {
                if(board[j][i]!='.') {
                    if(visited[board[j][i]-'0']) {
                        return false;
                    }
                    else {
                        visited[board[j][i]-'0']=true;
                    }
                }
            }
            clear(visited);
        }
        // Traverse row by row
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(board[i][j]!='.') {
                    if(visited[board[i][j]-'0']) {
                        return false;
                    }
                    else {
                        visited[board[i][j]-'0']=true;
                    }
                }
            }
            clear(visited);
        }
        vector<bool> visited2(10, false);
        vector<bool> visited3(10, false);
        vector<bool> *ref;
        for(int i=0;i<rows;) {
            for(int j=0;j<cols;j++) {
                if(j<3)
                    ref=&visited;
                else if(j<6)
                    ref=&visited2;
                else 
                    ref=&visited3;
                if(board[i][j]!='.') {
                    if((*ref)[board[i][j]-'0']) {
                        cout<<i<<'\t'<<j<<endl;
                        return false;
                    }
                    else {
                       (*ref)[board[i][j]-'0']=true; 
                    }
                }
            }
            i++;
            if(i%3==0) {
                clear(visited);
                clear(visited2);
                clear(visited3);
            }
        }
        return true;
    }
};