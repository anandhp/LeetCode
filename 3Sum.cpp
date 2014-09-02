/**
*   Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
*
*   Note:
*   Elements in a triplet (a,b,c) must be in non-descending order. (ie, a = b = c)
*   The solution set must not contain duplicate triplets.
*       For example, given array S = {-1 0 1 2 -1 -4},
*   
*       A solution set is:
*       (-1, 0, 1)
*       (-1, -1, 2)
*       
**/ 
   
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int size = num.size();
        vector<vector<int> > sums;
        set<vector<int> > sumSet;
        
        sort(num.begin(), num.end());
        
        for(int i = 0; i < size - 2; i++) {
            if (i > 0 && num[i] == num[i - 1])
                continue;

            for (int j = i + 1, k = size - 1; j < k;) {
                int sum = num[i] + num[j] + num[k];
                if (sum == 0) {
                    vector<int> s;
                    s.push_back(num[i]);
                    s.push_back(num[j]);                    
                    s.push_back(num[k]);
                    sort(s.begin(), s.end());
                    sumSet.insert(s);
                    j++, k--;
                } else if (sum > 0)
                    k--;
                else
                    j++;
            }
        }
        
        for (set<vector<int> >::iterator sit = sumSet.begin(); sit != sumSet.end(); ++sit)
            sums.push_back(*sit);
            
        return sums;
    }
};