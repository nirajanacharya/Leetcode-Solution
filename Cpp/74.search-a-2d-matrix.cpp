class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size();
        if (m == 0) {
            return false;
        }
        const int n = matrix[0].size();
        if (n == 0) {
            return false;
        }

        return findInSubMatrix(matrix, 0, m-1, 0, n-1, target);
    }

    bool findInSubMatrix(const vector<vector<int>>& matrix,
        const int top, const int bottom, const int left, const int right,
        const int target) {
        if (top > bottom || left > right) {
            return false;
        }

        if (target < matrix[top][left]) {
            return false;
        }
        if (target == matrix[top][left]) {
            return true;
        }
        if (target > matrix[bottom][right]) {
            return false;
        }
        if (target == matrix[bottom][right]) {
            return true;
        }

        if (top == bottom && left == right) {
            return target == matrix[top][left];
        }

        // Find the middle point.
        int middle_row = (top + bottom + 1) / 2;
        int middle_column = (left + right + 1) / 2;
        int middle_value = matrix[middle_row][middle_column];
        if (target == middle_value) {
            return true;
        }

        bool found;
        if (target < middle_value) {
            // Search upper left.
            found = findInSubMatrix(matrix, top, middle_row  - 1, left, middle_column, target);
            if (found) {
                return true;
            }
            // Search left
            found = findInSubMatrix(matrix, middle_row, middle_row, left, middle_column - 1, target);
            if (found) {
                return true;
            }
        }

        // Search bottom left
        found = findInSubMatrix(matrix, middle_row+1, bottom, left, middle_column, target);
        if (found) {
            return true;
        }

        // Search right
        return findInSubMatrix(matrix, top, bottom, middle_column+1, right, target);
    }
};