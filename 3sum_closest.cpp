//run time 20ms
int threeSumClosest(vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    return target - sumClosestRst(nums, target, 3, nums.size());
}
int sumClosestRst(vector<int>& nums, int target, int iRemain, int iMaxIdx)
{    
    int iCurClosestRst, iCurClosestRstAbs;
        
    if (iRemain == 1)
    {
        iCurClosestRst = 0;
        if (iMaxIdx > 0)
        {
            if (target <= nums[0])
            {
                iCurClosestRst= target - nums[0];
                iCurClosestRstAbs = std::abs(iCurClosestRst);
            }
            else if (target >= nums[iMaxIdx - 1])
            {
                iCurClosestRst= target - nums[iMaxIdx - 1];
                iCurClosestRstAbs = std::abs(iCurClosestRst);
            }
            else
            {
                int iMaxBoundIdx = iMaxIdx - 1;
                int iMinBoundIdx = 0;
                while (1)
                {
                    if (iMaxBoundIdx - iMinBoundIdx <= 1)
                        break;
                    int iCurIdx = (iMaxBoundIdx + iMinBoundIdx) / 2;
                    if (target == nums[iCurIdx])
                    {
                        return 0;
                    }
                    else if (target < nums[iCurIdx])
                    {
                        iMaxBoundIdx = iCurIdx;
                    } 
                    else if (target > nums[iCurIdx])
                    {
                        iMinBoundIdx = iCurIdx;
                    } 
                }
                iCurClosestRst= target - nums[iMaxBoundIdx];
                iCurClosestRstAbs = std::abs(iCurClosestRst);
                if (std::abs(target - nums[iMinBoundIdx]) < iCurClosestRstAbs)
                {
                    iCurClosestRst = target - nums[iMinBoundIdx];
                }
            }
        }
        return iCurClosestRst;
    }
        
    iCurClosestRstAbs = -1;
    int iCurBranchRst;
    int iLastNum = nums[iMaxIdx - 1]; 
    iCurBranchRst = sumClosestRst(nums, target - iLastNum, --iRemain, --iMaxIdx);
    if (iCurBranchRst == 0)
        return 0;
    if (iCurClosestRstAbs < 0 || std::abs(iCurBranchRst) < iCurClosestRstAbs)
    {
        iCurClosestRst = iCurBranchRst;
        iCurClosestRstAbs = std::abs(iCurBranchRst);
    }
        
    if (iMaxIdx > iRemain)
    { 
        iCurBranchRst = sumClosestRst(nums, target, iRemain + 1, iMaxIdx);
        if (iCurBranchRst == 0)
            return 0;
        if (std::abs(iCurBranchRst) < iCurClosestRstAbs)
        {
            iCurClosestRst = iCurBranchRst;
            iCurClosestRstAbs = std::abs(iCurBranchRst);
        }
    }
    return iCurClosestRst;
}