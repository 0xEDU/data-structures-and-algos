#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> current;
    int _n = 0;
    int _k = 0;

    void backtrack(int start) {
        if (current.size() == _k) {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= _n; i++) {
            current.push_back(i);
            backtrack(i + 1);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        _n = n;
        _k = k;

        backtrack(1);

        return result;
    }
};

int main() {
    Solution s;

    s.combine(4, 2);
}
