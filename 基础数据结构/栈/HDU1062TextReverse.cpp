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
	getchar();//¶Á×ß»Ø³µ 
	char c;
	while(n--){
		stack<char> s;
		while(true){
			c = getchar();
			if(c == '\n' || c == ' ' || c == EOF){
				while(!s.empty()){
					cout << s.top();
					s.pop();
				}
				if(c == '\n' || c == EOF){
					break;
				}
				cout << " ";
			}else{
				s.push(c);
			}
		}
		cout << endl;
	}

 	return 0;
}
