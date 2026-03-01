#include <stdio.h>

// プロトタイプ宣言：xに対する二次関数の値を返す
int nizi(short);
int main() {
short i, j, n;

// xの値を-7から7まで変化させてループ
for (i=-7; i<=7; i++) {
	// 関数を呼び出して y=x^2+4 の値を計算
n=nizi(i);

// 現在のxの値を表示
printf("%2d ",i);

// 計算された値nの数だけ文字'a'を横に並べて表示（簡易グラフ）
for (j=1; j<=n; j++ ) printf("a");

// 改行して次のxの値へ
printf("\n");
}
return 0;
}

// 二次関数　y=x^2+4　を計算する関数
int nizi(short x) {
return (x*x+4);
}