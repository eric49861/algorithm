#include <iostream>
#include <deque>
 
using namespace std;

const int SIZE = 500001;
int arr[SIZE] = {0};
int preSum[SIZE]= {0};

int main(int argc, char **argv)
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> arr[i];	
	}
	//ÇóÇ°×ººÍ
	preSum[0] = arr[0];
	for(int i = 1; i < n; i++){
		preSum[i] = arr[i] +preSum[i - 1];
	}
	deque<int> q;
	int ans = preSum[0];
	for(int i = 0; i < n; i++){
		while(!q.empty() && i - q.front() > m){
			q.pop_front();
		}
		if(q.empty()){
			ans = max(ans, preSum[i]);
		}else{
			ans = max(ans, preSum[i] - preSum[q.front()]);
		}
		while(!q.empty() && preSum[q.back()] >= preSum[i]){
			q.pop_back();
		}
		q.push_back(i);
	}
	cout << ans << endl;
 	return 0;
}

