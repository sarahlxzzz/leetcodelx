class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        // Step 1: Sort the array
        std::sort(nums.begin(), nums.end());
        
        // Initialize with a fallback sum from the first three elements
        int closestSum = nums[0] + nums[1] + nums[2];
        
        // Step 2: Iterate through the array fixing the first element
        for (int i = 0; i < n - 2; ++i) {
            // Optional: Skip duplicate values for the fixed element to optimize speed
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = n - 1;
            
            // Step 3: Two-pointer technique
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // If this sum is closer to target than our previous closestSum, update it
                if (std::abs(target - currentSum) < std::abs(target - closestSum)) {
                    closestSum = currentSum;
                }
                
                // Move pointers based on the comparison to the target
                if (currentSum < target) {
                    left++;
                } else if (currentSum > target) {
                    right--;
                } else {
                    // Exact match found
                    return currentSum;
                }
            }
        }
        
        return closestSum;
        
    }
};