class Solution {
public:
    int n,m;
    bool isVisited[51][51];
    int color;
    bool isValid(int x,int y,int n,int col,vector<vector<int>> m){
        if(x<0||x>=n||y<0||y>=col)
        return false;
        else if(isVisited[x][y]||m[x][y]!=color)
        return false;
        
        return true;
    }
    
    void dfs(int x,int y,int n,int col,vector<vector<int>> &m,int newColor){
        
        isVisited[x][y]=true;
        m[x][y]=newColor;
        if(isValid(x+1,y,n,col,m))
        dfs(x+1,y,n,col,m,newColor);
        
        if(isValid(x,y-1,n,col,m))
        dfs(x,y-1,n,col,m,newColor);
        
        if(isValid(x,y+1,n,col,m))
        dfs(x,y+1,n,col,m,newColor);
        
        if(isValid(x-1,y,n,col,m))
        dfs(x-1,y,n,col,m,newColor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n=image.size();
        m=image[0].size();
        color=image[sr][sc];
        memset(isVisited,false,sizeof(isVisited));
        dfs(sr,sc,n,m,image,newColor);
        
        return image;
    }
};
