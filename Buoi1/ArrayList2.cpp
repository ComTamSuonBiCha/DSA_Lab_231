#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations) {
    for(unsigned int i =0;i< operations.size();i++)
    {
        for (int j= operations[i][0] ; j<= operations[i][1]; j++)
        {
            nums[j]+=operations[i][2];
        }
    }
    return nums;
}   
int buyCar(int* nums, int length, int k)
{
    sort(nums, nums+length);
    int count=0;
    for(int i=0;i<length;i++)
    {
        if (k<0) break;
        if (nums[i] <= k)
        {
            count ++;
            k -= nums[i];
        }
    }
    return count;
}
bool consecutiveOnes(vector<int>& nums) {
    int count =0;
    int idx1=0;
    while(idx1 < nums.size())
    {
        if (nums[idx1] == 1)
        {
            break;
            count++;
        }
        idx1++;
    }
    int idx2=idx1;
    for (int i=idx1+1;i<nums.size();i++)
    {
        if (nums[i] == 1)
        {
            count ++;
            idx2=i;
        }
    }
    bool ans = ((idx2 - idx1) == count) ? 1 : 0;
    return ans;
}
int equalSumIndex(vector<int>& nums) {
    // STUDENT ANSWER
    int i=0, j=nums.size()-1;
    int sum1 = nums[i] , sum2 = nums[j];
    while(i < j)
    {
        if (sum1 <= sum2)
        {
            sum1 += nums[i];
            i++;
        }
        else if (sum1 > sum2)
        {
            sum2 += nums[j];
            j--;
        }
    }
    if (i==j) return i;
    else return -1;
}
int longestSublist(vector<string>& words) {
    int longestLength = 0;
    int currentLength = 1;  // Initialize to 1 since a single word is a valid subarray.
    
    for (int i = 1; i < words.size(); i++) {
        // Check if the current word has the same first letter as the previous word.
        if (words[i][0] == words[i - 1][0]) {
            currentLength++;  // Increment the current subarray length.
        } else {
            // If the first letters are different, update the longest length if needed.
            if (currentLength > longestLength) {
                longestLength = currentLength;
            }
            currentLength = 1;  // Reset the current subarray length.
        }
    }
    
    // After the loop, check one more time for the longest subarray.
    if (currentLength > longestLength) {
        longestLength = currentLength;
    }
    
    return longestLength;
}