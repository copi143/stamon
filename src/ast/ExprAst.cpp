/*
	Name: ExprAst.cpp
	Copyright: Apache 2.0
	Author: CLimber-Rong
	Date: 28/07/23 15:48
	Description: 在这里定义与表达式有关的Ast节点
*/

#ifndef EXPRAST_CPP
#define EXPRAST_CPP

#include <stamon/ast.hpp>

namespace stamon {
	namespace ast {
				AstExpression::AstExpression(AstLeftValue* LeftValue, int AssTok, AstExpression* expr) : AstNode() {
					children->add((AstNode*)LeftValue);
					children->add((AstNode*)expr);
					ass_type = AssTok;
				}
				AstExpression::AstExpression(AstBinary* value) : AstNode() {
					children->add((AstNode*)value);
					ass_type = -1;
				}
				int AstExpression::getType() {
					return AstExpressionType;
				}

				AstLeftValue::AstLeftValue(AstIdentifier* iden, ArrayList<AstNode*>* postfix) : AstNode() {
					children = postfix;
					children->insert(0,(AstNode*)iden);
				}
				int AstLeftValue::getType() {
					return AstLeftValueType;
        }

				AstLeftPostfix::AstLeftPostfix(int PostfixType, AstNode* value) : AstNode() {
					postfix_type = PostfixType;
					children->add((AstNode*)value);
				}
				int AstLeftPostfix::getType() {
					return AstLeftPostfixType;
				}

				AstBinary::AstBinary(int OperatorType, AstNode* left, AstNode* right) : AstNode() {
					operator_type = OperatorType;
					children->add((AstNode*)left);
					children->add((AstNode*)right);
				}
				AstBinary::AstBinary(AstNode* left) : AstNode() {
					operator_type = -1;
					children->add((AstNode*)left);
				}
				int AstBinary::getType() {
					return AstBinaryType;
				}

				int AstUnary::getOperatorType() {
					return operator_type;
				}
				AstUnary::AstUnary(int OperatorType, AstNode* value) : AstNode() {
					operator_type = OperatorType;
					children->add((AstNode*)value);
				}
				AstUnary::AstUnary(AstNode* value, ArrayList<AstNode*>* postfix) : AstNode() {
					operator_type = -1;
					children = postfix;
					children->insert(0, (AstNode*)value);
				}
				int AstUnary::getType() {
					return AstUnaryType;
				}

				int AstPostfix::getPostfixType() {
					return postfix_type;
				}
				AstPostfix::AstPostfix(int PostfixType, AstNode* value) : AstNode() {
					postfix_type = PostfixType;
					children->add((AstNode*)value);
				}
				int AstPostfix::getType() {
					return AstPostfixType;
				}

				AstArguments::AstArguments(ArrayList<AstNode*>* exprs) : AstNode() {
					children = exprs;
				}
				int AstArguments::getType() {
					return AstArgumentsType;
				}

				AstArrayLiteral::AstArrayLiteral(AstExpression* expr) : AstNode() {
					children->add((AstNode*)expr);
				}
				int AstArrayLiteral::getType() {
					return AstArrayLiteralType;
				}

				AstListLiteral::AstListLiteral(ArrayList<AstNode*>* exprs) : AstNode() {
					children = exprs;
				}
				int AstListLiteral::getType() {
					return AstListLiteralType;
				}
	}
}

#endif