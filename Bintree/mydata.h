#ifndef __mydata
#define __mydata

// データを保持するための構造体定義
typedef struct{
	int no;　// IDや出席番号などの識別番号
	char name[20];　// 名前を格納する文字列
}mydata;

// 新しくデータを作成（メモリ確保と初期化）し、そのポインタを返す関数
mydata* create_data(int no,char* name);

// 2つのデータの番号を比較し、順序関係を返す関数
int mydata_no_cmp(const mydata*x,const mydata*y);

// データを改行なしで表示する関数
void print_mydata(const mydata* x);

// データを表示した後、改行を加える関数
void println_mydata(const mydata* x);

#endif