/*
Leetcode:15 Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.*/


int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int** threeSum(int* nums, int numsSize, int* returnSize,
               int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);

    int** arr = calloc(numsSize * numsSize, sizeof(int*));
    *returnColumnSizes = (int*)calloc(numsSize * numsSize, sizeof(int));
    int index = 0;
    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int ptr1 = i + 1, ptr2 = numsSize - 1;
        while (ptr1 < ptr2) {
            int sum = nums[i] + nums[ptr1] + nums[ptr2];
            if (sum == 0) {
                arr[index] = (int*)calloc(3, sizeof(int));
                arr[index][0] = nums[i];
                arr[index][1] = nums[ptr1];
                arr[index][2] = nums[ptr2];
                (*returnColumnSizes)[index] = 3;
                index++;

                while (ptr1 < ptr2 && nums[ptr1] == nums[ptr1 + 1])
                    ptr1++;
                while (ptr1 < ptr2 && nums[ptr2] == nums[ptr2 - 1])
                    ptr2--;

                ptr1++;
                ptr2--;
            } else if (sum > 0)
                ptr2--;
            else
                ptr1++;
        }
    }
    *returnSize = index;
    return arr;
}
