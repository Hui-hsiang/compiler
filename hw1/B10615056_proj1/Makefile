all: scanner.l
	flex scanner.l
	cc -o scanner -O lex.yy.c -ll

test: scanner
	./scanner