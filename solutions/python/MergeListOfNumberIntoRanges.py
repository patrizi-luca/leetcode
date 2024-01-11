# Given a sorted list of numbers, return a list of strings that represent all of the consecutive numbers.
def findRanges(nums):
    if not nums:
        return []

    result = []
    start = end = nums[0]

    for num in nums[1:]:
        if num == end + 1:
            end = num
        else:
            result.append(f"{start}->{end}")
            start = end = num

    result.append(f"{start}->{end}")
    return result

print(findRanges([0, 1, 2, 5, 7, 8, 9, 9, 10, 11, 15]))
# Output: ['0->2', '5->5', '7->11', '15->15']
