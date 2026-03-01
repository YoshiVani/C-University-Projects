#include <stdio.h>
#include "mydata.h"
#include "bintree.h"

int main(void){
	binnode* root=NULL;　// 二分探索木の根（ルート）を指すポインタを初期化
	mydata *temp;
	
	//　１番：山田さんのデータを生成し、木に追加
	temp=create_data(1,"Yamada");
	root=add(root,temp);
	
	//　５番：鈴木さんのデータを生成し、木に追加
	temp=create_data(5,"Suzuki");
	root=add(root,temp);
	
	//　２番：田中さんのデータを生成し、木に追加
	temp=create_data(2,"Tanaka");
	root=add(root,temp);
	
	//　４番：佐藤さんのデータを生成し、木に追加
	temp=create_data(4,"Sato");
	root=add(root,temp);
	
	//　８番：田中さんのデータを生成し、木に追加
	temp=create_data(8,"Yamamoto");
	root=add(root,temp);
	
	// 完成した木の内容を、再帰的に表示
	printtree(root);
}