int removeElement(int* nums, int numsSize, int val) {
    int result[1000];
    int j = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            result[j] = nums[i];
            j++;
        }
    }
    for(int k=0;k<j;k++)nums[k]=result[k];
    return j;
}