// https://leetcode.com/problems/number-of-islands/description/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int islands = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (grid[i][j] == '1' && !visited[i][j]) {
                    islands++;

                    vector<int> row;
                    vector<int> col;

                    row.push_back(i);
                    col.push_back(j);
                    visited[i][j] = true;

                    int k = 0;

                    while (k < row.size()) {
                        int r = row[k];
                        int c = col[k];
                        k++;

                        if (r > 0 && grid[r - 1][c] == '1'
                            && !visited[r - 1][c]) {
                            row.push_back(r - 1);
                            col.push_back(c);
                            visited[r - 1][c] = true;
                        }

                        if (r + 1 < rows && grid[r + 1][c] == '1'
                            && !visited[r + 1][c]) {
                            row.push_back(r + 1);
                            col.push_back(c);
                            visited[r + 1][c] = true;
                        }

                        if (c > 0 && grid[r][c - 1] == '1'
                            && !visited[r][c - 1]) {
                            row.push_back(r);
                            col.push_back(c - 1);
                            visited[r][c - 1] = true;
                        }

                        if (c + 1 < cols && grid[r][c + 1] == '1'
                            && !visited[r][c + 1]) {
                            row.push_back(r);
                            col.push_back(c + 1);
                            visited[r][c + 1] = true;
                        }
                    }
                }
            }
        }

        return islands;
    }
};
