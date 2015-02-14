/**
*   Given an array of size n, find the majority element. The majority 
*   element is the element that appears more than n/2 times.
*
*   You may assume that the array is non-empty and the majority element 
*   always exist in the array.
*
**/

class Solution {
public:
    int majorityElement(vector<int> &num) {
        map<int, int> numMap;
        int majority = 0, majorityElement;
        for (int i = 0; i < num.size(); i++) {
            int element = num[i];
            if (numMap.find(element) == numMap.end())
                numMap.insert(make_pair(element, 0));
            numMap[element]++;
            if (majority < numMap[element]) {
                majority = numMap[element];
                majorityElement = element;
            }
        }
        return majorityElement;
    }
};