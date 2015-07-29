//run time 4ms
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize <= 0)
        return NULL;
    --numsSize;
    int iHalfSize = numsSize / 2;
    struct TreeNode* newNode = malloc(sizeof(struct TreeNode));
    newNode->val = nums[iHalfSize];
    newNode->left = newNode->right = NULL;
    if (iHalfSize < numsSize)
    {
        newNode->right = sortedArrayToBST(nums + iHalfSize + 1, numsSize - iHalfSize);
    }
    if (iHalfSize > 0)
    {
        newNode->left = sortedArrayToBST(nums, iHalfSize);
    }
    return newNode;
}