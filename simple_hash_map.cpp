class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int, char> sMap;
        unordered_map<int, char> tMap;

        for (int i = 0; i < s.size(); i++) {
            if (sMap.contains(s[i]) && sMap[s[i]] != t[i])  {
                return false;
            }
            if (tMap.contains(t[i]) && tMap[t[i]] != s[i])  {
                return false;
            }
            sMap[s[i]] = t[i];
            tMap[t[i]] = s[i];
        }

        return true;
    }
};
