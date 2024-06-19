/*
        Name: Ast
        Copyright: Apache 2.0
        Author: CLimber-Rong
        Date: 28/07/23 16:44
        Description:
        * 这里对Ast进行了基本的定义
        * 如果你想要引用所有的Ast源码，只要写入以下代码即可：
        #include"ast.hpp"
        using namespace stamon::ast;
*/

#ifndef AST_CPP
#define AST_CPP

#include <stamon/ast.hpp>

namespace stamon {
	namespace ast {
				AstNode::AstNode() {
					//构造函数
					children = new ArrayList<AstNode*>();
				}

				AstNode::AstNode(int line) {
					//构造函数
					children = new ArrayList<AstNode*>();
					lineNo = line;
				}

				int AstNode::ChildrenNum() {
					//子节点数量
					return children->size();
				}

				ArrayList<AstNode*> *AstNode::Children() {
					//获得子节点列表
					return children;
				}

				int AstNode::getType() {
					//获得节点类型
					return AstNodeType;
				}
	}
}

#include "ast/ast.hpp" // TODO 删除头文件对源文件的引用

#endif
