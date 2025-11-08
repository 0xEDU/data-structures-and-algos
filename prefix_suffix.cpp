class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> lhs(size + 1, 1);
        vector<int> rhs(size + 1, 1);
        vector<int> answer;

        for (int i = 1; i < size; i++) {
            if (nums[i - 1] >= nums[i]) lhs[i] = lhs[i - 1] + 1;
        }

        for (int i = size - 2;i >= 0;i--) {
           if (nums[i] <= nums[i + 1]) rhs[i] = rhs[i + 1] + 1;
        }

        for (int i = k; i < size - k; i++) {
            if (lhs[i - 1] >= k && rhs[i + 1] >= k) answer.push_back(i);
        }

        return answer;
    }
};
