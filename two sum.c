#include <stdio.h>
void twoSum(int nums[], int target, int size, int result[]) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return;
            }
        }
    }
}
int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int size = sizeof(nums) / sizeof(nums[0]);
    int result[2];
    twoSum(nums, target, size, result);
    printf("Indices: [%d, %d]\n", result[0], result[1]);
    return 0;
}
