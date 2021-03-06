%{
#include "symbolTable.hpp"
#include "lex.yy.cpp"
#define Trace(t)    if (Opt_P) cout << t << endl


symbolTableList  tables;
int Opt_P = 1;
void yyerror(string s);

%}

%union {
    int ival;
    double dval;
    bool bval;
    char cval;
    string* sval;
    valueInfo *value;
    idInfo *info;
    int type;
    vector<idInfo*>* argInfo;
    vector<valueInfo*> * expInfo;
}
/* tokens */
%token INC DEC LE GE EQ NEQ ADD OR SUB MUL DIV
%token BOOLEAN BREAK CHAR CASE CLASS CONTINUE DEF DO ELSE READ EXIT FALSE FLOAT FOR IF INT _NULL OBJECT PRINT
%token PRINTLN REPEAT RETURN STRING TO TRUE TYPE VAL VAR WHILE
%token <ival> INT_CONST
%token <dval> REAL_CONST
%token <bval> BOOL_CONST
%token <sval> STR_CONST
%token <cval> CHAR_CONST
%token <sval> ID
%token SEMICOLON

%type <value> VALUE EXP FUNCTION_INVOCATION
%type <type> DATA_TYPE FUNC_OPTIONAL
%type <argInfo> comma_seperated_ARG;
%type <info> ARG
%type <expInfo> comma_seperated_EXP
%left OR
%left AND
%left '!'
%left '<' LE EQ GE '>' NEQ
%left '+' '-'
%left '*' '/'
%nonassoc UMIUNS

%%

/*  start token 由 object ID 加上 多個 STMT 和 METHOD 開始 必須至少有一個method */
PROGRAM:    OBJECT ID {
                int result =  tables.list[tables.top].insert(*$2, objectType);
                if (result == -1){
                   yyerror("id has been uesd");
                }
            }'{'
            STMTS METHODS
            '}'{
                if (tables.lookup("main") == NULL){
                    yyerror("have no main function!!");
                }
            }


METHODS: METHOD{
            Trace("METHOD");
        } | METHOD METHODS  {
            Trace("METHOD METHODS");
        }


/*  METHOD 實作
    會判斷id 是否重複使用
    和 push pop symbol table  */

METHOD: DEF ID FUNC_OPTIONAL {
            
            Trace("NO ARG METHOD");
            int result =  tables.list[tables.top].insert(*$2, functionType, $3);
            if (result == -1){
                yyerror("id has been uesd");
            }
            tables.push();
        } FUC_BLOCK {
            tables.dump();
            tables.pop();
        }
        | DEF ID '(' ')' FUNC_OPTIONAL{
            
            Trace("NO ARG METHOD");
            int result =  tables.list[tables.top].insert(*$2, functionType,$5);
            if (result == -1){
                yyerror("id has been uesd");
            }
            tables.push();
        } FUC_BLOCK {
            tables.dump();
            tables.pop();
        }
        | DEF ID  '(' {
            tables.push(); 
        } comma_seperated_ARG ')' FUNC_OPTIONAL {
            Trace("ARG METHOD");
            int result =  tables.list[tables.top - 1].insert(*$2, functionType,$7);
            if (result == -1){
                yyerror("id has been uesd");
            }
            idInfo* tmp = tables.lookup(*$2);
            tmp->arg = *$5;
        } FUC_BLOCK {
            tables.dump();
            tables.pop();
        }

FUNC_OPTIONAL:  {$$ = unknowType; }| ':' DATA_TYPE { $$ = $2; } 



ARG:    ID ':' DATA_TYPE {
            int result =  tables.list[tables.top].insert(*$1,variableType, $3);
            if (result == -1){
                yyerror("id has been uesd");
            }
            $$ = tables.lookup(*$1);
        }
        

comma_seperated_ARG: ARG {
                        vector<idInfo*>* tmp = new vector<idInfo*>();
                        tmp->push_back($1);
                        $$ = tmp;
                    }
                    | ARG ',' comma_seperated_ARG{
                        vector<idInfo*>* tmp = $3;
                        tmp->push_back($1);
                        $$ = tmp;
                    }

STMTS:  STMT {
            Trace("STMT");
        }
        | STMT STMTS{
            Trace("STMT STMTS");
        }
        | 


