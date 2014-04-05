Problem Statement
    
In this problem, all strings consist of uppercase English letters only. That is, there are 26 distinct letters.  The weight of a string S can be computed as follows: for each letter that occurs at least once in S, its leftmost and rightmost occurrences L and R are found and the weight is increased by R-L.  For example, if S="ABCACAZ", the weight of S is (5-0) + (1-1) + (4-2) + (6-6) = 7. (The leftmost occurrence of 'A' is at the index L=0, the rightmost one is at R=5, so 'A' contributes 5-0 = 5 to the weight of S. The only 'B' contributes 0, the pair of 'C's adds 2, and the only 'Z' adds 0.)  You are given a int L. Consider all strings of length L. Compute the weight of each of these strings. The strings with the minimum weight among all of them are called light. Your task is to count the number of light strings of length L. Since this count may be very large, return it modulo 1,000,000,009.
Definition
    
Class:
StringWeightDiv2
Method:
countMinimums
Parameters:
int
Returns:
int
Method signature:
int countMinimums(int L)
(be sure your method is public)
    

Constraints
-
L will be between 1 and 1000, inclusive.
Examples
0)

    
1
Returns: 26
Any string of length 1 has weight equal to 0.
1)

    
2
Returns: 650
We can divide strings of length 2 into two classes: the strings with distinct first and second letter, and the strings with two equal letters. The strings composed of two equal letters have weight 1. All the other strings have weight 0. Thus, the number of strings of minimum weight is 26*26-26=650.
2)

    
50
Returns: 488801539

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
