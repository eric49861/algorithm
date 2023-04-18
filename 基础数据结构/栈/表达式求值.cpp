#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char **argv){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	stack<int> is;
    stack<char> cs;

    char c = 0;
    int now = 0;
    while(true){
        c = getchar();
        if(c == '\n' || c == EOF){
            is.push(now % 10000);
            break;
        }
        if(isdigit(c) != 0){
            now = now * 10 + (c - '0');
        }else{
            is.push(now % 10000);
            now = 0;
            switch(c){
                case '+':{
					if(!cs.empty()){
                        while(!cs.empty() && cs.top() == '*'){
                            int num1 = is.top(); is.pop();
                            int num2 = is.top(); is.pop();
                            is.push((num1 * num2) % 10000);
                            cs.pop();
                        }
                    }
                    cs.push(c);
                    break;
                }
                case '*':{
                	cs.push(c);
					break;
				}
					
            }
        }
    }
    while (!cs.empty())
    {
        int num1 = is.top(); is.pop();
        int num2 = is.top(); is.pop();
        if(cs.top() == '+'){
			is.push((num1 + num2) % 10000);
        }else{
			is.push((num1 * num2) % 10000);
        }
        cs.pop();
    }
    
	cout << is.top() << endl;
    return 0;
}
