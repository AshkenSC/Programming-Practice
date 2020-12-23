# 198

from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        current = 0
        prev = 0
        for num in nums:
            temp = max(current, prev + num)
            prev = current
            current = temp
        return current
