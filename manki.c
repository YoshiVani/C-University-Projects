#include<stdio.h>

int main(){
	int i,n,gankin;
	float r,S,sisu;
	
	// 満期金額、利率、期間の入力を受け付ける
	printf("Muturity_amount interest_rate years");
	scanf("%f%f%d",&S,&r,&n);
	
	// 複利計算の係数(1+r)^nを求めるためのループ処理
	for (sisu=1.0,i=1;
	i<=n;
	i++)
	// 利率rを100で割り、1を加えたものを期間n回分掛け合わせる
	{sisu*=1+r/100;
	}
	
	// 元金=満期金額/(1+利率)^期間
	gankin=S/sisu;
	
	// 計算結果の出力
	printf("principal = %d\n",gankin);
	printf("interest rate = %fpercent\n",r);
	printf("years = %d\n",n);
	printf("maturity amount = %f\n",S);
	return 0;
}