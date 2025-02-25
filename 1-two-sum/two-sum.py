# practicing some with Python to brush up
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        parsed_value_dictionary = {}
        for index, num in enumerate(nums):
            complement = target - num
            if complement in parsed_value_dictionary:
                # return complement's index, which is second element in dictionary, 
                # and current index, of num.
                return [parsed_value_dictionary[complement], index]
            else:
                # complement hasn't been found yet, we add current num as key to help with finding, 
                # and the nums index as value, so we can add it to the list for returning
                parsed_value_dictionary[num] = index