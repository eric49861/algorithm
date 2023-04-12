#include <iostream>
#include <queue>

using namespace std;

void implementWithQueue();
void implementWithLinkedList();


int main(int argc, char **argv){
	implementWithLinkedList();
	
	return 0;
}

void implementWithQueue(){
	int n, m;
	cin >> n >> m;
	queue<int> q;
	for(int i = 1; i <= n; i++){
		q.push(i);
	}
	while(!q.empty()){
		int count = m;
		int front;
		while(count-- > 1){
			front = q.front();
			q.pop();
			q.push(front);
		}
		front = q.front();
		q.pop();
		cout << front << " ";
	}
}

struct Node{
	int value;
	Node *next;
	Node();
	Node(int, Node*);
};
Node::Node(){};
Node::Node(int v, Node *next=nullptr){
	this->value = v;
	this->next = next;
};

void implementWithLinkedList(){
	int n, m;
	cin >> n >> m;
	Node *p = new Node(1);
	Node *temp = p;
	for(int i = 2; i <= n; i++){
		if(i == n){
			temp->next = new Node(i, p);
		}else{
			temp->next = new Node(i);
			temp = temp->next;
		}
	}
	Node *pre = temp->next;
	while(p != p->next){
		int count = m;
		while(count-- > 1){
			pre = p;
			p = p->next;
		}
		cout << p->value << " ";
		//删除当前节点
		pre->next = p->next;
		delete p;
		p = pre->next;
	}
	cout << p->value << " ";
	delete p;
	p = nullptr;
}





