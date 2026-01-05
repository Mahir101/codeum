"""
Two Pointers - Opposite Direction (Converging Pointers)
Template for sorted array problems
Time: O(n), Space: O(1)
"""

def two_sum_sorted(numbers, target):
    """
    LeetCode 167: Two Sum II - Input Array Is Sorted
    Find two numbers that add up to target.
    Returns 1-indexed positions.
    """
    left, right = 0, len(numbers) - 1
    
    while left < right:
        current_sum = numbers[left] + numbers[right]
        if current_sum == target:
            return [left + 1, right + 1]  # 1-indexed
        elif current_sum < target:
            left += 1
        else:
            right -= 1
    
    return [-1, -1]


def three_sum(nums):
    """
    LeetCode 15: 3Sum
    Find all unique triplets that sum to zero.
    """
    nums.sort()
    result = []
    
    for i in range(len(nums) - 2):
        # Skip duplicates for first number
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        
        left, right = i + 1, len(nums) - 1
        
        while left < right:
            total = nums[i] + nums[left] + nums[right]
            
            if total == 0:
                result.append([nums[i], nums[left], nums[right]])
                
                # Skip duplicates for second number
                while left < right and nums[left] == nums[left + 1]:
                    left += 1
                # Skip duplicates for third number
                while left < right and nums[right] == nums[right - 1]:
                    right -= 1
                
                left += 1
                right -= 1
            elif total < 0:
                left += 1
            else:
                right -= 1
    
    return result


def container_with_most_water(height):
    """
    LeetCode 11: Container With Most Water
    Find two lines that together with x-axis form container with most water.
    """
    left, right = 0, len(height) - 1
    max_area = 0
    
    while left < right:
        # Calculate area
        width = right - left
        current_height = min(height[left], height[right])
        current_area = width * current_height
        max_area = max(max_area, current_area)
        
        # Move pointer with smaller height
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1
    
    return max_area


def is_palindrome(s):
    """
    LeetCode 125: Valid Palindrome
    Check if string is palindrome (alphanumeric only, case-insensitive).
    """
    left, right = 0, len(s) - 1
    
    while left < right:
        # Skip non-alphanumeric from left
        while left < right and not s[left].isalnum():
            left += 1
        # Skip non-alphanumeric from right
        while left < right and not s[right].isalnum():
            right -= 1
        
        # Compare characters
        if s[left].lower() != s[right].lower():
            return False
        
        left += 1
        right -= 1
    
    return True


# Test cases
if __name__ == "__main__":
    # Test two sum sorted
    assert two_sum_sorted([2,7,11,15], 9) == [1, 2]
    assert two_sum_sorted([2,3,4], 6) == [1, 3]
    print("✓ two_sum_sorted")
    
    # Test three sum
    result = three_sum([-1,0,1,2,-1,4])
    assert sorted([sorted(x) for x in result]) == [[-1,-1,2], [-1,0,1]]
    print("✓ three_sum")
    
    # Test container with water
    assert container_with_most_water([1,8,6,2,5,4,8,3,7]) == 49
    assert container_with_most_water([1,1]) == 1
    print("✓ container_with_most_water")
    
    # Test palindrome
    assert is_palindrome("A man, a plan, a canal: Panama") == True
    assert is_palindrome("race a car") == False
    print("✓ is_palindrome")
    
    print("\n✅ All tests passed!")
