#include <iostream>
#include <unordered_set>
using namespace std;

int longestConsecutiveSequence(int nums[], int size) {
    unordered_set<int> numSet;
    for (int i = 0; i < size; i++) numSet.insert(nums[i]);

    int longestSeq = 0;
    for (int i = 0; i < size; i++) {
        int num = nums[i];
        if (numSet.find(num - 1) == numSet.end()) {
            int current = num;
            int length = 1;
            while (numSet.find(current + 1) != numSet.end()) {
                current++;
                length++;
            }
            if (length > longestSeq) longestSeq = length;
        }
    }
    return longestSeq;
}

int main() {
    int nums[] = {10, 5, 12, 3, 55, 30, 4, 11, 2};
    int size = sizeof(nums) / sizeof(nums[0]);

    cout << "Longest consecutive sequence length: " << longestConsecutiveSequence(nums, size) << endl;

    int nums2[] = {19, 13, 15, 12, 18, 14, 17, 11};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);

    cout << "Longest consecutive sequence length: " << longestConsecutiveSequence(nums2, size2) << endl;

    return 0;
}

