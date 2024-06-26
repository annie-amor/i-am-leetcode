class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = matrix.size() * matrix[0].size() - 1;

        while(left <= right){
            int mid = (left + right) / 2;
            int ml = mid / n; // to find the row
            int mr = 0; // to find the column
            if(mid >= n)
                mr = mid % n;
            else
                mr = mid;

            // at this point, we have row and column indexes

            if(matrix[ml][mr] > target){
                right = mid - 1;
            }else if(matrix[ml][mr] < target){
                left =  mid + 1;
            }else
                return true;
        }


        return false;
    }
};