/*  STMT 實作  */

STMT:   SIMPLE | V_DEC | FUNCTION_INVOCATION | CONDITIONAL | LOOP

SIMPLE: ID '=' EXP {
            Trace("ID = EXP");
            idInfo* tmp = tables.lookup(*$1);
            if ( $3->valueType != tmp->value->valueType){
                yyerror("Type error ");
            }
        }
        | ID '[' EXP ']' '=' EXP{
            if ($3->valueType != intType){
                yyerror("index must be INT");
            }
        }
        | PRINT '(' EXP ')' 
        | PRINTLN '(' EXP ')'
        | READ ID
        | RETURN {Trace("return");}
        | RETURN EXP {Trace("return EXP");}

/*  BLOCK 實作
    Block 會在一開始push symbolTable
    結束時 pop symbolTable  */
BLOCK:  '{'{
            Trace("BLOCK");
            tables.push();
        } STMTS 
        '}' { 
            tables.dump();
            tables.pop();
        }
FUC_BLOCK: '{' STMTS '}' { Trace("FUN_BLOCK");
}

CONDTIONAL_OPTIONAL: ELSE BLOCK { Trace("ELSE BLOCK");} 
                    | ELSE {tables.push();}SIMPLE { 
                        Trace("ELSE SIMPLE");tables.dump();
                        tables.pop();
                    }| ELSE CONDITIONAL { Trace("ELSE CONDITION");}
                    |

/*  CONDITIONAL 實作  */
CONDITIONAL:    IF '(' EXP ')' BLOCK {
                    Trace("IF BLOCK");
                    if ($3->valueType != boolType){
                        yyerror("CONDITION SHOULD BE BOOL TYPE");
                    }
                } CONDTIONAL_OPTIONAL
                | IF '(' EXP ')' {
                    Trace("IF SIMPLE ");
                    if ($3->valueType != boolType){
                        yyerror("CONDITION SHOULD BE BOOL TYPE");
                    }
                    tables.push();
                }
                SIMPLE{
                    tables.dump();
                    tables.pop();
                } CONDTIONAL_OPTIONAL
                
/*  LOOP 實作 */
LOOP:   WHILE '(' EXP ')' BLOCK {
            Trace("WHILE LOOP");
            if ($3->valueType != boolType ){
                yyerror("CONDITION SHOULD BE BOOL TYPE");
            }
        }
        | WHILE '(' EXP ')' {
            tables.push();
            Trace("WHILE LOOP");
            if ($3->valueType != boolType ){
                yyerror("CONDITION SHOULD BE BOOL TYPE");
            }
        } 
        SIMPLE {
            tables.dump();
            tables.pop();
        }
        | FOR '(' ID '<' '-' INT_CONST TO INT_CONST ')' BLOCK {
            Trace("FOR LOOP");
        }
        | FOR '(' ID '<' '-' INT_CONST TO INT_CONST ')' {
            tables.push();
            Trace("FOR LOOP");
        }
        SIMPLE {
            
            tables.dump();
            tables.pop();
        }
/*  變數和常數宣告 實作  */
V_DEC:    CONST_DEC | VAR_DEC

/*  變數宣告 實作  
    會判斷將變數用Class valueinfo 紀錄 並insert 到 symbolTable
*/
VAR_DEC:    VAR ID ':' DATA_TYPE '=' EXP {
                Trace("VAR ID : DATA_TYPE = EXP");
                if ($4 != $6->valueType){
                    if($4 != floatType && $6->valueType != floatType){
                        yyerror("TYPE ERROR");
                    }
                }
                int result =  tables.list[tables.top].insert(*$2, variableType, $6);
                if (result == -1){
                   yyerror("id has been uesd");
                }
            }
            | VAR ID ':' DATA_TYPE {
                Trace("VAR ID : DATA_TYPE");
                int result =  tables.list[tables.top].insert(*$2, variableType, $4);
                if (result == -1){
                   yyerror("id has been uesd");
                }
            }
            | VAR ID '=' EXP{
                Trace("VAR ID  = EXP");
                int result =  tables.list[tables.top].insert(*$2, variableType, $4);
                if (result == -1){
                   yyerror("id has been uesd");
                }
                if ($4->valueType == unknowType){
                    yyerror("valueType ERROR");
                }
            }
            | VAR ID {
                Trace("VAR ID");
                int result =  tables.list[tables.top].insert(*$2, variableType);
                if (result == -1){
                   yyerror("id has been uesd");
                }
            }
            | VAR ID ':' DATA_TYPE '[' INT_CONST ']'{
                Trace("VAR ID : DATA_TYPE [NUM]");
                int result =  tables.list[tables.top].insert(*$2, arrayType, $4, $6);
                if (result == -1){
                   yyerror("id has been uesd");
                }
            }

