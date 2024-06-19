/*
	Name: SfnAst.cpp
	Copyright: Apache 2.0
	Author: CLimber-Rong
	Date: 01/08/23 19:55
	Description: SFN节点的基本定义
*/

#ifndef SFNAST_CPP
#define SFNAST_CPP

#include <stamon/ast.hpp>
#include"String.hpp"

namespace stamon {
	namespace ast {
				AstSFN::AstSFN(AstIdentifier* port, AstIdentifier* result) : AstNode() {
					children->add(port);
					children->add(result);
				}
				int AstSFN::getType() {
					return AstSFNType;
				}
	}
}

#endif
