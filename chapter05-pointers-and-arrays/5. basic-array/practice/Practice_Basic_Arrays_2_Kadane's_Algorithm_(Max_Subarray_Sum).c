/*
Practice: Basic Arrays 2 — Kadane's Algorithm (Max Subarray Sum)
Find the contiguous subarray with the largest sum. Return that sum.
Example: arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4] → answer is 6 (from subarray [4, -1, 2, 1])
Hint: Track the maximum sum ending at each position as you loop.
*/
/*
Find a group of CONSECUTIVE numbers (side by side, no gaps) whose sum is the largest.
Example: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Some contiguous groups and their sums:

[4] → sum = 4
[4, -1] → sum = 3
[4, -1, 2] → sum = 5
[4, -1, 2, 1] → sum = 6 ← biggest!
[4, -1, 2, 1, -5] → sum = 1

So the answer is 6.
You must find which contiguous chunk gives the maximum sum.
*/