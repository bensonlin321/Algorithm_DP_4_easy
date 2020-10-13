#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <limits>
#include <utility> // pair
#include <tuple>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() <= 0) {
            return 0;
        }
        int current_profit = 0; // the profit of ith day
        int max_profix = 0;

        for (int i = 0 ; i < prices.size(); i++) {
            printf("%d\t", prices[i]);
        }
        printf("\n");

        // go through each day
        for (int i = 1; i < prices.size(); i++) {
            current_profit = std::max(0, current_profit + prices[i] - prices[i-1]);
            max_profix = std::max(max_profix, current_profit);
            printf("[%d] prices[%d]: %d, prices[%d]: %d ", i, i, prices[i], i-1, prices[i-1]);
            printf("[%d] current_profit: %d, max_profix: %d\n", i, current_profit, max_profix);
        }

        /*

         7   1   5   3   6   4
         ^   ^
        [1] prices[1]: 1, prices[0]: 7, current_profit: 0, max_profix: 0

         7   1   5   3   6   4
             ^   ^
        [2] prices[2]: 5, prices[1]: 1, current_profit: 4, max_profix: 4

         7   1   5   3   6   4
             ^       ^        
        [3] prices[3]: 3, prices[2]: 5, current_profit: 2, max_profix: 4

         7   1   5   3   6   4
             ^           ^                
        [4] prices[4]: 6, prices[3]: 3, current_profit: 5, max_profix: 5
        [5] prices[5]: 4, prices[4]: 6, current_profit: 3, max_profix: 5
        output:5

        */

        return max_profix;
    }

};


int main(int argc, char *argv[]) {
    Solution *s = new Solution();
    std::vector<int> nums{ 9,6,7,7,1,5,3,6,4 };
    printf("output:%d\n", s -> maxProfit(nums));
}