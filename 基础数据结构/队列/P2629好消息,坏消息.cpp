#include <iostream>
#include <deque>

using namespace std;

int main(int argc, char **argv)
{	
	int n;
	cin >> n;
	int *arr = new int[n + 1]();
	arr[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	int *preSum = new int[2 * n]();
	preSum[0] = arr[0];
	//求前缀和 
	for(int i = 1; i <= n; i++){
		preSum[i] = preSum[i - 1] + arr[i];
	}
	for(int i = n + 1; i < 2 * n; i++){
		preSum[i] = preSum[i - 1] + arr[i - n];
	}
	
	deque<int> q;
	int ans = 0;
	for(int i = 0; i < 2 * n; i++){
		
		while(!q.empty() && preSum[i] < preSum[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
		while(!q.empty() && i - q.front() >= n){
			q.pop_front();
		}
		//如果当前区间内的最小前缀和大于等于零，此时k成立 
		if(i >= n && preSum[q.front()] - preSum[i - n] >= 0){
			ans++;
		}
	}
	cout << ans << endl;
	
	delete[] arr;
	arr = nullptr;
	delete[] preSum;
	preSum = nullptr;
 	return 0;
}

