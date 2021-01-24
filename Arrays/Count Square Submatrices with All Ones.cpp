class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0||j==0||matrix[i][j]==0)
                    continue;
                int min_num=min(min(matrix[i-1][j-1],matrix[i-1][j]),matrix[i][j-1]);
                matrix[i][j]+=min_num;
            }
        }
        int count=0;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
            count+=matrix[i][j];
        
        return count;
    }
};
