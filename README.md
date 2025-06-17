# Data Structures & Algorithms
This is the solutions page to Leetcode problems. It covers the usage of Trees, Graphs, Binary Search, Dynamic Programming etc. The table below illustrates the code details further:

| # | Problem | Solution | Time | Space | Diffculty | Strategy | Notes |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 1833 | [Maximum Ice Cream Bar](https://leetcode.com/problems/maximum-ice-cream-bars/) | [C++](/1833_Maximum_Ice_Cream_Bars.cpp) | O(m+n) | O(m) | Medium | Greedy, Counting Sort |
| 409 | [Longest Pallindrome](https://leetcode.com/problems/longest-palindrome/) | [C++](/409_Longest_Pallindrome.cpp) | O(n) | O(1) | Easy | Greedy, HashSet|
| 455 | [Assign Cookies](https://leetcode.com/problems/assign-cookies/) | [C++](455_Assign_Cookies.cpp) | O(mlogm + nlogn) | O(log m + log n) | Easy | Greedy, 2 pointer|
| 1005 | [Maximize sum array after K negations](https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/) | [C++](1005_Maximize_Sum_Array_K_negation.cpp) | O(klog n) | O(n) | Easy | Priority Queue |
| 1663 | [Smallest String With A Given Numeric Value](https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/) | [C++](1663_Smallest_String_Numeric_Value.cpp)| O(n) | O(1) | Medium | Greedy Start from Right |
| 2410 | [Maximum match players with trainers](https://leetcode.com/problems/maximum-matching-of-players-with-trainers/) | [C++](2410_Max_Match_Players_Trainers.cpp)| O(nlogn + mlogm) | O(logm + logn) | Medium | Greedy Sort|
| 994 | [Rotting Oranges](https://leetcode.com/problems/rotting-oranges/) | [C++](994_Rotting_Oranges.cpp)| O(n*m) | O(n*m) | Medium | Graph BFS|
| 990 | [Satisfiability equality equations](https://leetcode.com/problems/satisfiability-of-equality-equations/) | [C++](990_Satisfiability_Equality_Eqns.cpp)| O(n) | O(n) | Medium | Graph DFS |
| 1372 | [Longest zigzag path in Binary tree](https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/) | [C++](1372_Longest_zigzag_path_Binary_Tree.cpp) | O(n) | O(n) | Medium | Binary Tree|
| 437 | [Path Sum III](https://leetcode.com/problems/path-sum-iii/) | [C++](437_Path_Sum.cpp) | O(n) | O(n) | Medium | Prefix Sum Hashmap, DFS|
| 2486 | [Append characters to string to make subsequence](https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/) | [C++](2486_Append_Characters_String_Make_Subsequence.cpp)| O(min(n,m)) | O(1) | Medium | Greedy |
| 2405 | [Optimal Partition String](https://leetcode.com/problems/optimal-partition-of-string/) | [C++](2405_Optimal_Partition_String.cpp) | O(n) | O(1) | Medium | Greedy |
| 2348 | [Largest Pallindromic Number](https://leetcode.com/problems/largest-palindromic-number/) | [C++](2348_Largest_Pallindrome_Num.cpp) | O(n) | O(1) | Medium | Greedy |
| 2250 | [Count number of rectangles containing each point](https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/) | [C++](2250_Count_Rectangles_containing_Point.cpp) | O(n+100+ m*100*logn) | O(n)| Medium | Binary Search, Hashmap |
| 1533 | [Find index of large integer](https://leetcode.com/problems/find-the-index-of-the-large-integer/) | [C++](1533_find_index_large_integer.cpp) | O(logn) | O(1)| Medium-Premium | Binary Search |
| 967 | [Numbers with same consecutive differences](https://leetcode.com/problems/numbers-with-same-consecutive-differences/) | [C++](967_numbers_with_same_consecutive_differences.cpp)| O(2^n) | O(n) | Medium | Backtracking, DFS |
| 216 | [Combination sum iii](https://leetcode.com/problems/combination-sum-iii/) | [C++](216_Combination_Sum_iii.cpp)| O(P(9,K)*K) | O(K) | Medium | Backtracking, DFS | P(*): Permutation |
| 387 | [First unique character in string](https://leetcode.com/problems/first-unique-character-in-a-string/) | [C++](387_First_unique_charater.cpp)| O(n) | O(1) | Easy | Linear Pass, Hashmap | |
| 128 | [Longest consecutive sequence](https://leetcode.com/problems/longest-consecutive-sequence/) | [C++](128_Longest_Consecutive_Sequence.cpp)| O(n) | O(n) | Medium | Hashset sequence build| Tricky |
| 695 | [Max area of island](https://leetcode.com/problems/max-area-of-island/) | [C++](695_Max_Area_Of_Island.cpp)| O(R*C) | O(R*C) | Medium | DFS |  |
| 47 | [Permutations II](https://leetcode.com/problems/permutations-ii/) | [C++](47_Permutations_ii.cpp)| O(Sum(P(N,k))) | O(N) | Medium | Backtracking | Sum: sum of all P(*)|
| 40 | [Combination sum II](https://leetcode.com/problems/combination-sum-ii/) | [C++](40_Combination_Sum_II.cpp)| O(2^N) | O(N) | Medium | Backtracking | Tricky |
| 2305 | [Fair distribution Cookies](https://leetcode.com/problems/fair-distribution-of-cookies/) | [C++](2305_Fair_distribution_cookies.cpp)| O(K^N) | O(K+N) | Medium | Backtracking |  |
| 79 | [Word search](https://leetcode.com/problems/word-search/) | [C++](79_Word_Search.cpp)| O(N*3^L) | O(L) | Medium | Backtracking |  |
| 1415 | [kth lexicographical string of happy strings](https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/) | [C++](1415_kth_lexicographical_string.cpp)| O(3*2^(N-1)) | O(N*K) | Medium | Backtracking |  |
| 491 | [Non Decreasing Subsequences](https://leetcode.com/problems/non-decreasing-subsequences/) | [C++](491_Non_Decreasing_Subsequences.cpp)| O(2^N * N^2) | O(N) | Medium | Backtracking |  |
| 93 | [Restore ip addresses](https://leetcode.com/problems/restore-ip-addresses/) | [C++](93_Restore_IP_Addresses.cpp)| O(M^N*N) | O(M*N) | Medium | Backtracking |  |
| 198 | [House Robber](https://leetcode.com/problems/house-robber/description/) | [C++](198_House_Robber.cpp) / [Optimized Space C++](198_House_Robber_ans2.cpp) / [Python](198_House_Robber_ans.py) / [Optimized Python](198_House_Robber_ans2.py)| O(N) | O(N)/ O(1)/ O(N)/ O(1) | Medium | Dynamic Programming | Iterative Bottom Up Recusrion Stack / Iterative Bottom Up Constant Space |
| 746 | [Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/description/) | [Python](746_Min_Cost_Climbing_Stairs_ans1.py)/ [Python Optimized](746_Min_Cost_Climbing_Stairs_ans2.py)  | O(N) | O(N)/ O(N)/ O(1) | Easy | Dynamic Programming | Top Down Recusrive Memoization / Bottom Up Tabulation / Bottom Up Optimized |
| 300 | [Longest increasing subsequence](https://leetcode.com/problems/longest-increasing-subsequence/description/) | [Python](300_Longest_Increasing_Subsequence.py)| O(N^2) | O(N) | Medium | Dynamic Programming | |
| 2140 | [Solving Questions With Brainpower](https://leetcode.com/problems/solving-questions-with-brainpower/description/) | [Python](2140_Solving_Questions_Brainpower.py)| O(N) | O(N) | Medium | Dynamic Programming | |
| 70 | [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/editorial/) | [Python](70_Climbing_Stairs.py)| O(N) | O(N)/ O(N)/ O(1) | Easy | Dynamic Programming |Closed form mathematical expression exists with Time: O(log(N))|
| 322 | [Coin Change](https://leetcode.com/problems/coin-change/description/) | [Python](322_Coin_Change.py)| O(S*N) | O(S) | Medium | Dynamic Programming with Depth First Search Tree |Extremely Tricky: Uses DFS with Recursive Tree under DP|
| 1143| [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/description/) | [Python](1143_Longest_Common_Subsequence.py)| O(M*N)| O(M*N) | Medium | Dynamic Programming | |
| 188 | [Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/) | [Python](188_Best_Time_Buy_Sell_StockIV.py)| O(N*K) | O(N*K) | Hard | Dynamic Programming | Top Down, Bottom Up solns | |
| 2218 | [Maximum Value of K Coins From Piles](https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/description/) | [Python](2218_Maximum_Value_K_Coins_From_Piles.py)| O(N*K*x) | O(N*K) | Hard | Dynamic Programming |x=total no. of coins (sum of len(piles[i])) |
| 714 | [Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/) | [Python](714_Best_Time_Buy_Sell_Stock_Transaction_Fee.py)| O(N) | O(N) | Medium | Dynamic Programming | |
| 309 | [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/) | [Python](309_Best_Time_Buy_Sell_Stock_Cooldown.py)| O(N) | O(N) | Medium | Dynamic Programming | |
| 123 | [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/) | [Python](123_Best_Time_Buy_Sell_StockIII.py)| O(N) | O(N) | Hard | Dynamic Programming ||
| 62 | [Unique Paths](https://leetcode.com/problems/unique-paths/description/) | [Python](62_Unique_Paths.py)| O(M*N) | O(M*N) | Medium | Memoization, Tabulation | Not a DP|
| 64 | [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/description/) | [Python](64_Minimum_Path_Sum.py)| O(M*N) | O(M*N), O(1), O(N) | Medium | Dynamic Programming Matrix| |