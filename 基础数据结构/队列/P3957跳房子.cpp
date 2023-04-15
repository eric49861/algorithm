#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(int argc, char **argv)
{
	int n, d, k;
	cin >> n >> d >> k;
	vector<vector<int>> arr;
	int xi = 0;
	int si = 0;
	for(int i = 0; i < n; i++){
		vector<int> temp;
		cin >> xi >> si;
		temp.push_back(xi);
		temp.push_back(si);
		arr.push_back(temp);
	}
	int *dp = new int[n]();
	
	deque<int> q;
	for(int i = 0; i < n; i++){
		while(!q.empty() && )
	}
 	return 0;
}

