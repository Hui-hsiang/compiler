%{
#include <stdio.h>

#define LIST     strcat(buf,yytext)
#define token(t) {LIST; printf("<%s>\n",t);}
#define tokenInteger(t,i) {LIST; printf("<%s:%d>\n",t,i);}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",t,s);}

#define MAX_LINE_LENG 256

int linenum = 1;
char buf[MAX_LINE_LENG];
char* keyword[28] = {
"BOOLEAN", "BREAK",	"CHAR", "CASE", "CLASS", "CONTINUE",
"DEF", "DO", "ELSE", "EXIT", "FALSE", "FLOAT", "FOR",
"IF", "INT", "NULL", "OBJECT", "PRINT", "PRINTLN",
"REPEAT", "RETURN", "STRING", "TO", "TRUE", "TYPE",
"VAL", "VAR", "WHILE" };

struct symbol{
	char * name;
	struct symbol * next;
	int index;
};
typedef struct symbol symbol;

symbol * head = NULL;
symbol * current = NULL;

void insert(char* s);
void dump();
symbol* creat(char * s);
int lookup(char* s);
%}
%x COMMENT
id	[a-zA-Z]([0-9a-zA-Z]*)
integer [0-9]+
string \"[^"]*\"
boolean  true|false 
plain_real [+-]?{integer}"."{integer}
exp_real [+-]?{integer}"."{integer}[Ee][+-]?{integer}
real {plain_real}|{exp_real}
%%


"(" 	{token("(");}
")" 	{token(")");}
"\[" 	{token("\[");}
"\]"	{token("\]");}
"\{" 	{token("\{");}
"\}"	{token("\}");}
","		{token(",");}
":" 	{token(":");}
"\."	{token("\.");}
";"		{token(";");}
"="		{token("=");}

"+" 	{token("+");}
"-" 	{token("-");}
"*" 	{token("*");}
"/"		{token("/");}
"%" 	{token("%");}
"<"		{token("<");}
"<="	{token("<=");}
">" 	{token(">");}
">="	{token(">=");}
"=="	{token("==");}
"!="	{token("!=");}
"&&"	{token("&&");}
"||" 	{token("||");}
"!"		{token("!");}


{boolean} {
	tokenString("BOOLEAN",yytext);
}
{id} { 
	int GetKeyword = 0;
	char tmp[256]  = {'\0'};
	strcat(tmp,yytext);
	for (int i=0;i<yyleng;i++){
		if (tmp[i] >= 'a' && tmp[i] <= 'z'){
			tmp[i] = tmp[i] - 'a' + 'A';
		}
	}
	for(int i=0;i<28;i++){
		if (strcmp(tmp,keyword[i]) == 0){
			token(tmp);
			GetKeyword =1;
		}
	}
	if (GetKeyword == 0){
		char str[256] = {0};
		strcat(str,yytext);
		if (head  == NULL){
			head = creat(str);
		}
		else{
			if (lookup(str) == -1){
				insert(str);
			}
		}
		tokenString("id",yytext);
	}
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
	tokenInteger("INTEGER", tmp)
}
{string} {
	char tmp[256] = {0};
	int f = 0;
	char c = input();
	if (c == '\"'){
		unput(c);
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
		unput(c);
	}
}
{real} {
	tokenString("REAL",yytext);
}
\n		{
		LIST;
		printf("%d: %s", linenum++, buf);
		buf[0] = '\0';
}

[ \t]*  {LIST;}

.		{ 
		LIST;
		printf("%d:%s\n", linenum, buf);
		printf("bad character:’%s’\n",yytext);
		exit(-1);
}
%%

int main(int argc,char ** argv )
{
	if ( argc > 1 )
		yyin = fopen( argv[1], "r" );
	else
		yyin = stdin;
	if(!yyin){
		printf("file not found.\n");
        return -1;
	}
	yylex();
	printf("\nSymbol Table:\n");
	dump();
}
int yywrap(){
	LIST;
	printf("%d: %s", linenum++, buf);
	buf[0] = '\0';
	return 1;
}
symbol* creat(char *s){
	char * str = (char *)malloc(255);
	strcat(str,s);
	head = (symbol *)malloc(sizeof(symbol));
	head -> name = str;
	head -> index = 1;
	current = head;

}
void insert(char* s){
	char * str = (char *)malloc(255);
	strcat(str,s);
	symbol * tmp = (symbol *)malloc(sizeof(symbol));
	tmp -> name = str;
	tmp -> index = current->index +1;
	current -> next = tmp;
	current = tmp;
}
int lookup(char* s){
	symbol* tmp = head;
	while(tmp != NULL){
		
		if(strcmp(tmp->name, s) == 0){
			return tmp -> index;
		}
		tmp = tmp -> next;
	}

	return -1;
}
void dump(){
	symbol* tmp = head;
	while(tmp != NULL){
		printf ("%d: %s\n",tmp->index ,tmp -> name);
		tmp = tmp -> next;
	}
}