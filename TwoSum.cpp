/**
*   Given an array of integers, find two numbers such that they add up to a specific target number.
*
*   The function twoSum should return indices of the two numbers such that they add up to the target, 
*   where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
*   
*   You may assume that each input would have exactly one solution.
*   Input: numbers={2, 7, 11, 15}, target=9
*   Output: index1=1, index2=2
*
**/

class Solution {
public:

    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> indexedTargetMap;
        vector<int> indices;
        map<int,int>::iterator it;
        
        int numbersSize = numbers.size(); 
        for (int i = 0; i < numbersSize; i++) {
            indexedTargetMap.insert(pair<int, int>(numbers[i], i)); 
        }
        
        for (int i = 0; i < numbersSize; i++) {
            it = indexedTargetMap.find(target - numbers[i]);
            if ( it != indexedTargetMap.end() && it->second != i) {
                if (i < it->second) {
                    indices.push_back(i + 1);
                    indices.push_back(it->second + 1);
                }
                else {
                    indices.push_back(it->second + 1);                    
                    indices.push_back(i + 1);
                }
                break;
            }
        }
        return indices;
    }
};