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
	int *ans = new int[n]();
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	stack<int> s;
	for(int i = 0; i < n; i++){
		while(!s.empty() && arr[i] > arr[s.top()]){
			int index = s.top();
			ans[index] = i;
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty()){
		ans[s.top()] = -1;
		s.pop();
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] + 1 << " ";
	}
	cout << endl;
	delete[] arr;
	delete[] ans;
	arr = nullptr;
	ans = nullptr;
 	return 0;
}

