#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	int *arr = new int[n]();
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	stack<int> s;
	int *ans = new int[n]();
	for(int i = 0; i < n; i++){
		while(!s.empty() && arr[s.top()] < arr[i]){
			int index = s.top();
			ans[index] = i;
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty()){
		int i = s.top();
		ans[i] = -1;
		s.pop();
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] + 1 << endl;
	}
	delete[] arr;
	arr = nullptr;
	delete[] ans;
	ans = nullptr;
 	return 0;
}

