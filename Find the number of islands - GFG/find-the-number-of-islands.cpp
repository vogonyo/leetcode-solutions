// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int row = grid.size();
        int col = grid[0].size();
        
        int numberOfIslands = 0;
        for(int i=0; i<row; i++){
            for(int j =0; j <col; j++){
                if(grid[i][j] == '1')
                {
                    mark_current_island(grid, i, j, row, col);
                    numberOfIslands++;
                }
            }
        }
        return numberOfIslands;
    }



void mark_current_island(vector<vector<char>>& grid, int r, int c, int row, int col)
    {
        // Boundary conditions
        if(r < 0 || r >= row || c < 0 || c >= col || grid[r][c] != '1')
            return;
        
        // mark current island as visited
        grid[r][c] = '2';
        
        // mark all its neighbour visisted
        mark_current_island(grid, r-1, c, row, col); // up
        mark_current_island(grid, r+1, c, row, col); // down
        mark_current_island(grid, r, c-1, row, col); // left
        mark_current_island(grid, r, c+1, row, col); // right
        mark_current_island(grid, r-1, c-1, row, col); // left up diagonal
        mark_current_island(grid, r+1, c-1, row, col); // left down diagonal
        mark_current_island(grid, r+1, c+1, row, col); // right down diagonal
        mark_current_island(grid, r-1, c+1, row, col); // right up diagonal
        
    }
    
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends