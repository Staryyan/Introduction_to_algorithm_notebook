# Ch15--动态规划
## 动态规划原理
适合动态规划的问题通常具有两个要素：最优子结构和子问题重叠。简单地说，就是要解决一个原问题，可以把该问题分解为很多的子问题，而子问题也可以同样地分割为其他的子问题。在这个时候如果我们使用暴力求解会导致效率低下，而且浪费资源。动态规划的想法就是把子问题的解放入一个表中，当其他子问题求解时也可以通过这个表查看已解决的子问题，从而解决问题。

动态规划的难度在于刻画子问题。通常的解决方法是把问题缩小，寻找小问题的最优解，并且在适当的时代扩展它。我们通常自底向上地使用最优子结构。也就是说先求出子问题的最优解，然后求原问题的最优解。原问题最优解的代价通常就是子问题最优解的代价再加上由此选择直接带来的代价。

需要注意的是，一个问题是否适合动态规划算法同时依赖于子问题的重叠性和无关性。也就是说，两个子问题不能共享资源，并且两个子问题实际上是一个子问题，只是作为不同问题的子问题。

接下来，我用leetcode题目来解释如何使用动态规划算法。

## 典型例题
[Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices/)

题意：题目意思就是在已知的一个序列中找出所有含有3个以上形成等差数列的序列。
分析： 我们可以考虑声明一个表用来记录从第0个到第i个的元素所能行程的最优数量（最优子结构），然后再考虑第i+1个元素可以和前面的i个元素行程多少个等差序列。
于是`dp[i+1] = dp[i] + count`，`count`表示最后一个元素为i+1的等差序列数量。
不难发现，实际上每个子问题都是一样的。

参考代码：

```
/**
 * 413.
 * https://leetcode.com/problems/arithmetic-slices/
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool checkSeq(vector<int>& A, int start, int end) {
        int diff = A[start + 1] - A[start];
        for (int i = start; i < end; ++i) {
            if (A[i + 1] - A[i] != diff) {
                return false;
            }
        }
        return true;
    }
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) {
            return 0;
        }
        vector<int> ans; ans.push_back(0); ans.push_back(0);
        if (checkSeq(A, 0, 2)) {
            ans.push_back(1);
        } else {
            ans.push_back(0);
        }
        for (int i = 3; i < A.size(); ++i) {
            int count = 0;
            for (int j = i - 2; j >= 0; j--) {
                if (checkSeq(A, j, i)) {
                    count++;
                } else {
                    break;
                }
            }
            ans.push_back(ans[i - 1] + count);
        }
        return ans[A.size() - 1];
    }
};
int main() {
    Solution so;
    vector<int> A = {2,1,3,4,2,3};
    cout << so.numberOfArithmeticSlices(A);
}
```


[Arithmetic Slices II - Subsequence](https://leetcode.com/problems/arithmetic-slices-ii-subsequence/)

题意：和前面的问题类似，只是这题不要求等差序列在原序列中是连续的。
分析：我们同样考虑使用动态规划中自底向上的算法。只是这时候的表不再这么简单，我们设计一个表记录第i个元素可以和前面i - 1个元素形成的差值。
于是表就是`vector<unordered_map<int, int>> dp(A.size());`，分别表示`[vertex, [diff, count]]`。
表示以i元素结尾的序列并且形成了diff差值的数量。
对于最终的答案我们声明一个变量用来统计，每次发现一个新的序列我们都增加这个变量。对于第i + 1个元素，我们遍历前面的i个元素，并且把第k个元素和第i+1个元素的差值在dp[k]里面查找，如果能找到这个差值（也就是说，k元素之前也有元素能和k形成这个差值，满足题意，3个以上的元素），那么最终结果就可以增加dp[k]中的这个差值的数量。

参考代码：

```
/**
 * 446
 * https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
 */
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.empty()) { return 0; }
        vector<unordered_map<int, int>> dp(A.size()); // [vertex, [diff, count]]
        int res = 0;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if((long)A[i] - (long)A[j] > INT_MAX || (long)A[i] - (long)A[j] < INT_MIN) continue;
                // do not ignore this step, it will help you save time & space to pass OJ.
                int diff = A[i] - A[j];
                dp[i][diff]++;
                if (dp[j].find(diff) != dp[j].end()) {
                    dp[i][diff] += dp[j][diff];
                    res += dp[j][diff];
                }
            }
        }
        return res;
    }
};

```

[edit-distance](https://leetcode.com/problems/edit-distance/)

题意：计算如何能最少操纵地把字符串word1转换为字符串word2。
分析：题目中给出了三种操作：
a) Insert a character
b) Delete a character
c) Replace a character
我们用一个表dp[i][j]来存储word1，长度为i的字符串转换到word2中长度为j的子字符串所需要的最少操作数。
对于dp[i][j]来说，以上三种操作分别需要以下代价：
1）插入一个新的字母到word1中，`dp[i][j] = dp[i][j - 1] + 1`，意味着新增的一个字母匹配word2的第j个字母。
2）从word1中删除一个字母，`dp[i][j] = dp[i - 1][j] + 1`，意味着word2不再需要匹配word1的第i个字母。
3）word1中替换一个字母，`dp[i][j]=dp[i-1][j-1]+1`，意味着i和j一定是匹配的了，只需要确保word1的i-1字符串和word2的j-1字符串匹配即可。
那么以上过程对于任意长度的word1和word2都是满足。（最优子结构）

参考代码：

```
/**
 * 72
 * https://leetcode.com/problems/edit-distance/
 *
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = (int) word1.length(), m = (int) word2.length();
        if (!n || !m) { return m + n; }
        /**
         * dp[i][j]: word1.substr(i), word2.substr(j)
         */
        vector<vector<int>> dp((unsigned long) (n + 1), vector<int>((unsigned long) (m + 1), 0));
        /**
         * Initialization.
         */
        for (int i = 0; i <= m; ++i) { dp[0][i] = i; }
        for (int i = 0; i <= n; ++i) { dp[i][0] = i; }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] != word2[j - 1]) {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                } else {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};
```

[Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/)

分析：题目较简单，使用的就是自底向上的算法。用表dp表示i块钱可以有多少种组合。那么我们就可以对任意k块钱，依次减去nums中给定的零钱，计算求和减去相应零钱后的组合数。（最优子结构：每个特定的总钱数。）


```
/**
 * 377
 * https://leetcode.com/problems/combination-sum-iv/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        for (int i = 0; i <= target; ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == nums[j]) {
                    dp[i]++;
                } else if (i - nums[j] > 0) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};
```

