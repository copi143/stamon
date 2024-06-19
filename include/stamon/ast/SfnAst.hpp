/*
	Name: SfnAst.cpp
	Copyright: Apache 2.0
	Author: CLimber-Rong
	Date: 01/08/23 19:55
	Description: SFN节点的基本定义
*/

#ifndef STAMON_SFNAST_HPP
#define STAMON_SFNAST_HPP

#include <stamon/ast.hpp>
#include"String.hpp"

namespace stamon {
	namespace ast {
		class AstSFN : public AstNode {
			public:
				AstSFN() = default;
				AstSFN(AstIdentifier* port, AstIdentifier* result);
				int getType() override;
		};
	}
}

#endif
