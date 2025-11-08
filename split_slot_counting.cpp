class Solution {
//    vector<string_view> split(string_view s) { vector<string_view> splitString;
//
//        size_t start = 0;
//        while (true) {
//            size_t position = s.find(',', start);
//            if (position == string_view::npos) {
//                splitString.push_back(s.substr(start));
//                break;
//            }
//            splitString.push_back(s.substr(start, position - start));
//            start = position + 1;
//        }
//
//        return splitString;
//    }

public:
    bool isValidSerialization(string preorder) {
        // slot counting
        int slots = 1;

        for (size_t i = 0; i < preorder.size();) {
            if (!slots) return false;

            if (preorder[i] == '#') {
                slots--;
                i++;
            } else {
                while (i < preorder.size() && preorder[i] != ',') i++;
                slots++;
            }

            if (i < preorder.size() && preorder[i] == ',') i++;
        }

        return slots == 0;
    }
};
