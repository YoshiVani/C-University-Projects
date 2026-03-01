#include <stdio.h>
#include <stdlib.h>
#include "mydata.h"
#include "bintree.h"

// --- 内部補助関数 ---

// 新しいノードのメモリを確保する関数
static binnode* alloc_bin_node(void)
{
	return calloc(1,sizeof(binnode)); // callocにより全メンバを0で初期化
}

// ノードにデータと左右の子へのポインタをセットする関数
static void set_bin_node(binnode *n, const mydata *x,const binnode *left,const binnode* right)
{
	n->data = *x; //データをコピー
	n->left = left;　//左の子へのポインタを設定
	n->right = right;　//右の子へのポインタを設定
}

// --- 公開関数（木の操作） ---

// 木にデータを追加する関数（再帰的に適切な位置を探索）
binnode* add(binnode* p,const mydata* x)
{
	int cond;
	
	if(p==NULL){
		// 空の場所に到達したら、新しいノードを作成
		p=alloc_bin_node();
		set_bin_node(p,x,NULL,NULL);
	}else if((cond=mydata_no_cmp(x,&p->data))==0)
		// 既に同じ番号のデータが存在する場合はエラーを表示
		printf("Error %d is already registerd.\n",x->no);
	else if (cond <0)
		//小さければ左の枝へ
		p->left=add(p->left,x);
	else
		//大きければ右の枝へ
		p->right=add(p->right,x);
	return p;
}

// 木の構造を再帰的に表示する関数
void printtree(const binnode* p)
{
	if(p!=NULL){
		println_mydata(&p->data);　// 現在のノードのデータを表示
		printf("left node of %d:\n",(&p->data)->no);
		printtree(p->left);　// 左の子を再帰的に探索
		printf("right node of %d:\n", (&p->data)->no);
		printtree(p->right);　// 右の子を再帰的に探索
		printf("right node of %d end:\n", (&p->data)->no);
}
}

// 指定されたノードを削除する関数
int remove_node(binnode **root, const mydata *x) {
	binnode **p = root;
	binnode *temp, *next;
	binnode **min, **left;　//　元のコードにある変数宣言

	// 削除対象のノードを探索
	while (1) {
		int cond;
		if (*p == NULL) {
			printf("Error: %d is not registered\n", x->no);
			return -1;
		}else if((cond = mydata_no_cmp(x, &(*p)->data))==0){
			break;　// 対象のノードを発見
		}else if (cond < 0){
			p = &((*p)->left);	// 対象が現在のノードより小さければ左へ
		}else{
			p = &((*p)->right);　// 対象が現在のノードより大きければ右へ
		}
	}

	// ノードの削除処理
	if ((*p)->left == NULL && (*p)->right == NULL) {
		//　子がない場合
		temp = *p;
		*p = NULL;
		free(temp);
	}else if ((*p)->left == NULL){
		// 右の子だけがいる場合
		next = (*p)->right;
		temp = *p;
		*p = next;
		free(temp);
	}else if ((*p)->right == NULL){
		//　左の子だけがいる場合
		next = (*p)->left;
		temp = *p;
		*p = next;
		free(temp);
	}else{
		//　左右両方に子がいる場合
		if ((*p)->left == NULL) {
			next = (*p)->right;
		}else{
			// 左の子から右端（最大値）を探すロジック
			binnode **leftPtr = &((*p)->left);
			while ((*leftPtr)->right != NULL) {
				leftPtr = &((*leftPtr)->right);
			}ぐ
			next = *leftPtr;
			*leftPtr = (*leftPtr)->left;
		}
		//　メモリの入れ替えと解放
		temp = *p;
		*p = next;
		free(temp);
	}

	return 0;
}

