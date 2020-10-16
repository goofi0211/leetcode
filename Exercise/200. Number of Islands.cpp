/*思考:
dfs應用
計算圖上的連通圖個數
只要那個點是1對他呼叫dfs並且cnt++
走過的點會被更改為'*'
cnt的值就知道有幾個連通圖
*/
class Solution {
public:
    int r,c;
    int ax[4]={0,0,1,-1};
    int ay[4]={1,-1,0,0};
    int numIslands(vector<vector<char>>& grid) {
        r=grid.size();
        if(r==0)return 0;
        c=grid[0].size();
        int cnt=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    grid[i][j]='*';
                    dfs(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    void dfs(vector<vector<char>>& grid,int i,int j){
        for(int k=0;k<4;k++){
            int nx=i+ax[k],ny=j+ay[k];
            if(nx<0||nx>=r||ny<0||ny>=c||grid[nx][ny]=='0'||grid[nx][ny]=='*')continue;
            grid[nx][ny]='*'; 
            dfs(grid,nx,ny);
        }
    }
};