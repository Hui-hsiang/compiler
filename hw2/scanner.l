%{
#include <stdio.h>
#include "y.tab.hpp"

using namespace std;

#define LIST     strcat(buf,yytext)
#define token(t) {LIST;  }
#define tokenInteger(t,i) {LIST;  }
#define tokenString(t,s) {LIST;  }

#define MAX_LINE_LENG 256

int linenum = 1;
char buf[MAX_LINE_LENG];

struct symbol{
	char * name;
	struct symbol * next;
	int index;
};
typedef struct symbol symbol;



void insert(char* s);
void dump();

int lookup(char* s);
%}
%x COMMENT
id	[a-zA-Z]([0-9a-zA-Z]*)
integer [0-9]+
string \"[^"]*\"
plain_real [+-]?{integer}"."{integer}
exp_real [+-]?{integer}"."{integer}[Ee][+-]?{integer}
real {plain_real}|{exp_real}
%%


"(" 	{token("("); return('(');}
")" 	{token(")"); return(')');}
"\[" 	{token("\["); return('\[');}
"\]"	{token("\]"); return('\]');}
"\{" 	{token("\{"); return('\{');}
"\}"	{token("\}"); return('\}');}
","		{token(","); return(',');}
":" 	{token(":"); return(':');}
"\."	{token("\."); return('\.');}
";"		{token(";"); return(';');}
"="		{token("="); return('=');}

"+" 	{token("+"); return('+');}
"-" 	{token("-"); return('-');}
"*" 	{token("*"); return('*');}
"/"		{token("/"); return('/');}
"%" 	{token("%"); return('%');}
"<"		{token("<"); return('<');}
">"		{token(">"); return('>');}
"<="	{token("<="); return(LE);}
">="	{token(">="); return(GE);}
"=="	{token("=="); return(EQ);}
"!="	{token("!="); return(NEQ);}
"&&"	{token("&&"); return(AND);}
"||" 	{token("||"); return(OR);}
"!"		{token("!"); return('!');}
"++" 	{token("++"); return(INC);}
"--"	{token("--"); return(DEC);}
"+=" 	{token("+="); return(ADD);}
"-="	{token("-="); return(SUB);}
"*="	{token("*="); return(MUL);}
"/="	{token("!"); return(DIV);}

boolean   {
    token("BOOLEAN");
    return BOOLEAN;
}

break   {
    token("BREAK");
    return BREAK;
}
char   {
    token("CHAR");
    return CHAR;
}
case   {
	token("CASE");
    return CASE;
}
class   {
    token("CLASS");
    return CLASS;
}
continue   {
    token("CONTINUE");
    return CONTINUE;
}
def   {
    token("DEF");
    return DEF;
}
do   {
    token("DO");
    return DO;
}
else   {
    token("ELSE");
    return ELSE;
}
exit   {
    token("EXIT");
    return EXIT;
}
false   {
    token("FALSE");
    yylval.bval = false;
    return BOOL_CONST;
}
float   {
    token("FLOAT");
    return FLOAT;
}
for   {
    token("FOR");
    return FOR;
}
if   {
    token("IF");
    return IF;
}
int   {
    token("INT");
    return INT;
}
null   {
    token("NULL");
    return _NULL;
}
object   {
    token("OBJECT");
    return OBJECT;
}
print   {
    token("PRINT");
    return PRINT;
}
println   {
    token("PRINTLN");
    return PRINTLN;
}
read {
    token("READ");
    return READ;
}
repeat   {
    token("REPEAT");
    return REPEAT;
}
return   {
    token("RETURN");
    return RETURN;
}
string   {
    token("STRING");
    return STRING;
}
to   {
    token("TO");
    return TO;
}
true   {
    token("BOOLEAN");
    yylval.bval = true;
    return BOOL_CONST;
}
type   {
    token("TYPE");
    return TYPE;
}
val   {
    token("VAL");
    return VAL;
}
var   {
    token("VAR");
    return VAR;
}
while   {
    token("WHILE");
    return WHILE;
}	

{id} { 

	char str[256] = {0};
	strcat(str,yytext);
	

	tokenString("id",yytext);
	yylval.sval = new string(yytext);
	return(ID);
	
}



"//"[^\n]*	{LIST;}

"/*" 		{
			LIST;
			BEGIN COMMENT;
}
<COMMENT>.		{
			LIST;
}	
<COMMENT>\n	{
	LIST;
	printf("%d: %s", linenum++, buf);
	buf[0] = '\0';
}
<COMMENT>"*/"	{
	LIST;
	BEGIN INITIAL;
}
{integer}	{
	int tmp;
	sscanf(yytext, "%d", &tmp);
	yylval.ival = tmp;
	tokenInteger("INTEGER", tmp);
	return (INT_CONST);
}
{string} {
	char tmp[256] = {0};
	int f = 0;
	char c = getc(yyin);
	if (c == '\"'){
		ungetc(c, yyin);
		yymore();
	}
	else{
		for(int i=0,j=0;i<=yyleng;i++){
			if((i == 0 && yytext[i] == '\"') || (i == yyleng - 1 && yytext[i] == ('\"') )){
				continue;
			}
			else if(yytext[i] == '\"' && f == 0){
				f = 1;
			}
			else if (yytext[i] == '\"' && f == 1){
				f = 0;
				continue;
			}
			tmp[j] = yytext[i];
			j++;
		}
		tokenString("STRING", tmp);
		ungetc(c,yyin);
		yylval.sval = new string(tmp);
		return(STR_CONST);
	}
}
{real} {
	tokenString("REAL",yytext);
	yylval.dval = atof(yytext);
}
\n		{
		LIST;
		printf("%d: %s", linenum++, buf);
		buf[0] = '\0';
}

[ \t]*  {LIST;}

.		{ 
		LIST;
		printf("\n%d:%s\n", linenum, buf);
		printf("bad character:’%s’\n",yytext);
		exit(-1);
}
%%

