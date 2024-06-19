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

#ifndef STAMON_AST_HPP
#define STAMON_AST_HPP

#include "ArrayList.hpp"
#include "String.hpp"

namespace stamon {
	namespace ast {
		// Ast类型定义，详细作用见doc/虚拟机AST设计.md
		enum _AstType {
		    AstNodeType = 0,
		    AstProgramType,
		    AstDefClassType,
			AstDefFuncType,
			AstDefVarType,
		    AstAnonClassType,
		    AstAnonFuncType,
		    AstBlockType,
		    AstBreakType,
			AstContinueType,
		    AstIfStatementType,
		    AstWhileStatementType,
		    AstForStatementType,
		    AstReturnStatementType,
		    AstSFNType,
		    AstExpressionType,
		    AstLeftValueType,
		    AstLeftPostfixType,
		    AstBinaryType,
		    AstUnaryType,
		    AstPostfixType,
			AstArgumentsType,
		    AstIdentifierType,
		    AstNumberType,
		    AstStringType,
		    AstNullType,
		    AstArrayLiteralType,
		    AstListLiteralType,
			AstLeafType,	//见AstIR.cpp
		    AstTypeNum // Ast总数
		};

		// Ast类定义，详细实现见同目录的其他源码
		class AstNode;
		class AstProgram;
		class AstDefClass;
		class AstDefFunc;
		class AstAnonClass;
		class AstAnonFunc;
		class AstBlock;
		class AstBreak;
		class AstContinue;
		class AstIfStatement;
		class AstWhileStatement;
		class AstForStatement;
		class AstReturnStatement;
		class AstSFN;
		class AstExpression;
		class AstLeftValue;
		class AstLeftPostfix;
		class AstBinary;
		class AstUnary;
		class AstPostfix;
		class AstArguments;
		class AstIdentifier;
		class AstNumber;
		class AstString;
		class AstNull;
		class AstArrayLiteral;
		class AstListLiteral;

		class AstNode {
			protected:
				ArrayList<AstNode*>* children;

			public:
				int lineNo;			//语法分析时用于显示行号
				String filename;	//语义分析时用于显示文件名

				AstNode();

				explicit AstNode(int line);

				virtual int ChildrenNum();

				virtual ArrayList<AstNode*> *Children();

				virtual int getType();
		};
	}
}

#endif
