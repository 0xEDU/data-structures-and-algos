// Reverse and rotate implementations

/*void reverse(vector<int> &v, int start, int end) {*/
/*    while (start < end) {*/
/*        swap(v[start], v[end]);*/
/*        start++;*/
/*        end--;*/
/*    }*/
/*}*/
/**/
/*void rotate(vector<int> &v, int start) {*/
/*    int n = v.size();*/
/**/
/*    start %= n;*/
/*    reverse(v, 0, start - 1);*/
/*    reverse(v, start, n - 1);*/
/*    reverse(v, 0, n - 1);*/
/*}*/


// Optimal solution
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> v;
        int rotateStart = 0;

        for  (int i = 0; i <= (pow(2, n) - 1); i++) {
            int gray = i ^ (i >> 1);
            v.push_back(gray);
            if (gray == start) rotateStart = i;
        }

        rotate(v.begin(), v.begin() + rotateStart, v.end());

        return v;
    }
};
