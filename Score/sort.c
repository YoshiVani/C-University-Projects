#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 科目ごとの成績を管理する構造体
struct kamoku{
char mei[20];　// 名前
char kana[10];　// カナ（ソート用）
int ei;　// 英語
int koku;　// 国語
int su;　// 数学
int sha;　// 社会
int ri;　// 理科
int goukei;　// 5教科合計
};

#define SIZE 30

int main(){
	struct kamoku seiseki[SIZE],min;
	int i,j,n,m;
	FILE*input,*output;
	char infname[16],outfname[16];
	
	// 入出力ファイル名の指定
	printf("input file name：");
	scanf("%s",infname);
	printf("output file name：");
	scanf("%s",outfname);
	
	// ファイルオープンとエラーチェック
	if((input=fopen(infname,"r"))==NULL){
		printf("flie not found\n");
		exit(1);
	}
	if((output=fopen(outfname,"w"))==NULL){
		printf("cannot found\n");
		exit(1);
	}
	n=SIZE-1;
	// データの読み込みとフィルタリング
	for(i=0;i<SIZE;i++){
		// ファイルから各項目を読み込み、EOFに達したら終了
		if(fscanf(input,"%s%s%d%d%d%d%d",
		seiseki[i].mei,seiseki[i].kana,&seiseki[i].ei,&seiseki[i].koku,
		&seiseki[i].su,&seiseki[i].sha,&seiseki[i].ri)==EOF){
			n=i-1;
			break;
		}
		
		// 合計点の計算
			seiseki[i].goukei=seiseki[i].ei+seiseki[i].koku+seiseki[i].su
			+seiseki[i].sha+seiseki[i].ri;
			
			// 合計が300点以下のデータは除外（上書きするためにインデックス i を戻す）
			if(seiseki[i].goukei<=300){
				i=i-1;
			}
	}
	
	// 選択ソートを用いてカナ順に並び替え
	for(i=0;i<=n-1;i++){
		min = seiseki[i];
		m = i;
		for(j=i+1;j<=n;j++){
			// strcmpでカナを比較（辞書順で前にあるものを探す）
			if( strcmp(min.kana,seiseki[j].kana)>0){
				min = seiseki[j];
				m=j;
			}
		}
		// 要素の入れ替え
		seiseki[m]=seiseki[i];
		seiseki[i]=min;
	}
	
	// 画面への結果出力（ヘッダーと各データ）
	printf("\tname\t\tkana\tGoukei\tEnglish\tNat.\tMath\tSociety\tScience\n");
	for(i=0;i<=n;i++){
		printf("\t%-10s\t%-10s\t%d\t%d\t%d\t%d\t%d\t%d\n",
		seiseki[i].mei,seiseki[i].kana,seiseki[i].goukei,seiseki[i].ei,seiseki[i].koku,
		seiseki[i].su,seiseki[i].sha,seiseki[i].ri);
	}
	
	// 出力ファイルへの書き込み
	for(i=0;i<=n;i++){
		fprintf(output,"\t%-10s\t%-10s\t%d\t%d\t%d\t%d\t%d\t%d\n",
		seiseki[i].mei,seiseki[i].kana,seiseki[i].goukei,seiseki[i].ei,seiseki[i].koku,
		seiseki[i].su,seiseki[i].sha,seiseki[i].ri);
	}
	
	// ファイルを閉じる
	fclose(input);
	fclose(output);
	return 0;
}

/*
追記：
テスト用のファイルとして、以下の情報をテキストファイルに保存し、このファイルをプログラムに入力すると正しい結果が得られます。

赤井    アカイ    78 65 87 92 70
伊藤    イトウ    56 57 63 87 45
鈴木    スズキ    93 92 89 67 75
藤原    フジハラ  72 82 71 63 82
田中    タナカ    88 66 91 74 79
山田    ヤマダ    45 54 62 86 90
奥村    オクムラ  32 78 63 82 46
高野    タカノ    93 78 65 88 96
松本    マツモト  85 67 79 57 87
相田    アイダ    69 42 52 63 56

*/