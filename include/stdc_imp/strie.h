/*
	Name: strie.h
	Copyright: Apache 2.0 License
	Author: 瞿相荣
	Date: 25/10/22 08:22
	Description: C语言字典树库（仅支持普通ASCII码存储），版本1.0.0.0
*/

/*
 * 这个库并不是在编写STVM时诞生的
 * 而是我之前编写过的
 * 这个库的开源地址：github.com/CLimber-Rong/ctrie
 * 注意：这个库经过修改，和原版的并不一样
 */

/*
 * 我改装了strie.h，让它的键不是字符串，而是字节数组
 */


#ifndef STRIE_H
#define STRIE_H

#include"stdlib.h"
#include"string.h"
#include"stack.h"

typedef int (*TRIE_VISIT)(void*);							//遍历的函数指针接口

typedef struct _STRIE_NODE_TYPE {
	void* data;				//数据域
	int isexist;			//是否存在，存在为1，不存在为0
	struct _STRIE_NODE_TYPE* child[256];
} STRIE;

STRIE* InitTrie();											//初始化树，成功返回地址，失败返回NULL
int SetTrieKeyVal(STRIE* trie, unsigned char* key, int key_size, void* val);		//设置键-值，成功返回1，失败返回0，可以用此接口创建键-值和更改已有键-值
int DelTrieKeyVal(STRIE* trie, unsigned char* key, int key_size);		//删除键-值，成功返回1，失败返回0
void* GetTrieKeyVal(STRIE* trie, unsigned char* key, int key_size);	//根据键获得获得值，成功返回值，失败返回NULL，
//返回NULL时不排除数据域的指针本来就等于NULL，
//需配合TrieExistKeyVal()接口判断
int TrieExistKeyVal(STRIE* trie, unsigned char* key, int key_size);	//键-值是否存在，存在则返回1，不存在则返回0
int ClearTrie(STRIE* trie);									//清空所有键-值，成功返回1，失败返回0
int DestroyTrie(STRIE* trie);								//销毁树，成功返回1，失败返回0
int TrieEmpty(STRIE* trie);									//树是否为空，是则返回1，否则返回0，错误返回-1
int TrieTraverse(STRIE* trie, TRIE_VISIT visit);				//对树中所有元素依次调用visit函数
//要求visit函数参数为数据，visit返回1代表处理成功，并开始处理下一个元素
//返回0代表处理失败，StackTraverse则终止处理并退出
//返回成功处理的元素个数

#endif
