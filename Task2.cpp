
#include <iostream>
using namespace std;

int findMissingNumber(int nums[], int size) {
    int n = size;
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;

    for (int i = 0; i < size; i++) {
        actualSum += nums[i];
    }

    return expectedSum - actualSum;
}

int main() {
    int nums1[] = {2, 3, 0, 6, 1, 5};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    cout << "Missing number: " << findMissingNumber(nums1, size1) << endl;

    int nums2[] = {8, 2, 3, 9, 4, 7, 5, 0, 6};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    cout << "Missing number: " << findMissingNumber(nums2, size2) << endl;

    return 0;
}
