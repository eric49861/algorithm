#include <iostream>
#include <deque>
using namespace std;

int main(int argc, char **argv)
{
	deque<int> q;
	
	int n, k;
	cin >> n >> k;
	int *arr = new int[n]();
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < n; i++){
		//入队操作 
		while(!q.empty() && arr[i] < arr[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
		if(i >= k - 1){
			//删头
			while(!q.empty() && i - q.front() >= k){
				q.pop_front();
			}
			cout << arr[q.front()] << " ";
		}
	}
	cout << endl;
	q.clear();
	for(int i = 0; i < n; i++){
		while(!q.empty() && arr[i] > arr[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
		if(i >= k - 1){
			while(!q.empty() && i - q.front() >= k){
				q.pop_front();
			}
			cout << arr[q.front()] << " ";
		}
	}
	cout << endl;
 	return 0;
}

