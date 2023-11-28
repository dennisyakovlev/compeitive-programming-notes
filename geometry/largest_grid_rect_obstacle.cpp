/*
find the largest rectangle on a grid with some obstacles in the way (leetcode 85)

generate all valid rectangle possible, obviously the max will be max of these

for some point
    1) height at current point
    2) left distance to first 0 < height
    3) right distance to first 0 < height

    area of square is (l_dist + r_dist + 1) * height

how to find these distances ?

iterate by col, top to bottom
    at every row, take the max(left_all) and min(right_all)
    reset the l,r bounds at every 0 in the col
    keep track of current height, resetting upon 0 in col

does this generate all valid rectangles?

proof 
    let R be any valid rectangle

    first show
    R is bounded by exactly 4 values defined by 0s, 1 for each side
        w.l.o.g
        for some side assume has 2 unique bounding values for two seperate 0s
            0_a = 0_b => 1 unique bounding value, contradiction
            0_a < 0_b => bound edge is defined by 0_a or 0_b
                        => bounded by 0_a => 1 unique bounding value, contradiction
                        or
                        => bounded by 0_b => rect has 0 => invalid rect, contradiction
            likewise for 0_a > 0_b
        conclude a side is bounded by some 0 value => statement true

    now show
    R will be generated in the given traversal
        R is valid
            => has bounding 0 from top, bottom
            => algo will see this 0, resetting l,r bounds correctly
        are left and right bounds correct ?
        likewise, R is valid
            => has bounding right 0
            => like in first lemma, know need minimum right 0, otherwise invalid rect
            => keep track of minimum right 0 from bounding top 0
            => algo correct
        likewise but keep track of max for left bounding 0

    conclude all valid rectangles are generated
*/

#include <bits/stdc++.h>

using namespace std;

int maximalRectangle(const vector<vector<char>>& matrix)
{
    int rows = size(matrix), cols = size(matrix[0]);
    vector<vector<int>> r_min(rows, vector<int>(cols, 1)),
                        l_max(rows, vector<int>(cols, 1));

    for (int r = 0; r != rows; ++r)
    {
        r_min[r][cols - 1] = matrix[r][cols - 1] == '1';
        for (int c = cols - 2; c != -1; --c)
            r_min[r][c] = (r_min[r][c + 1] + 1) * (matrix[r][c] == '1');

        l_max[r][0] = matrix[r][0] == '1';
        for (int c = 1; c != cols; ++c)
            l_max[r][c] = (l_max[r][c - 1] + 1) * (matrix[r][c] == '1');
    }

    int M = 0;
    for (int c = 0; c != cols; ++c)
    {
        int ml = INT_MAX, mr = INT_MAX, ch = 0;
        for (int r = 0; r != rows; ++r)
        {
            if (matrix[r][c] == '0')
            {
                ml = INT_MAX;
                mr = INT_MAX;
                ch = 0;
            }
            else
            {
                ml = min(ml, l_max[r][c]);
                mr = min(mr, r_min[r][c]);
                ++ch;

                M = max(M, ch * (ml + mr - 1));
            }
        }
    }
    return M;
}

int main()
{
    cout << maximalRectangle
    ({
        {'1','1','1'},
        {'1','1','0'}
    });
}
