#include <stdio.h>
#define SIZE 7　//配列の最大サイズ
#define ERR 0.000001　// 許容誤差
#define LOW 1.0　// 探索範囲の下限
#define HIGH 3.0　// 探索範囲の上限

// プロトタイプ宣言
float proot( float *, int, float, float, float );
float polyf( float *, int, float );

int main() {
float a[SIZE], rir;int i, n;

printf("input data of polynomial\n" );
n = SIZE - 1;

// 多項式の係数を入力（a[0]から順に格納）
for ( i = 0; i < SIZE; i++ ) {
printf( "a[%2d]=", i);
// EOFの場合は、そこまでの次数をnにセット
if ( scanf( "%f", &a[i] ) == EOF ) {
 n = i - 1;
 break;
 }
}

// 二分法を用いて根(1+IRR)を計算
rir = proot( a, n, ERR, LOW, HIGH );

// 結果の判定と表示
if ( rir < LOW ) printf( "\nThere is no solution within the region.\n" );
else printf( "\ninternal rate of return: %f\n", rir - 1.0 ); // 求めたいのは利回りなので、計算結果から1.0を引いて表示
return 0;
}

// 二分法により根を求める関数
float proot( float *a, int n, float err, float xa, float xb ) {
float x1, x2, x;
x1 = xa;
x2 = xb;

// 指定された範囲の両端で関数の符号が同じ場合、その範囲に根はないと判断
if ( polyf( a, n, x1 ) * polyf( a, n, x2 ) > 0.0 )return ( xa - 1.0 );

// 誤差が許容範囲内に収まるまで範囲を半分に絞り込んでいく
while ( x2 - x1 >= err ) {x = ( x1 + x2 )/2.0; // 中間点を計算

// 中間点と右端の符号が同じなら、根は左側にあるので右端を更新
if ( polyf( a, n, x ) * polyf( a, n, x2 ) > 0.0 ) x2 = x;
else x1 = x; // そうでなければ根は右側にあるので左端を更新
}
return x2; // 近似解を返す
}

// ホーナー法に準じた形式で多項式の値を計算する関数
// y=a[0]*x^n + a[1]*x^(n-1) + ... + a[n]
float polyf( float *a, int n, float x ) {
int i;
float y;
y = *a;　// 先頭の係数
for ( i = 1; i <= n; i++ ) y = y*x + (*(a+i));　// 逐次的に計算
return y;
}