[Burst Balloons](https://leetcode.com/problems/burst-balloons/)

分析：此题和前面使用的方法不同，但使用的仍然是动态规划算法常见的方法，称为括号化问题。就是说要去任意i 到 j 区间内最优解，把问题分解为[i, k - 1]，[k + 1, j] 以及k操作所需要的开销。
此题使用的就是这种想法：用表dp[i][j]存储[i, j]的最优解，对于dp[i][j + 1]则只需要遍历dp[i][i] dp[i][j + 1]中每一个中间燃烧点，算出其中最优解，并且对于这个原问题中，任意子问题dp[i][k]都是已知的了。

```
/**
 * 312
 * https://leetcode.com/problems/burst-balloons/
 */
#include <vector>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.size() == 0) { return 0; }
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int len = nums.size(), dp[len][len]{};
        for (int r = 1; r < len - 1; ++r) {
            for (int l = r; l > 0; --l) {
                for (int k = l; k <= r; ++k) {
                    dp[l][r] = max(dp[l][r], dp[l][k - 1] + nums[l - 1] * nums[k] * nums[r + 1] + dp[k + 1][r]);
                }
            }
        }
        return dp[1][len - 2];
    }
};
```

[Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/)
分析：此题使用的仍然是自底向上的算法。我们使用表dp[k]来存储k个连续的数能形成的二叉搜索树数量。那么对于dp[k+1]则可以做这样的分析。我们把k+1作为中间枢纽分成k+1节点的右上方和他的左下方，（k+1是树中最大的节点）那么就是把k个数分成两份a,b分别表示k+1节点的右上方和左下方。于是对于特定的分配所能产生的解的数量就为dp[a] * dp[b]， 所以遍历所有的分配情况就可以得到相应dp[k+1]的解了。


```
/**
 * 96
 * https://leetcode.com/problems/unique-binary-search-trees/
 */
#include <vector>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0; dp[1] = 1; dp[2] = 2;
        for (int i = 3; i < n + 1; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (j == i - 1 || j == 0) { dp[i] += dp[i - 1]; }
                else {
                    dp[i] += dp[j] * dp[i - j - 1];
                }
            }
        }
        return dp[n];
    }
};
```

[unique-binary-search-trees-ii](https://leetcode.com/problems/unique-binary-search-trees-ii/)
分析：此问题属于动态规划的另一个步骤，重构最优解，也就是说要把形成最优解的过程描述出来。想法和前面是一样的，最主要的问题在于构造树而已。具体方法见代码。

参考代码

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) { return vector<TreeNode*>{}; }
        vector<vector<TreeNode*>> dp(n + 1);
        dp[0].push_back(nullptr);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (int k = 0; k < dp[j].size(); ++k) {
                    for (int l = 0; l < dp[i - j - 1].size(); ++l) {
                        int id = 0;
                        TreeNode* root = new TreeNode(0);
                        root->left = copyTree(dp[j][k], id);
                        root->val = ++id;
                        root->right = copyTree(dp[i - j - 1][l], id);
                        dp[i].push_back(root);
                    }
                }
            }
        }
        return dp[n];
    }
    /**
     * deep copy.
     * @param root 
     * @param id 
     * @return 
     */
    TreeNode* copyTree(TreeNode* root, int& id) {
        if(!root) return 0;
        TreeNode* root1 = new TreeNode(0);
        root1->left = copyTree(root->left,id);
        root1->val = ++id;
        root1->right = copyTree(root->right,id);
        return root1;
    }
};
```


[best-time-to-buy-and-sell-stock-with-cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

分析：此问题属于括号化问题，对于i到j的股票价格，我们假定在第k天休息，前面买卖赚的钱和后面买卖赚的钱总和就是i到j天总共能赚的钱。
代码如下：但对于输入较大时，会因为生成数组超时。

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<int>> profit(size, vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = i; j < size; ++j) {
                profit[i][j] = prices[j] - prices[i];
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int k = 0; k <= i; ++k) {
                if (k == 0) {
                    profit[0][i] = max(profit[0][i], profit[k + 1][i]);
                } else if (k == size - 1) {
                    profit[0][i] = max(profit[0][i], profit[0][k - 1]);
                } else{
                    profit[0][i] = max(profit[0][i], profit[0][k - 1] + profit[k + 1][i]);
                }
            }
        }
        return profit[0][size - 1];
    }
};
```

来自[Clean c++ DP solution](https://discuss.leetcode.com/topic/61843/clean-c-dp-solution)

1、keep best value for holding one product in bestBuy.
2、best profit after processing item i is by selling i or the existed profit, max(profit_current, bestBuy + prices[i])
3、next bestBuy is by buying current product or the existed bestBuy, max(bestBuy, profit_prev - prices[i]) where profit_prev is the most profit before previous one (cooldown)

最特别的地方就在于profit_prev，用来记录如果当前天的前一天的前面的受益，如此就可以计算如果在当天买入（前一天必须cooldown),可以获得的受益。


