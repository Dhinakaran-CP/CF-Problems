**Divisible by Seven (Codeforces 375A)**

## Key Observation

The choice of the digits {1,6,8,9} is the crux of the problem.

There are only 7 possible remainders when any number x is divided by 7(namely 0,1,2,3,4,5,6). The four digits {1,6,8,9} have 4! = 24 unique permutations.

| Permutation | Remainder Modulo 7 |
|:------------|--------------------:|
| 1869        |                   0 |
| 1968        |                   1 |
| 1689        |                   2 |
| 6198        |                   3 |
| 1698        |                   4 |
| 1986        |                   5 |
| 1896        |                   6 |


## The Greedy Strategy

Since we can always form any remainder we want using just these four digits, we can treat the rest of the digits as a fixed "prefix" (
P
), calculate what remainder it leaves, and then pick the exact 
4
-digit permutation at the end to "patch" the remainder so the overall sum becomes a multiple of 
7.

However, we must avoid leading zeroes. We can easily resolve this by dividing the digits into three parts:

*The Prefix (
P
)*: All non-zero digits (excluding one copy of 1, 6, 8, 9).

*The Permutation*: One reserved copy of the digits {1, 6, 8, 9}.

*The Suffix*: All 0s.

## Algorithm

1. **Reserve the Digits**  
   Count the frequencies of all digits. Decrement the counts of 1, 6, 8, and 9 by 1 each to reserve them.

2. **Build the Prefix $P$**  
   Concatenate the remaining non-zero digits (from 1 to 9) to form the prefix string. As you build the string, maintain the running remainder modulo 7:
   $$r_{\text{prefix}} = (r_{\text{prefix}} \times 10 + \text{digit}) \pmod{7}$$

3. **Account for the Shift**  
   When we append our 4-digit permutation to the prefix, the prefix is shifted left by 4 decimal places. Calculate the shifted remainder:
   $$r_{\text{shift}} = (r_{\text{prefix}} \times 10^4) \pmod{7} = (r_{\text{prefix}} \times 4) \pmod{7}$$
   > **Note:** $10^4 \equiv 4 \pmod{7}$

4. **Solve for the Permutation**  
   We need $(r_{\text{shift}} + \text{permutation}) \equiv 0 \pmod{7}$  
   Therefore, we need a permutation of $\{1,6,8,9\}$ with remainder:
   $$\text{target} = (7 - r_{\text{shift}}) \pmod{7}$$

5. **Output**  
   Print the prefix $P$, followed by the selected permutation, followed by all the saved 0s at the end.

   ## Complexity Analysis

   **Time Complexity:** O(N) , where N is the number of digits in given input.

   **Space Complexity:** O(N)  to store the frequencies.
