//run time 1140ms
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int iRow = matrix.size();
	if (iRow <= 0)
		return false;
	int iCol = matrix[0].size();
	if (iCol <= 0)
		return false;
	if (matrix[0][0] > target)
		return false;
	if (matrix[iRow - 1][iCol - 1] < target)
		return false;
	int iMaxDiag = (iRow < iCol) ? iRow : iCol;
	int iDiagCheck = 0;
	for (; iDiagCheck < iMaxDiag; ++iDiagCheck)
	{
		int iCurEntry = matrix[iDiagCheck][iDiagCheck];
		if (iCurEntry == target)
			return true;
		else if (iCurEntry < target)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	if (iDiagCheck == iMaxDiag)
	{
		if (iRow > iCol)
		{
			for (; iDiagCheck < iRow; ++iDiagCheck)
			{
				if (std::binary_search(matrix[iDiagCheck].begin(), matrix[iDiagCheck].end(), target))
					return true;
			}
			return false;
		}
		else if (iRow < iCol)
		{
			for (int i = 0; i < iRow; ++i)
			{
				if (std::binary_search(matrix[i].begin() + iDiagCheck, matrix[i].end(), target))
					return true;
			}
			return false;
		}
		else 
			return false;
	}
	else
	{
		for (int i = iDiagCheck; i < iRow; ++i)
		{		
			if (std::binary_search(matrix[i].begin(), matrix[i].begin() + iDiagCheck, target))
			{
				return true;
			}
		}
		for (int i = 0; i < iDiagCheck; ++i)
		{
			if (std::binary_search(matrix[i].begin() + iDiagCheck, matrix[i].end(), target))
				return true;
		}
		return false;
	}
}
//run time 1160ms
/*bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int iRow = matrix.size();
	if (iRow <= 0)
		return false;
	int iCol = matrix[0].size();
	if (iCol <= 0)
		return false;
	if (matrix[0][0] > target)
		return false;
	if (matrix[iRow - 1][iCol - 1] < target)
		return false;
	int iMaxDiag = (iRow < iCol) ? iRow : iCol;
	int iDiagCheck = 0;
	for (; iDiagCheck < iMaxDiag; ++iDiagCheck)
	{
		int iCurEntry = matrix[iDiagCheck][iDiagCheck];
		if (iCurEntry == target)
			return true;
		else if (iCurEntry < target)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	if (iDiagCheck == iMaxDiag)
	{
		if (iRow > iCol)
		{
			for (; iDiagCheck < iRow; ++iDiagCheck)
			{
				if (std::binary_search(matrix[iDiagCheck].begin(), matrix[iDiagCheck].end(), target))
					return true;
			}
			return false;
		}
		else if (iRow < iCol)
		{
			for (int i = 0; i < iRow; ++i)
			{
				if (std::binary_search(matrix[i].begin() + iDiagCheck, matrix[i].end(), target))
					return true;
			}
			return false;
		}
		else 
			return false;
	}
	else
	{
		for (int i = iDiagCheck; i < iRow; ++i)
		{		
			if (std::binary_search(matrix[i].begin(), matrix[i].begin() + iDiagCheck, target))
			{
				return true;
			}
		}
		for (int i = 0; i < iDiagCheck; ++i)
		{
			if (std::binary_search(matrix[i].begin() + iDiagCheck, matrix[i].end(), target))
				return true;
		}
		return false;
	}
}*/