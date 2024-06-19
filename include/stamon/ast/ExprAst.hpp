/*
	Name: ExprAst.cpp
	Copyright: Apache 2.0
	Author: CLimber-Rong
	Date: 28/07/23 15:48
	Description: 在这里定义与表达式有关的Ast节点
*/

#ifndef STAMON_EXPRAST_HPP
#define STAMON_EXPRAST_HPP

#include "ast.hpp"

namespace stamon {
	namespace ast {
		enum _PostfixType {
		    //后缀类型定义
		    PostfixMemberType = 0, //成员后缀
		    PostfixElementType,	   //下标后缀
		    PostfixCallType,	   //调用函数后缀
		    PostfixNewType,		   //新建对象后缀
		};
		enum _BinaryOperatorType {
		    //双目运算符类型定义
		    BinaryLogicORType = 0,	   //逻辑或
		    BinaryLogicANDType,		   //逻辑与
		    BinaryBitORType,		   //按位或
		    BinaryBitXORType,		   //按位异或
		    BinaryBitANDType,		   //按位与
		    BinaryEqualityType,		   //是否相等
		    BinaryInequalityType,	   //是否不相等
		    BinaryBigThanType,		   //大于
		    BinaryLessThanType,		   //小于
		    BinaryBigThanOrEqualType,  //大等于
		    BinaryLessThanOrEqualType, //小等于
		    BinaryLeftShiftType,	   //左移位
		    BinaryRightShiftType,	   //右移位
		    BinaryAddType,			   //加法
		    BinarySubType,			   //减法
		    BinaryMultType,			   //乘法
		    BinaryDiviType,			   //除法
		    BinaryModType,			   //取余
		};
		enum _UnaryOperatorType {
		    //单目运算符类型定义
		    UnaryPositiveType = 0, //正
		    UnaryNegative,		   //负
		    UnaryNotType,		   //非
		    UnaryInverseType	   //按位反
		};

		class AstExpression : public AstNode {

			public:
				int ass_type;

				AstExpression() = default;

				AstExpression(AstLeftValue* LeftValue, int AssTok, AstExpression* expr);
				AstExpression(AstBinary* value);
				int getType() override;
		};
		class AstLeftValue : public AstNode {

			public:

				AstLeftValue() = default;

				AstLeftValue(AstIdentifier* iden, ArrayList<AstNode*>* postfix);
				int getType() override;
		};
		class AstLeftPostfix : public AstNode {
			public:
				int postfix_type;
				virtual int getPostfixType() {
					return postfix_type;
				}

				AstLeftPostfix() = default;

				AstLeftPostfix(int PostfixType, AstNode* value);
				int getType() override;
		};
		class AstBinary : public AstNode {
			public:
				int operator_type;
				virtual int getOperatorType() {
					return operator_type;
				}

				AstBinary() = default;

				AstBinary(int OperatorType, AstNode* left, AstNode* right);
				AstBinary(AstNode* left);
				int getType() override;
		};
		class AstUnary : public AstNode {
			public:
				int operator_type;
				virtual int getOperatorType();
				AstUnary() = default;
				AstUnary(int OperatorType, AstNode* value);
				AstUnary(AstNode* value, ArrayList<AstNode*>* postfix);
				int getType() override;
		};
		class AstPostfix : public AstNode {

			public:
				int postfix_type;
				virtual int getPostfixType();
				AstPostfix() = default;
				AstPostfix(int PostfixType, AstNode* value);
				int getType() override;
		};
		class AstArguments : public AstNode {

			public:

				AstArguments() = default;

				AstArguments(ArrayList<AstNode*>* exprs);
				int getType() override;
		};
		class AstArrayLiteral : public AstNode {

			public:

				AstArrayLiteral() = default;

				AstArrayLiteral(AstExpression* expr);
				int getType() override;
		};
		class AstListLiteral : public AstNode {

			public:

				AstListLiteral() = default;

				AstListLiteral(ArrayList<AstNode*>* exprs);
				int getType() override;
		};

	}
}

#endif