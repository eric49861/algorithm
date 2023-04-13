#include <iostream>

int left[100001] = {0};
int right[100001] = {0};

void insertLeft(int, int);
void insertRight(int, int);
void del(int);

int main(int argc, char **argv){
	int N;
	std::cin >> N;
	for(int i = 2; i <= N; i++){
		int k, p;
		std::cin >> k >> p;
		if(p == 0){
			//left
			insertLeft(k, i);
		}else{
			//right
			insertRight(k, i);
		}
	}
	int M;
	std::cin >> M;
	int x;
	while(M--){
		std::cin >> x;
		del(x);
	}
	//找到头结点 left[head] = 0
	int head = -1;
	for(int i = 1; i <= N; i++){
		if(left[i] == 0){
			head = i;
			break;
		}
	}
	//从头遍历链表
	while(head != 0){
		std::cout << head << " ";
		head = right[head];
	}
	return 0;
}

void insertLeft(int k, int i){
	int l = left[k];
	right[l] = i;
	right[i] = k;
	left[i] = l;
	left[k] = i;
}

void insertRight(int k, int i){
	int r = right[k];
	right[k] = i;
	left[i] = k;
	left[r] = i;
	right[i] = r;
}

void del(int x){
	if(left[x] == -1 && right[x] == -1){
		return;
	}
	int l = left[x];
	int r = right[x];
	right[l] = r;
	left[r] = l;
	
	left[x] = -1;
	right[x] = -1;
}
