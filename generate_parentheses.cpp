vector<string> generatePar(int iLeft, int iRight)
{
	string newString;
	vector<string> vec_GenString;
	if (iLeft <= 0)
	{
		newString.resize(iRight, ')');  
		vec_GenString.push_back(newString);
	}
	else
	{
		for (int i = 1; i <= iLeft; ++i)
		{
			newString.clear();
			newString.resize(i, '(');
			if (iLeft > i)
			{
				for (int j = 1; j <= i + iRight; ++j)
				{
					string tmpString(j, ')');
					string leftTmpString = newString;
					leftTmpString.append(tmpString); 
					vector<string> vec_NewString = generatePar(iLeft - i, iRight - j + i);
					for (unsigned int k = 0; k < vec_NewString.size(); ++k)
					{
						vec_GenString.push_back(leftTmpString);
						vec_GenString.back().append(vec_NewString[k]);
					}
				}
			}
			else
			{
				string tmpString(iRight + i, ')');
				newString.append(tmpString); 
				vec_GenString.push_back(newString);
			}			
		}	
	}
	return vec_GenString;
}
vector<string> generateParenthesis(int n) {
	vector<string> vec_String;
	if (n <= 0)
		return vec_String;
	vec_String = generatePar(n, 0);
	return vec_String;
}