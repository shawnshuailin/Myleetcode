bool height(TreeNode* node, int& iNodeHeight)
    {
        int iLeftNodeHeight, iRightNodeHeight;
        iLeftNodeHeight = iRightNodeHeight = 0;
        if (node->left != NULL)
        {
            if(!height(node->left, iLeftNodeHeight))
                return false;
        }
        if (node->right != NULL)
        {
            if(!height(node->right, iRightNodeHeight))
                return false;
        }
        if (std::abs(iLeftNodeHeight - iRightNodeHeight) > 1)
        {
            return false;
        }
        iNodeHeight = (iLeftNodeHeight >= iRightNodeHeight) ? iLeftNodeHeight : iRightNodeHeight;
        ++iNodeHeight;
        return true;
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
        {
            return true;
        }
        int iRootHeight;
        return height(root, iRootHeight);
    }