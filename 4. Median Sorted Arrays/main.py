from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # Гарантируем, что nums1 — меньший массив
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        m, n = len(nums1), len(nums2)
        left, right = 0, m

        while left <= right:
            # Точка разбиения в nums1
            partition1 = (left + right) // 2
            # Точка разбиения в nums2
            partition2 = (m + n + 1) // 2 - partition1

            # Граничные элементы разбиения
            maxLeft1 = nums1[partition1 - 1] if partition1 > 0 else float('-inf')
            minRight1 = nums1[partition1] if partition1 < m else float('inf')

            maxLeft2 = nums2[partition2 - 1] if partition2 > 0 else float('-inf')
            minRight2 = nums2[partition2] if partition2 < n else float('inf')

            # Проверяем корректность разбиения
            if maxLeft1 <= minRight2 and maxLeft2 <= minRight1:
                # Если общее число элементов чётное
                if (m + n) % 2 == 0:
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2
                # Если общее число элементов нечётное
                else:
                    return max(maxLeft1, maxLeft2)
            elif maxLeft1 > minRight2:
                right = partition1 - 1
            else:
                left = partition1 + 1

nums1 = [1, 5, 6, 7]
nums2 = [2, 3, 4]
solve = Solution()
print(format(solve.findMedianSortedArrays(nums1, nums2), '.5f'))  # Вывод: 4.0


# class Solution(object):
#     def findMedianSortedArrays(self, nums1, nums2):
#         array = []
#         needed = (len(nums1) + len(nums2)) // 2 + (len(nums1) + len(nums2)) % 2

#         if nums1[len(nums1) // 2 + len(nums1) % 2] > nums2[len(nums2) // 2 + len(nums2) % 2]:
#             array.extend(nums2[:len(nums2) // 2 + len(nums2) % 2])
#             needed -= len(nums2) // 2 + len(nums2) % 2
#             nums1 = nums1[:len(nums1) // 2 + len(nums1) % 2]
#             print(array)
#         else:
#             array.extend(nums1[:len(nums1) // 2 + len(nums1) % 2])
#             needed -= len(nums1) // 2 + len(nums1) % 2
#             nums2 = nums2[:len(nums2) // 2 + len(nums2) % 2]
#             print(array)


#         return float(array[len(array) // 2])
#         # return format(result, '.5f')
    

# solve = Solution()
# print(solve.findMedianSortedArrays([1, 2, 3, 4], [5, 6, 7]))
# print()
# print(solve.findMedianSortedArrays([1, 2, 3,], [5, 6, 7]))
# print()
# print(solve.findMedianSortedArrays([1, 5, 6, 7], [2, 3, 4, 5]))
# print()