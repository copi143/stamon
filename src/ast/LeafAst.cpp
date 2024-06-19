/*
	Name: LeafAst.cpp
	Copyright: Apache 2.0
	Author: CLimber-Rong
	Date: 29/07/23 20:14
	Description: 语法树叶子节点的定义
*/

#ifndef LEAFAST_CPP
#define LEAFAST_CPP

#include <stamon/ast.hpp>
#include"String.hpp"

namespace stamon {
	namespace ast {
				AstIdentifier::AstIdentifier(unsigned long long iden_id) : AstNode() {
					id = iden_id;
				}
				int AstIdentifier::getType() {
					return AstIdentifierType;
				}
				unsigned long long AstIdentifier::getID() {
					return id;
				}

				AstIdentifierName::AstIdentifierName(const String& id) : AstIdentifier(-1) {
					name = id;
				}
				int AstIdentifierName::getType() {
					return AstIdentifierType;
				}
				String AstIdentifierName::getName() {
					return name.getstr();
				}

				int AstNumber::getType() {
					return AstNumberType;
				}
				int AstNumber::getNumberType() {
					return number_type;
				}

				AstIntNumber::AstIntNumber(int val) : AstNumber() {
					number_type = IntNumberType;
					value = val;
				}
				int AstIntNumber::getVal() {
					return value;
				}

				AstFloatNumber::AstFloatNumber(float val) : AstNumber() {
					number_type = FloatNumberType;
					value = val;
				}
				float AstFloatNumber::getVal() {
					return value;
				}

				AstDoubleNumber::AstDoubleNumber(double val) : AstNumber() {
					number_type = DoubleNumberType;
					value = val;
				}
				double AstDoubleNumber::getVal() {
					return value;
				}

				AstString::AstString(const String& str) : AstNode() {
					val = str;
				}
				int AstString::getType() {
					return AstStringType;
				}
				String AstString::getVal() {
					return val;
				}

				int AstNull::getType() {
					return AstNullType;
        }

				int AstBreak::getType() {
					return AstBreakType;
				}

				int AstContinue::getType() {
					return AstContinueType;
				}
	}
}

#endif
