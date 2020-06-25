all: parser

parser: lex.yy.cpp y.tab.cpp symbolTable.cpp symbolTable.hpp
	g++ y.tab.cpp symbolTable.cpp -o parser -ll -ly  -std=c++11  -Wno-deprecated-register

lex.yy.cpp: scanner.l
	flex -o lex.yy.cpp scanner.l

y.tab.cpp: parser.y
	yacc -d parser.y -o y.tab.cpp