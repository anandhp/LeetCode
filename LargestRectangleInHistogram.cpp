/**
*   Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
*   
*   
*   For example consider histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
*
*
*   The largest rectangle is = 10 unit.
*
**/

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int maxArea = 0;
        stack<int> s;
        int i = 0;
        
        while (i < height.size()) {
            if (s.empty() || height[s.top()] <= height[i])
                s.push(i++);
            else {
                int top = s.top();
                s.pop();
                int area = height[top] * (s.empty() ? i : i - s.top() - 1);
                maxArea = max(maxArea, area);
            }
        }
        while (!s.empty()) {
            int top = s.top();
            s.pop();
            int area = height[top] * (s.empty() ? i : i - s.top() - 1);
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};