```
/**
 * 309
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int bestBuy = INT_MIN;
        int profitPrev = 0, profitCurr = 0;
        for (int i = 0; i < size; ++i) {
            int current = max(profitCurr, bestBuy + prices[i]);
            bestBuy = max(bestBuy, profitPrev - prices[i]);
            profitPrev = profitCurr;
            profitCurr = current;
        }
        return profitCurr;
    }
};

```


[Unique Paths](https://leetcode.com/problems/unique-paths/)
分析：对于任一节点，dp[i][j]都只能从dp[i-1][j]和dp[i][j-1]中来。

```
/**
 * 62
 * https://leetcode.com/problems/unique-paths/
 */
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        int graph[101][101];
        memset(graph, 0, sizeof(graph));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == 1 && j == 1) {
                    graph[1][1] = 1;
                } else {
                    graph[i][j] = graph[i - 1][j] + graph[i][j - 1];
                }
            }
        }
        return graph[m][n];
    }
};
```

[Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)
分析：首先计算整个序列的总和，如果为奇数则不可能分为两个subset，如果为偶数则取半，half，用一个数组dp[half + 1]，记录通过给定的序列能都到达相应的j（dp[j]），

```
/**
 * 416
 * https://leetcode.com/problems/partition-equal-subset-sum/
 */
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;
class Solution {
public:
    /**
     * If there is a sequence of num which can reach half,
     * then the left num can also construct a sequence which sums up as half.
     * @param nums 
     * @return 
     */
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        /**
         * odd: false.
         */
        if (sum & 1) { return false; }
        int half = sum >> 1;
        vector<bool> accessibility(half + 1, false);
        accessibility[0] = true;
        for (auto num : nums) {
            for (int i = half; i >= num; --i) {
                if (accessibility[i - num]) {
                    accessibility[i] = true;
                }
            }
        }
        return accessibility[half];
    }
};
```

[Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)
分析：用表dp[i]表示以i为终点的最长增长序列的长度，于是对于dp[k]可以遍历前面k-1个点，如果找到以k结尾所能形成的最长序列长度。最后只要遍历所有的节点找到最长的长度即可。

```
/**
 * 300
 * https://leetcode.com/problems/longest-increasing-subsequence/
 */
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /**
         * For each vertex,
         * the Longest Increasing Subsequence.
         */
        vector<int> lis(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j] && lis[j] + 1 > lis[i]) {
                    lis[i] = lis[j] + 1;
                }
            }
        }
        int maxSeq = 0;
        for (int k = 0; k < nums.size(); ++k) {
            maxSeq = max(maxSeq, lis[k]);
        }
        return maxSeq;
    }
};
```

[minimum-path-sum](https://leetcode.com/problems/minimum-path-sum/)
分析：这个问题可以用广搜来做，而用动态规划也是很简单的。从两条路径（来源）中找到较小的来源。

```
/**
 * 64
 * https://leetcode.com/problems/minimum-path-sum/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, INT_MAX));
        dp[0][1] = 0; dp[1][0] = 0;
        for (int i = 1; i <= grid.size(); ++i) {
            for (int j = 1; j <= grid[0].size(); ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[grid.size()][grid[0].size()];
    }
};
```

[Perfect Squares](https://leetcode.com/problems/perfect-squares/)
分析：此题太简单了。使用的是自底向上的方法。


```
/**
 * 279
 * https://leetcode.com/problems/perfect-squares/
 */
#include <vector>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i - j * j] + 1, dp[i]);
            }
        }
        return dp[n];
    }
};
```

[Guess Number Higher or Lower II](https://leetcode.com/problems/guess-number-higher-or-lower-ii/)
分析：此题使用的是括号化问题。对于任意i到k区间中的开销为第一次猜m，i到m-1的开销，和m+1到k的开销。

```
/**
 * 375
 * https://leetcode.com/problems/guess-number-higher-or-lower-ii/
 */

#include <vector>
using namespace std;
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));
        for (int i = 2; i <= n; ++i) {
            for (int j = i - 1; j > 0; --j) {
                int globalMin = INT_MAX;
                for (int k = j + 1; k < i; ++k) {
                    globalMin = min(globalMin, k + max(table[j][k - 1], table[k+1][i]));
                }
                table[j][i] = i == j + 1 ? j : globalMin;
            }
        }
        return table[1][n];
    }
};
```

[Wiggle Subsequence](https://leetcode.com/problems/wiggle-subsequence/)
分析：维持一个表dp用来记录dp[i]作为震荡上升时的长度和作为下降时的长度。
这里需要证明，对于一个最长的震荡序列，nums的最后一个值一定在这个最长的序列中。我们假设存在一个最长序列（last不是这个序列的最后一个），那么last如果比这个序列的最后一个大，last可以作为上升进入序列中，序列长度加1，如果last比他小，则last可以作为下降进入序列中。如果相等，则可以与序列的前面的值组成一个新的序列，与最长序列一样长。所以证必。

```
/**
 * 376
 * https://leetcode.com/problems/wiggle-subsequence/
 */
#include <vector>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 0) { return 0; }
        /**
         * The first represent index as the Up.
         * The second represent index as the Down.
         */
        vector<pair<int, int>> dp(nums.size(), pair<int, int>(1, 1));
        dp[0].first = 1; dp[0].second = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j =  i - 1; j >= 0; --j) {
                if (nums[i] > nums[j]) {
                    dp[i].first = max(dp[i].first, dp[j].second + 1);
                } else if (nums[i] < nums[j]) {
                    dp[i].second = max(dp[i].second, dp[j].first + 1);
                }
            }
        }
        return max(dp[nums.size() - 1].first, dp[nums.size() - 1].second);
    }
};
```

[Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset/)
分析：使用自底向上的方法，dp中每个index都维持一个包含自己的最长的subset。

```
/**
 * 368
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) { return vector<int>(); }
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(nums.size());
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j].size() > dp[i].size()) {
                    dp[i] = dp[j];
                }
            }
            dp[i].push_back(nums[i]);
            if (res.size() < dp[i].size()) {
                res = dp[i];
            }
        }
        return res;
    }
};
```

[Triangle](https://leetcode.com/problems/triangle/)
分析：最优括号化问题。表示从i 到 j的最短路径。

```
/**
 * 120
 * https://leetcode.com/problems/triangle/
 */
#include <vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i) {
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
            for (int j = 1; j < i; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            }
        }
        int localMin = INT_MAX;
        for (int k = 0; k < triangle.size(); ++k) {
            localMin = min(localMin, dp[triangle.size() - 1][k]);
        }
        return localMin;
    }
};
```

[Unique Paths II](https://leetcode.com/problems/unique-paths-ii/)
分析：简单题。

```
/**
 * 63
 */
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int col = obstacleGrid[0].size();
        int row = obstacleGrid.size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[row - 1][col - 1] == 1) {
            return 0;
        }
        vector<vector<int>> dp(row, vector<int>(col, 0));
        dp[0][0] = 1;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (j != 0) {
                    if (obstacleGrid[i][j - 1] == 0) {
                        dp[i][j] += dp[i][j - 1];
                    }
                }
                if (i != 0) {
                    if (obstacleGrid[i - 1][j] == 0) {
                        dp[i][j] += dp[i - 1][j];
                    }
                }
            }
        }
        return dp[row - 1][col - 1];
    }
};
```

[Coin Change](https://leetcode.com/problems/coin-change/)
分析：dp维持i块钱最少需要多少次换硬币。自底向上的方法。

```
/**
 * 322
 * https://leetcode.com/problems/coin-change/
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (i < coins[j]) { break; }
                if (dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
int main() {
    vector<int> in{186,419,83,408};
    cout << Solution().coinChange(in, 6249);
    return 0;
}
```

