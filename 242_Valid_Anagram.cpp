#include <algorithm>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        string one = s, two = t;
        sort(one.begin(), one.end());
        sort(two.begin(), two.end());

        return one == two;
    }
};
