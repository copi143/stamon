/*
    Name: CodeLogicAst.cpp
    Copyright: Apache 2.0
    Author: CLimber-Rong
    Date: 28/07/23 15:45
    Description: 在这里写代码逻辑（如函数、流程控制等）节点的定义
*/

#ifndef STAMON_CODELOGICAST_HPP
#define STAMON_CODELOGICAST_HPP

#include "ast.hpp"

namespace stamon {
	namespace ast {
  class AstProgram : public AstNode {

			public:

        AstProgram() = default;

				explicit AstProgram(ArrayList<AstNode*>* statements);
        int getType() override;
		};
		class AstDefClass : public AstNode {
			public:
				AstDefClass() = default;

				AstDefClass(AstIdentifier* iden, AstAnonClass* object_class);
				int getType() override;
		};
		class AstDefFunc : public AstNode {

			public:

				AstDefFunc() = default;

				AstDefFunc(AstIdentifier* iden, AstAnonFunc* func);
				int getType() override;
		};
		class AstDefVar : public AstNode {

			public:

				AstDefVar() = default;

				AstDefVar(AstIdentifier* iden, AstExpression* expr);

				int getType() override; 
		};
		class AstAnonClass : public AstNode {

			public:
				bool isHaveFather = false;

				AstAnonClass() = default;

				AstAnonClass(AstIdentifier* father, ArrayList<AstNode*>* expr);
				int getType() override;
		};
		class AstAnonFunc : public AstNode {

			public:

				AstAnonFunc() = default;

				AstAnonFunc(ArrayList<AstNode*>* args, AstBlock* block);
				int getType() override; 
		};
		class AstBlock : public AstNode {

			public:

				AstBlock() = default;

				AstBlock(ArrayList<AstNode*>* statements);
				int getType() override; 
		};
		class AstIfStatement : public AstNode {

			public:

				AstIfStatement() = default;

				AstIfStatement(AstExpression* expr, AstBlock* block_if);
				AstIfStatement(AstExpression* expr, AstBlock* block_if, AstBlock* block_else);
				int getType() override;
		};
		class AstWhileStatement : public AstNode {

			public:

				AstWhileStatement() = default;

				AstWhileStatement(AstExpression* expr, AstBlock* block_while);
				int getType() override;
		};
		class AstForStatement : public AstNode {

			public:

				AstForStatement() = default;

				AstForStatement(AstIdentifier* iden, AstExpression* expr, AstBlock* block_for);
				int getType() override; 
		};
		class AstReturnStatement : public AstNode {

			public:

				AstReturnStatement() = default;

				AstReturnStatement(AstExpression* expr);
				int getType() override; 
		};
	}
}

#endif