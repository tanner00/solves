// URL: https://leetcode.com/contest/weekly-contest-165/problems/number-of-burgers-with-no-waste-of-ingredients/
// TYPE: Math

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if (tomatoSlices == 0 && cheeseSlices == 0) return vector<int>{0,0};
        if (tomatoSlices < 0 || cheeseSlices < 0) return vector<int>{};
        if ((tomatoSlices % 2) != 0) return vector<int>{};

        int small = (4 * cheeseSlices - tomatoSlices) / 2;
        int large = cheeseSlices - small;
        if (small < 0 || large < 0) return vector<int>{};
        return vector<int> {large, small};
    }
};
