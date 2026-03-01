#include <stdio.h>
#include "IntQueue.h"

int main(void){
	IntQueue que;　// キュー構造体のインスタンス
	int x;
	
	// キューの初期化：最大6個の要素を格納できるメモリを確保
	if(Initialize(&que,6)==-1){
		puts("Bouilding queue failes.\n");　// 初期化失敗時のエラーメッセージ
		return 1;
	}
	
	// 初期状態を表示（空の状態）
	Print(&que);
	
	// データ「1」をエンキュー
	Enque(&que,1);
		Print(&que);
		
	// データ「2」をエンキュー
	Enque(&que,2);
		Print(&que);
		
	// データ「3」をエンキュー（現在のキューの状態：1 2 3）
	Enque(&que,3);
	Print(&que);
		
	// データをデキュー（最初に入れた「1」が取り出される）
	Deque(&que,&x);
	printf("%d:",x);　// 取り出した値を表示
	Print(&que);　// 残りのキューを表示
	
	// データをデキュー（次に入れた「2」が取り出される）
	Deque(&que,&x);
	printf("%d:",x);
	Print(&que);
	
	// データをデキュー（最後に入れた「3」が取り出される）
	Deque(&que,&x);
	printf("%d:",x);
	Print(&que);
	
	return 0;
}