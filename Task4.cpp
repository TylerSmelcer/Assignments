
#include <iostream>
using namespace std;

int highestProduct(int nums[], int size) {
    if (size < 2) return 0;

    int max1 = nums[0], max2 = nums[1];
    int min1 = nums[0], min2 = nums[1];

    if (max2 > max1) swap(max1, max2);
    if (min2 < min1) swap(min1, min2);

    for (int i = 2; i < size; i++) {
        int n = nums[i];

        if (n > max2) {
            if (n > max1) {
                max2 = max1;
                max1 = n;
            } else {
                max2 = n;
            }
        }

        if (n < min2) {
            if (n < min1) {
                min2 = min1;
                min1 = n;
            } else {
                min2 = n;
            }
        }
    }

    int prodMax = max1 * max2;
    int prodMin = min1 * min2;

    return (prodMax > prodMin) ? prodMax : prodMin;
}

int main() {
    int nums[] = {5, -10, -6, 9, 4};
    int size = sizeof(nums) / sizeof(nums[0]);

    cout << "Highest product of any two numbers: " << highestProduct(nums, size) << endl;
    return 0;
}
