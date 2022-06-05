#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> grid; 
        // 1 : walled
        // -1 : unguarded
        // 2 left / right guarded
        // 3 up / down guarded
    int M, N;
public:
    void moveLeft(int r, int c)
    {
        if(c < 0)
            return;
        if(grid[r][c] == 1)
            return;
        if(grid[r][c] == 2)
            return;
        grid[r][c] = 2;
        moveLeft(r, c-1);
    }
    
    void moveRight(int r, int c)
    {
        if(c >= N)
            return;
        if(grid[r][c] == 1)
            return;
        if(grid[r][c] == 2)
            return;
        grid[r][c] = 2;
        moveRight(r, c+1);
    }
    
    void moveUp(int r, int c)
    {
        if(r < 0)
            return;
         if(grid[r][c] == 1)
            return;
        if(grid[r][c] == 3)
            return;
        grid[r][c] = 3;
        moveUp(r-1, c);
    }
    
    void moveDown(int r, int c)
    {
        if(r >= M)
            return;
         if(grid[r][c] == 1)
            return;
        if(grid[r][c] == 3)
            return;
        grid[r][c] = 3;
        moveDown(r+1, c);
    }
    
    int countUnguarded(int m, int n, std::vector<std::vector<int>>& guards, std::vector<std::vector<int>>& walls) {
        int i, j;
        M = m;
        N = n;
        std::vector<int> temp;
        for(i = 0; i < n; i++)
            temp.push_back(-1);
        
        for(i = 0; i < m; i++)
            grid.push_back(temp);
        
        for(i = 0; i < walls.size(); i++)
            grid[walls[i][0]][walls[i][1]] = 1;
        
        for(i = 0; i < guards.size(); i++)
        {
            moveLeft(guards[i][0], guards[i][1]);
            moveRight(guards[i][0], guards[i][1]+1);
        }
        
        for(i = 0; i < guards.size(); i++)
        {
            moveUp(guards[i][0], guards[i][1]);
            moveDown(guards[i][0]+1, guards[i][1]);
        }
        
        int ans = 0;;
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
                if(grid[i][j] == -1)
                    ans++;
        return ans;
    }
};