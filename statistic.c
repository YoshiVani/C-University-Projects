#include <stdio.h>
int main(){
	int n,ten,good,bad;
	n=0;
	good=0;
	bad=0;
	while(printf("point:\n"),scanf("%d",&ten)!=EOF){
		n++;
		if(80<=ten)good++;
		if (60>ten)bad++;
	}
	printf("number=%d,good amount is %d,bad amount is %d\n",n,good,bad);
	return 0;
}
		