//run time 20ms
TreeNode* sArrayToBST(int* pNums, int iSize)
{
    if (iSize <= 0)
        return NULL;
    --iSize;
    int iHalfSize = iSize / 2;
    TreeNode* newNode = new TreeNode(pNums[iHalfSize]);
    if (iHalfSize < iSize)
    {
        newNode->right = sArrayToBST(pNums + iHalfSize + 1, iSize - iHalfSize);
    }
    if (iHalfSize > 0)
    {
        newNode->left = sArrayToBST(pNums, iHalfSize);
    }
    return newNode;
}
    
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sArrayToBST(&(nums[0]), nums.size());
}