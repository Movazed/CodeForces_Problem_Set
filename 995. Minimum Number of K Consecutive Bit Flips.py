class Solution(object):
    def minKBitFlips(self, nums, k):
        n = len(nums)
        flipped = 0
        res = 0
        isFlipped = [0] * n
        
        for i in range(n):
            if i >= k:
                flipped ^= isFlipped[i - k]
            if flipped == nums[i]:
                if i + k > n:
                    return -1
                isFlipped[i] = 1
                flipped ^= 1
                res += 1
        
        return res
        
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

if __name__ == "__main__":
    solution = Solution()
    
    # Test cases
    nums1 = [0, 1, 0]
    k1 = 1
    result1 = solution.minKBitFlips(nums1, k1)
    print(f"Test case 1: nums = {nums1}, k = {k1} => Minimum K-bit flips = {result1}")

    nums2 = [1, 1, 0]
    k2 = 2
    result2 = solution.minKBitFlips(nums2, k2)
    print(f"Test case 2: nums = {nums2}, k = {k2} => Minimum K-bit flips = {result2}")

    nums3 = [0, 0, 0, 1, 0, 1, 1, 0]
    k3 = 3
    result3 = solution.minKBitFlips(nums3, k3)
    print(f"Test case 3: nums = {nums3}, k = {k3} => Minimum K-bit flips = {result3}")

    nums4 = [1, 1, 1, 1, 0, 0, 0, 0]
    k4 = 4
    result4 = solution.minKBitFlips(nums4, k4)
    print(f"Test case 4: nums = {nums4}, k = {k4} => Minimum K-bit flips = {result4}")
