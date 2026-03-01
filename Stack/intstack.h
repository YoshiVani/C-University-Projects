#ifndef __intstack
#define __intstack

// スタックを管理するための構造体定義
typedef struct{
	int max;　// スタックの最大容量（格納できる要素数）
	int ptr;　// スタックポインタ（現在格納されている要素数・次の挿入位置）
	int *stk;　// スタックの本体となる配列へのポインタ
}IntStack;

// スタックを初期化する関数
// max: 確保するメモリのサイズ
int initialize(IntStack *s,int max);

// スタックにデータ x を挿入する関数
int push(IntStack *s,int x);
	
// スタックからデータを取り出し、x に格納する関数
int pop(IntStack *s,int *x);
	
// スタックの全要素を表示する関数
void print(const IntStack *s);
#endif
