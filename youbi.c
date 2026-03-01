#include <stdio.h>

// プロトタイプ宣言：西暦0年からの通算日数を計算する関数
long n1day(int,int,int);
long n2day(int,int,int);
int main(){
	int y1,m1,d1,y2,m2,d2;
	long n1,n2;
	
	// 2つの日付入力を繰り返し受け付ける（Ctrl+Z または Ctrl+D で終了）
	while(printf("Y1 M1 D1,Y2 M2 D2 "),scanf("%d%d%d",&y1,&m1,&d1,&y2,&m2,&d2)!=EOF){
		// それぞれの日付の通算日数を計算
		n1 =n1day(y1,m1,d1);
		n2 =n2day(y2,m2,d2);
		
		// 日数差を表示（n1-n2の絶対値が2日間の差）
		printf("number of days from %d %d %d to %d %d %d = %ld\n",y1,m1,d2,y2,m2,d2,n1-n2);
	}
	return 0;
}

// 日付1の通算日数を求める関数
long n1day(int iy1,int im1,int id1){
	long ny1,nm1;
	ny1 = iy1;
	nm1 = im1;
	
	// 1月と2月は、前年の13月、14月として計算する（閏年計算の都合上）
	if(im1 <= 2){
		ny1--;
		nm1+=12;
	}
	// 経過日数の計算式（ツェラーの公式の応用）
	// 365日 + 閏年補正 - 100年毎の補正 + 400年毎の補正 + 月ごとの日数補正 + 日付
	return (365*ny1+ny1/4-ny1/100+ny1/400+306*(nm1+1)/10+id1-428);
}

// 日付2の通算日数を求める関数（n1dayと同じロジック）
long n2day(int iy2,int im2,int id2){
	long ny2,nm2;
	ny2 = iy2;
	nm2 = im2;
	if(im2 <= 2){
		ny2--;
		nm2+=12;
	}
	return (365*ny2+ny2/4-ny2/100+ny2/400+306*(nm2+1)/10+id2-428);
}