/*  常數宣告 實作  */
CONST_DEC:  VAL ID ':' DATA_TYPE '=' EXP {
                Trace("VAL ID : DATA_TYPE = EXP");
                if ($4 != $6->valueType){
                    if($4 != floatType && $6->valueType != floatType){
                        yyerror("TYPE ERROR");
                    }
                }
                int result =  tables.list[tables.top].insert(*$2, constType, $6);
                if (result == -1){
                   yyerror("id has been uesd");
                }
            }
            | VAL ID '=' EXP {
                Trace("VAL ID = EXP");
                int result = tables.list[tables.top].insert(*$2 ,constType, $4);
                
                if (result == -1){
                    yyerror("id has been uesd");
                }
            }
/*  FUNCTION_INVOCATION 實作
    會回傳valueinfo pointer  */
FUNCTION_INVOCATION :   ID '(' ')'{
                            Trace("ID()");
                            idInfo* tmp = tables.lookup(*$1);
                            if (tmp == NULL){
                                yyerror("CANT FIND ID");
                            }
                            if(tmp->idType != functionType){
                                yyerror("ID IS NOT A FUNCTION");
                            }
                            if(tmp->arg.size() != 0){
                                yyerror("ARG ERROR");
                            }
                            valueInfo* v = new valueInfo();
                            v->valueType = tmp->returnType;



                            $$ = v;

   

                        }
                        | ID '(' comma_seperated_EXP ')'{
                            Trace("ID COMMA SEPERATED EXP");
                            idInfo* tmp = tables.lookup(*$1);
                            vector<valueInfo*>* texp = $3;
                            if (tmp == NULL){
                                yyerror("CANT FIND ID");
                            }
                            if(tmp->idType != functionType){
                                yyerror("ID IS NOT A FUNCTION");
                            }
                            valueInfo* v = new valueInfo();
                            v->valueType = tmp->returnType;

                            for (int i=0;i<$3->size();i++){
                                if ((*texp)[i]->valueType != tmp->arg[i]->value->valueType){
                                    yyerror("arg not match");
                                }
                            }


                            $$ = v;
                        }

comma_seperated_EXP :   EXP ',' comma_seperated_EXP {
                            Trace("COMMA SEPREATED EXP");
                            vector<valueInfo*>* tmp = $3;
                            tmp->push_back($1);
                            $$ = tmp;
                        }
                        | EXP {
                            Trace("EXP");
                            vector<valueInfo*>* tmp = new vector<valueInfo*>();
                            tmp->push_back($1);
                            $$ = tmp;
                        }

