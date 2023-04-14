#include <iostream>
using namespace std;

void implementWithDynamicPlan();
void implementWithMonotonicQueue();

int main(int argc, char **argv)
{

 	return 0;
}

void implementWithDynamicPlan(){
	
	int T;
	cin >> T;
	for(int j = 0; j < T; j++){
		int N = 0;
		cin >> N;

		int *arr = new int[N]();
		for(int i = 0; i < N; i++){
			cin >> arr[i];
		}
		int *dp = new int[N]();
		dp[0] = arr[0];
		int max = dp[0];
		int start = 0;
		int end = 0;
		int start_temp = 0;
		for(int m = 1; m < N; m++){
			if(arr[m] > dp[m - 1] + arr[m]){
				dp[m] = arr[m];
				start_temp = m;
			}else{
				dp[m] = dp[m - 1] + arr[m];
			}
			if(dp[m] > max){
				max = dp[m];
				end = m;
				start = start_temp;
			}
		}
		cout << "Case " << j + 1 << ":" << endl;
		cout << dp[end] << " " << start + 1 << " " << end + 1 << endl;
		if(j != T - 1){
			cout << endl;
		}
		delete[] arr;
		arr = nullptr;
		delete[] dp;
		dp = nullptr;
	}
}

void implementWithMonotonicQueue(){
	
}
