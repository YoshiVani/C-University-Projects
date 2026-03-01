#ifndef ___bintree
#define ___bintree

#include "mydata.h"

// 二分探索木のノードを定義する構造体
typedef struct __bnode {
mydata data;　// 格納するデータ（mydata型）
struct __bnode* left;　// 左の子ノードへのポインタ
struct __bnode* right;　// 右の子ノードへのポインタ
} binnode;

// 指定したデータを木に追加し、その結果の根（ルート）を返す関数
binnode* add(binnode* p, const mydata* x);

// 木の構造を再帰的に巡回し、内容を表示する関数
void printtree(const binnode* p);

#endif
