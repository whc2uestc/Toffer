#include <stdio.h>
#include <stack>
#include <list>
using namespace std;

int main21(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i = 0;
		stack<int> sta;
		stack<int> vec;
		while(i < n){
			char ci;
			int num;
			scanf("\n%c",&ci);
			if(ci == 's'){
				scanf("%d",&num);
				sta.push(num);
				if(vec.empty())
					vec.push(num);
				else{
					vec.push((num<vec.top()?num:vec.top()));
				}
				printf("%d\n",vec.top());
			}
			else{
				if(sta.empty())
					printf("NULL\n");
				else{
					sta.pop();
					vec.pop();
					if(vec.empty())
						printf("NULL\n");
					else
						printf("%d\n",vec.top());
				}
			}
			i ++;
		}
	}

	return 0;
}