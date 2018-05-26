#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

const int INFINITY = -1;
const string NOTHING = "";

struct node
{
	string shortestPath = NOTHING;
	int shortestDistance = INFINITY;
	bool flag = false;
};

int main()
{
	vector<char> vertexSet;

	string line;
	getline(cin,line);
	istringstream sin(line);

	char vertex;
	while(sin>>vertex)
		vertexSet.push_back(vertex);

	vector<int> vector_int(vertexSet.size(),0);
	vector<vector<int>> distanceSet(vertexSet.size(),vector_int);

	for(vector<vector<int>>::size_type x = 0;x < distanceSet.size();++x)
		for(vector<int>::size_type y= 0;y < vertexSet.size();++y)
			cin>>distanceSet[x][y];

	char beginVert;
	vector<node> list(vertexSet.size());
	cin>>beginVert;

	int posi = 0;
	for(vector<int>::size_type t = 0;t < vertexSet.size();++t)
		if(vertexSet[t] == beginVert)
		{
			posi = t;
			break;
		}

	int distance;
	list[posi].shortestDistance = 0;
	list[posi].shortestPath += vertexSet[posi];
	list[posi].flag = true;
	for(vector<vector<int>>::size_type i = 1;i < distanceSet.size();++i)
	{
		for(vector<int>::size_type j = 0;j < vertexSet.size();++j)
			if(distanceSet[posi][j] != INFINITY && list[j].flag == false)
			{
				distance = list[posi].shortestDistance + distanceSet[posi][j];
				if
				(
					(list[j].shortestDistance == INFINITY) ||
					(list[j].shortestDistance > distance)
				)
				{
					list[j].shortestDistance = distance;
					list[j].shortestPath = list[posi].shortestPath + vertexSet[j];
				}
			}
		int minChange = INFINITY;
		for(vector<int>::size_type k = 0;k < list.size();++k)
			if(list[k].flag == false && list[k].shortestDistance != INFINITY)
				if(minChange == INFINITY || list[k].shortestDistance < list[minChange].shortestDistance)
					minChange = k;
		posi = minChange;
		list[posi].flag = true;
	}

	cout<<"Shortest Distance\tShortest Path"<<endl;

	for(vector<int>::size_type m = 0;m < list.size();++m)
		cout<<list[m].shortestDistance<<"\t\t\t"<<list[m].shortestPath<<endl;

	return 0;
}
