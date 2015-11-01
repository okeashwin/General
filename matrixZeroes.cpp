class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rowsZeroed;
        vector<int> columnsZeroed;
        int rows = matrix.size();
        int columns = matrix[0].size();
        
        cout << "rows : "<< rows << '\t' << "columns : " << columns << endl;
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                if(matrix[i][j]==0)
                {
                    rowsZeroed.push_back(i);
                    columnsZeroed.push_back(j);
                    // cout << i << '\t' << j << endl;
                }
            }
        }
        
        for(int i=0;i<rowsZeroed.size();i++)
        {
            for(int j=0;j<columns;j++)
                matrix[rowsZeroed[i]][j] = 0;
        }
        
        for(int i=0;i<columnsZeroed.size();i++)
        {
            for(int j=0;j<rows;j++)
                matrix[j][columnsZeroed[i]] = 0;
        }
    }
};