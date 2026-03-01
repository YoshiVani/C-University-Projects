#include<stdio.h>
#include<math.h>
int main(){
	double a,b,c,s,A;
	
	// 3辺の入力を繰り返し受け付ける
	while(printf("a b c : "),scanf("%lf%lf%lf",&a,&b,&c)!=EOF){
		// 三角形の成立条件：2辺の和が他の一辺より大きく、かつ2辺の差の絶対値より大きい
		if(a+b>c && c>fabs(a-b)){
			// 計算された面積 A を表示
			printf("Area of triangle is %lf\n",A);
		}
			else printf("No triangle.\n");
	// ヘロンの公式に必要な s を計算
	s=(a+b+c)/2;
	// ヘロンの公式：面積A=sqrt(s*(s-a)*(s-b)*(s-c))
	A=sqrt(s*(s-a)*(s-b)*(s-c));
		}
		return 0;
	}