//run time 8ms
void diffWaysToComputeRst(char* str, int strLength, vector<int>& vec_operatorPos, vector<int>& vec_iRst){
	if (vec_operatorPos.size() <= 0)
	{
		vec_iRst.push_back(atoi(str));
		return;
	}
	for (unsigned int i = 0; i < vec_operatorPos.size(); ++i)
	{
		vector<int> vec_iFirstSub, vec_iSecondSub;
		vector<int> vec_iFirstSubOpPos, vec_iSecondSubOpPos;
		int iOperatorPos = vec_operatorPos[i];
		for (unsigned int j = 0; j < i; ++j)
		{
			vec_iFirstSubOpPos.push_back(vec_operatorPos[j]);
		}
		for (unsigned int j = i + 1; j < vec_operatorPos.size(); ++j)
		{
			vec_iSecondSubOpPos.push_back(vec_operatorPos[j] - iOperatorPos - 1);
		}
		char* strFirstSub = new char[iOperatorPos];
		strncpy(strFirstSub, str, iOperatorPos);
		diffWaysToComputeRst(strFirstSub, iOperatorPos, vec_iFirstSubOpPos, vec_iFirstSub);
		delete []strFirstSub;
		diffWaysToComputeRst(str + iOperatorPos + 1, strLength - 1 - iOperatorPos, vec_iSecondSubOpPos, vec_iSecondSub);
		if (str[iOperatorPos] == '+')
		{
			for (int i = 0; i < vec_iFirstSub.size(); ++i)
			{
				for (int j = 0; j < vec_iSecondSub.size(); ++j)
				{
					vec_iRst.push_back(vec_iFirstSub[i] + vec_iSecondSub[j]);
				}
			}
		}
		else if (str[iOperatorPos] == '-')
		{
			for (int i = 0; i < vec_iFirstSub.size(); ++i)
			{
				for (int j = 0; j < vec_iSecondSub.size(); ++j)
				{
					vec_iRst.push_back(vec_iFirstSub[i] - vec_iSecondSub[j]);
				}
			}
		}
		else if (str[iOperatorPos] == '*')
		{
			for (int i = 0; i < vec_iFirstSub.size(); ++i)
			{
				for (int j = 0; j < vec_iSecondSub.size(); ++j)
				{
					vec_iRst.push_back(vec_iFirstSub[i] * vec_iSecondSub[j]);
				}
			}
		}
	}
	return;
}
vector<int> diffWaysToCompute(string input) {
	char *cstr = new char[input.length() + 1];
	strcpy(cstr, input.c_str());
	vector<int> vec_iRst;
	vector<int> vec_operatorPos;
	for (unsigned int i = 0; i < input.length(); ++i)
	{
		if (cstr[i] == '+' || cstr[i] == '-' || cstr[i] == '*')
		{
			vec_operatorPos.push_back(i);
		}
	}
	diffWaysToComputeRst(cstr, input.length(), vec_operatorPos, vec_iRst);
	delete [] cstr;
	return vec_iRst;
}