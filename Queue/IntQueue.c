#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

// キューを初期化する関数
int Initialize(IntQueue *q,int max){
	// 要素数、先頭位置、末尾位置をすべて0で初期化
	q->num=q->front=q->rear=0;
	
	// 指定された最大要素数分のメモリを確保
	if((q->que=calloc(max,sizeof(int)))==NULL){
		q->max=0;　// 確保失敗時は最大容量を0にする
		return -1;
	}
	q->max=max;
	return 0;
}

// キュー内の全要素を表示する関数
void Print(const IntQueue *q){
	for(int i=0;i<q->num;i++)
		// リングバッファのため、(開始位置 + ずらす分) を最大サイズで割った余りを使う
	printf("%d",q->que[(i+q->front)%q->max]);
	putchar('\n');
}

// データをキューに入れる関数
int Enque(IntQueue *q,int x){
	if(q->num>=q->max)　// キューが満杯ならエラー
		return -1;
	q->num++;　// 現在の要素数を増やす
	q->que[q->rear++]=x;　// データの末尾に格納し、rearを一つ進める
	
	// rearが配列の末尾に達したら、先頭の0に戻す（リングバッファ）
	if(q->rear>=q->max)
	q->rear=0;
	return 0;
}

// データをキューから取り出す関数
int Deque(IntQueue *q,int *x){
	if(q->num<=0)　// キューが空ならエラー
	return -1;
	q->num--;　// 要素数を減らす
	*x=q->que[q->front];　// 先頭のデータを取り出す
	q->front++;　// frontを一つ進める
	
	// frontが末尾に達したら、先頭の0に戻す
	if(q->front==q->max)
	q->front=0;
	return 0;
}