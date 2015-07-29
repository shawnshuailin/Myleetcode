//run time 248ms
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
{
	vector<vector<int>> vec_VeciDependence(numCourses);
	vector<int> vec_iIndependentFlag(numCourses,1);
	vector<int> vec_iMinimumRequire(numCourses, 0);
	std::vector<int> vec_iActiveSet;
	for (int i = 0; i < prerequisites.size(); ++i)
	{
		std::pair<int, int>& pair_Dependence = prerequisites[i];
		vec_VeciDependence[pair_Dependence.second].push_back(pair_Dependence.first);
		vec_iIndependentFlag[pair_Dependence.first] = 0;
		++vec_iMinimumRequire[pair_Dependence.first];
	}
	for (int i = 0; i < numCourses; ++i)
	{
		if (vec_iIndependentFlag[i] >= 1)
		{
			vec_iActiveSet.push_back(i);
		}
	}

	for (int i = 0; i < vec_iActiveSet.size(); ++i)
	{
		int iCurActiveIdx = vec_iActiveSet[i];
		vector<int>& vec_iCurDependence = vec_VeciDependence[iCurActiveIdx];
		for (int j = 0; j < vec_iCurDependence.size(); ++j)
		{
			++vec_iIndependentFlag[vec_iCurDependence[j]];
			if (vec_iIndependentFlag[vec_iCurDependence[j]] >= vec_iMinimumRequire[vec_iCurDependence[j]])
			{
				vec_iActiveSet.push_back(vec_iCurDependence[j]);
			}
		}
	}
	return (vec_iActiveSet.size() >= numCourses);
}