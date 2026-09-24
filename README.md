# unstop-Code-conquest-5
Making the Largest Island with Obstacles
You are given an N x N matrix grid where each element is one of the following:

1 representing land,

0 representing water,

-1 representing an obstacle.

A group of connected 1s forms an island. Two 1s are connected if they share one of their four sides (up, down, left, or right). You are allowed to change at most one 0 to 1 (obstacles -1 cannot be changed) in order to maximize the size of an island.

Your task is to return the size of the largest island possible after performing the operation.

Input Format
The first line contains an integer N representing the number of rows (and columns) of the matrix.

The next N lines each contain N space-separated integers where each integer is one of -1, 0, or 1, representing the matrix grid.

Output Format
Print a single integer which is the size of the largest island that can be achieved after changing at most one 0 to 1.

Constraints
1 ≤ N ≤ 5*10^2

grid[i][j] ∈ {−1,0,1}  for all valid indices i and j.

Sample Testcase 0
Testcase Input
2
1 -1
-1 0
Testcase Output
1
Explanation


The grid initially contains one land cell. Changing the water cell does not connect it with any other land cell, so the maximum island size remains 1.



Sample Testcase 1
Testcase Input
4
1 1 0 1
1 0 1 0
0 1 0 1
1 0 1 1
Testcase Output
6
Explanation


The largest island before modification is of size 3.




Changing 0 at (2,2) to 1 connects multiple islands, making the largest island size 6.

