/*
    Name: CodeLogicAst.cpp
    Copyright: Apache 2.0
    Author: CLimber-Rong
    Date: 28/07/23 15:45
    Description: 在这里写代码逻辑（如函数、流程控制等）节点的定义
*/

#ifndef CODELOGICAST_CPP
#define CODELOGICAST_CPP

#include <stamon/ast.hpp>

namespace stamon {
	namespace ast {
				AstProgram::AstProgram(ArrayList<AstNode*>* statements) {
					children = statements;
				}
				int AstProgram::getType() {
					return AstProgramType;
        }

				AstDefClass::AstDefClass(AstIdentifier* iden, AstAnonClass* object_class) {
					children->add((AstNode*)iden);
					children->add((AstNode*)object_class);
				}
				int AstDefClass::getType() {
					return AstDefClassType;
				}

				AstDefFunc::AstDefFunc(AstIdentifier* iden, AstAnonFunc* func) : AstNode() {
					children->add((AstNode*)iden);
					children->add((AstNode*)func);
				}
				int AstDefFunc::getType() {
					return AstDefFuncType;
				}

				AstDefVar::AstDefVar(AstIdentifier* iden, AstExpression* expr) : AstNode() {
					children->add((AstNode*)iden);
					children->add((AstNode*)expr);
				}

				int AstDefVar::getType() {
					return AstDefVarType;
				}

				AstAnonClass::AstAnonClass(AstIdentifier* father, ArrayList<AstNode*>* expr) : AstNode() {
					children = expr;
					if(father!=NULL) {
						isHaveFather = true;
						children->insert(0, (AstNode*)father);
					}
				}
				int AstAnonClass::getType() {
					return AstAnonClassType;
				}

				AstAnonFunc::AstAnonFunc(ArrayList<AstNode*>* args, AstBlock* block) : AstNode() {
					children = args;
					children->add((AstNode*)block);
				}
				int AstAnonFunc::getType() {
					return AstAnonFuncType;
				}

				AstBlock::AstBlock(ArrayList<AstNode*>* statements) : AstNode() {
					children = statements;
				}
				int AstBlock::getType() {
					return AstBlockType;
				}

				AstIfStatement::AstIfStatement(AstExpression* expr, AstBlock* block_if) : AstNode() {
					children->add((AstNode*)expr);
					children->add((AstNode*)block_if);
				}
				AstIfStatement::AstIfStatement(AstExpression* expr, AstBlock* block_if, AstBlock* block_else) : AstNode() {
					children->add((AstNode*)expr);
					children->add((AstNode*)block_if);
					children->add((AstNode*)block_else);
				}
				int AstIfStatement::getType() {
					return AstIfStatementType;
				}

				AstWhileStatement::AstWhileStatement(AstExpression* expr, AstBlock* block_while) : AstNode() {
					children->add((AstNode*)expr);
					children->add((AstNode*)block_while);
				}
				int AstWhileStatement::getType() {
					return AstWhileStatementType;
        }

				AstForStatement::AstForStatement(AstIdentifier* iden, AstExpression* expr, AstBlock* block_for) : AstNode() {
					children->add((AstNode*)iden);
					children->add((AstNode*)expr);
					children->add((AstNode*)block_for);
				}
				int AstForStatement::getType() {
					return AstForStatementType;
				}

				AstReturnStatement::AstReturnStatement(AstExpression* expr) {
					children->add((AstNode*)expr);
				}
				int AstReturnStatement::getType() {
					return AstReturnStatementType;
				}
	}
}

#endif