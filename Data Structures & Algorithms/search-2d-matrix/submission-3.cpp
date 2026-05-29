class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Utilities
        int m = matrix.size(); //3
        int n = matrix[0].size(); //4

        int l = 0;
        int r =  n*m - 1;

        while(l<=r){
            int mid = l + (r - l) / 2;
            int row = mid / n;
            int col = mid % n;

            if(matrix[row][col]==target) return true;
            else if (matrix[row][col]>target) r = mid -1;
            else l = mid +1;
        }

        return false;
    }
};
