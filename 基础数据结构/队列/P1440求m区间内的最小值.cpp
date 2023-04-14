//该题使用iostream，#2和#10会超时 
#include <cstdio>
#include <deque>
using namespace std;

const int SIZE = 2000001;
int arr[SIZE] = {0};
 
int main(int argc, char**argv){
	
	int n, m;
	scanf("%d%d", &n, &m);
	deque<int> q;
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		if(i == 0){
			printf("%d\n", 0);
			continue;
		}
		while(!q.empty() && arr[i -1] < arr[q.back()]){
			q.pop_back();
		}
		q.push_back(i - 1);
		
		while(!q.empty() && i - q.front() > m){
			q.pop_front();
		}
		printf("%d\n", arr[q.front()]);
	}
	return 0;
}
