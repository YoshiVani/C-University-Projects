#include <stdio.h>
#include <stdlib.h>
#include "intstack.h"

// スタックを初期化する関数
int initialize(IntStack *s,int max){
	s->ptr=0;　// スタックポインタ（現在のデータ数）を0に設定
	
	// 指定された最大要素数分のメモリを動的に確保
	// callocを使用し、確保した領域を0で初期化
	if((s->stk=calloc(max,sizeof(int)))==NULL){
		s->max=0;
		return -1;
	}
	s->max=max;　// 最大容量を設定
	return 0;
}

// スタックにデータを積み上げる関数
int push(IntStack *s,int x){
	// スタックが満杯（ptrがmaxに到達）ならエラーを返す
	if(s->ptr >= s->max)return -1;
	
	s->stk[s->ptr]=x;　// 現在のポインタの位置にデータを格納
	s->ptr++;　// 次の格納位置のためにポインタをインクリメント
	return 0;
}

// スタックからデータを取り出す関数
int pop(IntStack *s,int *x)
{
	// スタックが空（ptrが0以下）ならエラーを返す
	if(s->ptr<=0)return -1;
    s->ptr--;　// ポインタを一つ下げ、最新のデータの位置に合わせる
    *x = s->stk[s->ptr];　// ポインタが指すデータを変数xに格納  
return 0;
}

// スタックの内容を底から順番に表示する関数
void print(const IntStack *s){
	for(int i=0;i < s->ptr;i++)
		printf("%d",s->stk[i]);　// 格納されている要素を順に出力
	putchar('\n');
}
	