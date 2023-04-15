#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	stack<int> s;
	char c;
	int num = 0;
	while((c = getchar()) != '@'){
		if(isdigit(c) != 0){
			num *= 10;
			num += (c - '0');
		}else if(c == '.'){
			s.push(num);
			num = 0;
			continue;
		}else{
			int num1 = s.top();
			s.pop();
			int num2 = s.top();
			s.pop();
			if(c == '*'){
				s.push(num1 * num2);
			}else if(c == '+'){
				s.push(num2 + num1);
			}else if(c == '-'){
				s.push(num2 - num1);
			}else if(c == '/'){
				s.push(num2 / num1);
			}
		}
	}
	cout << s.top() << endl;
 	return 0;
}

