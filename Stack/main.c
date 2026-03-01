#include <stdio.h>
#include "intstack.h"

int main(void){
	IntStack s;
	int x;
	
	// スタックの初期化：最大10個の要素を格納できるようにメモリを確保
	if(initialize(&s,10)==-1){
		puts("Building stack fails.\n");　// 初期化失敗時のエラーメッセージ
		return 1;
	}
	
	// 初期状態の表示（空の状態）
	print(&s);
	
	// データ「1」をプッシュ
	push(&s,1);
	print(&s);
		
	// データ「2」をプッシュ
	push(&s,2);
	print(&s);
	
	// データ「3」をプッシュ（この時点でスタックは 1, 2, 3 の順）
	push(&s,3);
	print(&s);
	
	// データをポップ（最後に入れた「3」が取り出される）
	pop(&s,&x);
	
	// 取り出した値を表示し、その後のスタックの状態を確認
	printf("(%d)",x);
	print(&s);
	return 0;
}