/*  EXP 實作  */
EXP :   '(' EXP ')'{
            Trace("( EXP )");
            $$ = $2;
        }
        | FUNCTION_INVOCATION{Trace("FUNINVOKE");}
        | EXP '+' EXP {
            Trace("EXP '+' EXP");
            valueInfo* tmp = new valueInfo();
            if ($1->valueType == intType && $3->valueType == intType){
                tmp->valueType = intType;
                tmp->intval = ($1->intval + $3->intval);
            }
            else if ($1->valueType == floatType && $3->valueType == floatType){
                tmp->valueType = floatType;
                tmp->floatval = ($1->floatval + $3->floatval);
            }
            else{
                yyerror("EXP + EXP Type ERROR");
            }
            $$ = tmp;
        }
        | EXP '-' EXP {
            Trace("EXP '-' EXP");
            valueInfo* tmp = new valueInfo();
            if ($1->valueType == intType && $3->valueType == intType){
                tmp->valueType = intType;
                tmp->intval = ($1->intval - $3->intval);
            }
            else if ($1->valueType == floatType && $3->valueType == floatType){
                tmp->valueType = floatType;
                tmp->floatval = ($1->floatval - $3->floatval);
            }
            else{
                yyerror("EXP - EXP Type ERROR");
            }
            $$ = tmp;
        }
        | EXP '*' EXP {
            Trace("EXP '*' EXP");
            valueInfo* tmp = new valueInfo();
            if ($1->valueType == intType && $3->valueType == intType){
                tmp->valueType = intType;
                tmp->intval = ($1->intval * $3->intval);
            }
            else if ($1->valueType == floatType && $3->valueType == floatType){
                tmp->valueType = floatType;
                tmp->floatval = ($1->floatval * $3->floatval);
            }
            else{
                yyerror("EXP * EXP Type ERROR");
            }
            $$ = tmp;
        }
        | EXP '/' EXP {
            Trace("EXP '/' EXP");
            valueInfo* tmp = new valueInfo();
            if ($1->valueType == intType && $3->valueType == intType){
                tmp->valueType = floatType;
                tmp->floatval = ($1->intval / $3->intval);
            }
            else if ($1->valueType == floatType && $3->valueType == floatType){
                tmp->valueType = floatType;
                tmp->floatval = ($1->floatval * $3->floatval);
            }
            else{
                yyerror("EXP * EXP Type ERROR");
            }
            $$ = tmp;
        }
        | '-' EXP %prec UMIUNS {
            Trace("- EXP");
            valueInfo* tmp = new valueInfo();
            if ($2->valueType == intType){
                *tmp = *$2;
                tmp->intval = -1 * tmp->intval;
            }
            else if($2->valueType == floatType){
                *tmp = *$2;
                tmp->floatval = -1 * tmp->floatval;
            }
            else {
                yyerror("- EXP ERROR");
            }
            $$ = tmp;
        }
        | EXP OR EXP {
            Trace("EXP || EXP");
            valueInfo* tmp = new valueInfo();
            tmp->valueType = boolType;
            if($1->valueType != boolType || $3->valueType != boolType){
                yyerror("Type ERROR");
            }
            else{
                tmp->boolval = ($1->boolval || $3->boolval);
            }
            $$ = tmp;

        }
        | EXP AND EXP {
            Trace("EXP && EXP");
            valueInfo* tmp = new valueInfo();
            tmp->valueType = boolType;
            if($1->valueType != boolType || $3->valueType != boolType){
                yyerror("Type ERROR");
            }
            else{
                tmp->boolval = ($1->boolval && $3->boolval);
            }
            $$ = tmp;
        }
        | EXP '<' EXP {
            Trace("EXP '<' EXP");
            valueInfo* tmp = new valueInfo();
            tmp->valueType = boolType;
            if($1->valueType !=  $3->valueType){
                yyerror("Type ERROR");
            }
            else{
                tmp->boolval = ($1->boolval < $3->boolval);
            }
            $$ = tmp;
        }
        | EXP '>' EXP {
            Trace("EXP '>' EXP");
            valueInfo* tmp = new valueInfo();
            tmp->valueType = boolType;
            if($1->valueType !=  $3->valueType){
                yyerror("Type ERROR");
            }
            else{
                tmp->boolval = ($1->boolval > $3->boolval);
            }
            $$ = tmp;
        }
        | EXP EQ EXP {
            Trace("EXP '==' EXP");
            valueInfo* tmp = new valueInfo();
            tmp->valueType = boolType;
            if($1->valueType != $3->valueType){
                yyerror("Type NOT MATCH ERROR");
            }
            else if ($1->valueType == intType){
                tmp->boolval = ($1->intval == $3->intval);
            }
            else if ($1->valueType == boolType){
                tmp->boolval = ($1->boolval == $3->boolval);
            }
            else if ($1->valueType == floatType){
                tmp->boolval = ($1->floatval == $3->floatval);
            }
            else if ($1->valueType == stringType){
                tmp->boolval = ($1->stringval == $3->stringval);
            }
            else if ($1->valueType == charType){
                tmp->boolval = ($1->charval == $3->charval);
            }
            else{
                yyerror("EXP == EXP ERROR");
            }
            $$ = tmp;
        }
        | EXP GE EXP {
            Trace("EXP '>=' EXP");
            valueInfo* tmp = new valueInfo();
            tmp->valueType = boolType;
            if($1->valueType != $3->valueType){
                yyerror("Type ERROR");
            }
            else{
                tmp->boolval = $1->boolval >= $3->boolval;
            }
            $$ = tmp;
        }
        | EXP LE EXP {
            Trace("EXP '<=' EXP");
            valueInfo* tmp = new valueInfo();
            tmp->valueType = boolType;
            if($1->valueType != $3->valueType){
                yyerror("Type ERROR");
            }
            else{
                tmp->boolval = $1->boolval <= $3->boolval;
            }
            $$ = tmp;
        }
        | EXP NEQ EXP {
            Trace("EXP '!=' EXP");
            valueInfo* tmp = new valueInfo();
            tmp->valueType = boolType;
            if($1->valueType != $3->valueType){
                yyerror("Type NOT MATCH ERROR");
            }
            else if ($1->valueType == intType){
                tmp->boolval = ($1->intval != $3->intval);
            }
            else if ($1->valueType == boolType){
                tmp->boolval = ($1->boolval != $3->boolval);
            }
            else if ($1->valueType == floatType){
                tmp->boolval = ($1->floatval != $3->floatval);
            }
            else if ($1->valueType == stringType){
                tmp->boolval = ($1->stringval != $3->stringval);
            }
            else if ($1->valueType == charType){
                tmp->boolval = ($1->charval != $3->charval);
            }
            else{
                yyerror("EXP != EXP ERROR");
            }
            $$ = tmp;
        }
        | '!' EXP {
            Trace("EXP '!' EXP");
            valueInfo* tmp = new valueInfo();
            tmp->valueType = boolType;
            if($2->valueType != boolType){
                yyerror("Type ERROR");
            }
            else{
                tmp->boolval = !($2->boolval);
            }
            $$ = tmp;
        }
        | ID {
            Trace("ID");
            idInfo* tmp = tables.lookup(*$1);
            if (tmp == NULL){
                yyerror("ID DOSENT EXIST");
            }
            if (tmp->idType == arrayType){
                yyerror("ID CANT NOT BE ARRAY");
            }
            $$ = tmp->value;
        }
        | ID '[' EXP ']' {
            Trace("ID [EXP]");
            idInfo* tmp = tables.lookup(*$1);
            if (tmp == NULL){
                yyerror("ID DOSENT EXIST");
            }
            if (tmp->idType != arrayType){
                yyerror("ID IS NOT A ARRAY");
            }
            if ($3->valueType != intType){
                yyerror("index must be int");
            }
            if ($3->intval >= tmp->arraySize || $3->intval < 0){
                yyerror("access out of range");
            }
            $$ = tmp->arrayValue[$3->intval];
            
        }
        | VALUE {
            Trace("VALUE");
            $$ = $1;
        }

/*  將token轉換成valueinfo pointer 實作  */
VALUE : STR_CONST {
            Trace("string constance");
            $$ = stringValue($1);
        }
        | INT_CONST {
            Trace("integer constance");
            $$ = intValue($1);
        }
        | BOOL_CONST {
            Trace("bool constance");
            $$ = boolValue($1);
        }
        | REAL_CONST {
            Trace("real number constance");
            $$ = floatValue($1);
        }
        | CHAR_CONST {
            Trace("char constance");
            $$ = charValue($1);
        }
        
/*  將token轉換成 valueType 實作  */
DATA_TYPE : CHAR {
                $$ = charType;
            } 
            | STRING {
                $$ = stringType;
            }
            | INT {
                $$ = intType;
            }
            | BOOLEAN {
                $$ = boolType;
            }
            | FLOAT {
                $$ = floatType;
            }



%%


void yyerror(string s){
    cerr << "line " << linenum << ": " << s << endl;
    exit(1);
}



int main(int argc, char* argv[]){
    if (argc == 1){
        yyin = stdin;
    }
    else if (argc == 2){
        yyin = fopen(argv[1], "r");
    }

    yyparse();
    tables.dump();
    return 0;
}