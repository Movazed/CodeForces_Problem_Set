from collections import deque

class Solution(object):
    def longestSubarray(self, nums, limit):
        increase = deque()
        decrease = deque()
        max_length = 0
        left = 0

        for right in range(len(nums)):
            while increase and nums[right] < increase[-1]:
                increase.pop()
            increase.append(nums[right])
            
            while decrease and nums[right] > decrease[-1]:
                decrease.pop()
            decrease.append(nums[right])
            
            while decrease[0] - increase[0] > limit:
                if nums[left] == increase[0]:
                    increase.popleft()
                if nums[left] == decrease[0]:
                    decrease.popleft()
                left += 1
                
            max_length = max(max_length, right - left + 1)
        
        return max_length
        
        """
        :type nums: List[int]
        :type limit: int
        :rtype: int
        """

if __name__ == "__main__":
    solution = Solution()
    
    # Test cases
    nums1 = [8, 2, 4, 7]
    limit1 = 4
    result1 = solution.longestSubarray(nums1, limit1)
    print(f"Test case 1: nums = {nums1}, limit = {limit1} => Longest subarray length = {result1}")

    nums2 = [10, 1, 2, 4, 7, 2]
    limit2 = 5
    result2 = solution.longestSubarray(nums2, limit2)
    print(f"Test case 2: nums = {nums2}, limit = {limit2} => Longest subarray length = {result2}")

    nums3 = [4, 2, 2, 2, 4, 4, 2, 2]
    limit3 = 0
    result3 = solution.longestSubarray(nums3, limit3)
    print(f"Test case 3: nums = {nums3}, limit = {limit3} => Longest subarray length = {result3}")
