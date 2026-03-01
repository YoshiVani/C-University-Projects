#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mydata.h"

// データを動的に生成し、初期化する関数
mydata* create_data(int no,char* name)
{
	// mydata構造体のメモリを確保し、0で初期化
	mydata* tmp=(mydata*)calloc(1,sizeof(mydata));
	tmp->no=no;　//番号をセット
	strcpy(tmp->name,name);　//名前をコピー
	return tmp;　//　生成したデータのポインタを返す
}

// 2つのデータの番号（no）を比較する関数
int mydata_no_cmp(const mydata*x,const mydata *y){
	// xが小さければ-1、大きければ1、等しければ0を返す
	return x->no < y->no ? -1: x->no > y->no ? 1 : 0;
}

// データを標準出力に表示する関数
void print_mydata(const mydata* x){
	printf("%d %s",x->no,x->name);
}

// データを表示し、最後に改行を入れる関数
void println_mydata(const mydata* x){
	printf("%d %s\n",x->no,x->name);
}