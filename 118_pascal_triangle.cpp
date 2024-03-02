#include <vector>

std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> ans(numRows);

        for (int i = 0; i < numRows; i++){
            ans[i].resize(i + 1);   // resize based on what row it is
            // first element of that row is always 1
            ans[i][0] = 1;

            // all middle elements = ans[i-1][j-1] + ans[i-1][j]
            // start with j = 1
            for (int j = 1; j < i; j++) ans[i][j] = ans[i-1][j-1] + ans[i-1][j];

            // end element of that row is always 1
            ans[i][i] = 1;
        }
        return ans;
    }