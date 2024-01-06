/*
 * @lc app=leetcode id=1401 lang=cpp
 *
 * [1401] Circle and Rectangle Overlapping
 */

// @lc code=start
class Solution
{
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
    {
        int edgeX = (xCenter < x1) ? x1 : (xCenter > x2) ? x2
                                                         : xCenter;
        int edgeY = (yCenter < y1) ? y1 : (yCenter > y2) ? y2
                                                         : yCenter;
        int distX = xCenter - edgeX, distY = yCenter - edgeY;
        return distX * distX + distY * distY <= radius * radius;
    }
};
// @lc code=end
