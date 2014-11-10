/**
*   Given a 2D binary matrix filled with 0's and 1's, find the largest 
*   rectangle containing all ones and return its area.
*
**/

class Solution {
public:
    int maxHisto(vector<int>& A) {
        stack<int> S;
        int maxArea = 0, i = 0;
        while(i < A.size()) {
            if (S.empty() || A[i] >= A[S.top()])
                S.push(i++);
            else {
                int top = S.top();
                S.pop();
                int area = A[top] * (S.empty() ? i : i - S.top() - 1);
                maxArea = max(maxArea, area);
            }
        }
        
        while (!S.empty()) {
            int top = S.top();
            S.pop();
            int area = A[top] * (S.empty() ? i : i - S.top() - 1);
            maxArea = max(maxArea, area);            
        }
        
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
    
        vector<int> A(n);
        for(int i = 0; i < n; i++)
            A[i] = matrix[0][i]-'0';

        int maxArea=0;
        maxArea = max(maxArea,maxHisto(A));

        for (int i = 1; i < m; i++) {
            for(int j = 0;j < n; j++)
                A[j] = matrix[i][j] == '1'? A[j] + 1 : 0;
            maxArea = max(maxArea,maxHisto(A));
        }
        return maxArea;
    }
};