#include <stdio.h>

// 円周率を定義
#define PAI 3.1415926535897932384626433832795

// プロトタイプ宣言：数値の二乗を計算する関数
float sqr(float x);

int main(){
float r,S;

// 半径の入力を受け付ける
printf("radius = ");
scanf("%f",&r);
// 円の面積S=πr^2を計算
// 自作したsqr関数で半径を二乗している
S=PAI*sqr(r);

// 計算結果を出力
printf("S = %f\n",S);
return 0;
}

// 数値を二乗して返す関数
float sqr(float x){
return(x*x);
}