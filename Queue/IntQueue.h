#ifndef __IntQueue
#define __IntQueue

// キューを管理するための構造体定義（リングバッファ方式）
typedef struct{
	int max;　// キューの最大容量
	int num;　// 現在キューに格納されているデータの数
	int front;　// 先頭要素のインデックス（次に取り出す位置）
	int rear;　// 末尾要素のインデックス（次に挿入する位置）
	int *que;　// キューの本体となる配列へのポインタ
}IntQueue;

// キューを初期化する関数
// max: 確保するメモリのサイズ（最大容量）
int Initialize(IntQueue *q,int max);

// キューにデータxを挿入する関数
int Enque(IntQueue *q,int x);

// キューからデータを取り出し、xに格納する関数
int Deque(IntQueue *q,int *x);

// キューの全要素を先頭（front）から順番に表示する関数
void Print(const IntQueue *q);

#endif