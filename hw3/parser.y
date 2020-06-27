%{

#include "Assembler.hpp"
#include "lex.yy.cpp"
#define Trace(t)    if (Opt_P) cout << t << endl


symbolTableList  tables;
Assembler assember;
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
                assember.objinitial(*$2);
            }'{'
            STMTS METHODS
            '}'{
                assember.objFinish();
                if (tables.lookup("main") == NULL){
                    yyerror("have no main function!!");
                }else{
                    if(tables.lookup("main")->idType != functionType){
                        yyerror("have no main function!!");
                    }
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
            if(*$2 == "main"){
                assember.mainDEC();
            }else{
                assember.funDEC(*$2, $3);
            }
            tables.push();
        } FUC_BLOCK {
            if(*$2 == "main"){
                assember.mainFinish();
            }
            else{
                assember.funFinish();
            }
            assember.leaveBlock(*$2);
            tables.dump();
            tables.pop();
        }
        | DEF ID '(' ')' FUNC_OPTIONAL{
            
            Trace("NO ARG METHOD");
            int result =  tables.list[tables.top].insert(*$2, functionType,$5);
            if (result == -1){
                yyerror("id has been uesd");
            }
            if(*$2 == "main"){
                assember.mainDEC();
            }
            else{
                assember.funDEC(*$2, $5);
            }
            tables.push();
        } FUC_BLOCK {
            if(*$2 == "main"){
                assember.mainFinish();
            }
            else{
                assember.funFinish();
            }
            assember.leaveBlock(*$2);
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
            if(*$2 == "main"){
                assember.mainDEC();
            }
            else{
                assember.funDEC(*$2, $5, $7);
            }
        } FUC_BLOCK {
            if(*$2 == "main"){
                assember.mainFinish();
            }
            else{
                assember.funFinish();
            }
            assember.leaveBlock(*$2);
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
                if (($3->valueType == floatType && tmp->value->valueType == intType) || ($3->valueType == intType && tmp->value->valueType == floatType) ){break;}
                cout << $3->valueType<<tmp->value->valueType;
                yyerror("Type error ");
            }
            idInfo* checkGlobal = tables.list[0].lookup(*$1);
            if (checkGlobal == NULL){
                assember.putLocal(tmp);
            }else{
                assember.putGlobal(tmp);
            }
        }
        | ID '[' EXP ']' '=' EXP{
            if ($3->valueType != intType){
                yyerror("index must be INT");
            }
        }
        | PRINT {

            assember.output << "getstatic java.io.PrintStream java.lang.System.out\n";

        }'(' EXP ')'{
            switch ($4->valueType){
                case intType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                case floatType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(float)\n";
                    break;
                case boolType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                case charType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(char)\n";
                    break;
                case stringType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(java.lang.String)\n";
                    break;
                case unknowType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                case valueTypeError:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                default:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
            }
        } 
        | PRINTLN {

            assember.output << "getstatic java.io.PrintStream java.lang.System.out\n";

        }'(' EXP ')'{

            switch ($4->valueType){
                case intType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                case floatType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(float)\n";
                    break;
                case boolType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                case charType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(char)\n";
                    break;
                case stringType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(java.lang.String)\n";
                    break;
                case unknowType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                case valueTypeError:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                default:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
            }

        }
        | PRINT{

            assember.output << "getstatic java.io.PrintStream java.lang.System.out\n";

        }  EXP {

            switch ($3->valueType){
                case intType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                case floatType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(float)\n";
                    break;
                case boolType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                case charType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(char)\n";
                    break;
                case stringType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(java.lang.String)\n";
                    break;
                case unknowType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                case valueTypeError:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                default:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
            }

        } 
        | PRINTLN{

            assember.output << "getstatic java.io.PrintStream java.lang.System.out\n";

        }  EXP {

            switch ($3->valueType){
                case intType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                case floatType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(float)\n";
                    break;
                case boolType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                case charType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(char)\n";
                    break;
                case stringType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(java.lang.String)\n";
                    break;
                case unknowType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                case valueTypeError:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                default:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
            }

        }
        | READ ID
        | RETURN {Trace("return");}
        | RETURN EXP {Trace("return EXP");}

/*  BLOCK 實作
    Block 會在一開始push symbolTable
    結束時 pop symbolTable  */
BLOCK:  '{' {
            Trace("BLOCK");
            assember.enterBlock();
            tables.push();
        } STMTS 
        '}' { 

            tables.dump();
            tables.pop();
        }
FUC_BLOCK: '{' {
                assember.enterBlock();
            } STMTS '}' { 
                Trace("FUN_BLOCK");
            }

CONDTIONAL_OPTIONAL: ELSE BLOCK { 
                        Trace("ELSE BLOCK");
                        assember.elseFinish();
                    } 
                    | ELSE {Trace("ESLE");tables.push();} SIMPLE { 
                        Trace("ELSE SIMPLE");tables.dump();
                        assember.elseFinish();
                        tables.pop();
                    }| ELSE CONDITIONAL { Trace("ELSE CONDITION");}
                    |{ assember.elseFinish(); }

/*  CONDITIONAL 實作  */
CONDITIONAL:    IF '(' EXP ')' { assember.ifCondition();} BLOCK {
                    Trace("IF BLOCK");
                    if ($3->valueType != boolType){
                        yyerror("CONDITION SHOULD BE BOOL TYPE");
                        assember.ifFinish();
                    }
                } CONDTIONAL_OPTIONAL
                | IF '(' EXP ')' {
                    Trace("IF SIMPLE ");
                    if ($3->valueType != boolType){
                        yyerror("CONDITION SHOULD BE BOOL TYPE");
                    }
                    tables.push();
                    assember.ifCondition();
                }
                SIMPLE{
                    tables.dump();
                    tables.pop();
                    assember.ifFinish();
                } CONDTIONAL_OPTIONAL
                
/*  LOOP 實作 */

LOOP_CONDTIONAL: SIMPLE|FUC_BLOCK

LOOP:   WHILE {assember.whileLoopBegin();} '(' EXP ')' {
            tables.push();
            Trace("WHILE LOOP");
            if ($4->valueType != boolType ){
                yyerror("CONDITION SHOULD BE BOOL TYPE");
            }
            assember.whileLoopIn();
        } 
        LOOP_CONDTIONAL {
            tables.dump();
            tables.pop();
            assember.whileLoopexit();
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
                if (tables.top == 0){
                    assember.globalVar($4, *$2);
                }
                else{
                    assember.localVar(*$2, $6);
                }
            }
            | VAR ID ':' DATA_TYPE {
                Trace("VAR ID : DATA_TYPE");
                int result =  tables.list[tables.top].insert(*$2, variableType, $4);
                if (result == -1){
                   yyerror("id has been uesd");
                }
                if (tables.top == 0){
                    assember.globalVar($4, *$2);
                }
                else{
                    assember.localVar(*$2);
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
                if (tables.top == 0){
                    assember.globalVar($4->valueType, *$2);
                }
                else{
                    assember.localVar(*$2, $4);
                }
            }
            | VAR ID {
                Trace("VAR ID");
                int result =  tables.list[tables.top].insert(*$2, variableType);
                if (result == -1){
                   yyerror("id has been uesd");
                }
                if (tables.top == 0){
                    assember.globalVar(intType, *$2);
                }
                else{
                    assember.localVar(*$2);
                }
            }
            | VAR ID ':' DATA_TYPE '[' INT_CONST ']'{
                Trace("VAR ID : DATA_TYPE [NUM]");
                int result =  tables.list[tables.top].insert(*$2, arrayType, $4, $6);
                if (result == -1){
                   yyerror("id has been uesd");
                }
                if (tables.top == 0){
                    
                }
                else{
                    
                }
            }

/*  常數宣告 實作  */
CONST_DEC:  VAL ID {
                assember.fp = assember.output.tellp();
                } ':' DATA_TYPE '=' EXP {
                Trace("VAL ID : DATA_TYPE = EXP");
                if ($5 != $7->valueType){
                    if($5 != floatType && $7->valueType != floatType){
                        yyerror("TYPE ERROR");
                    }
                }
                int result =  tables.list[tables.top].insert(*$2, constType, $7);
                if (result == -1){
                   yyerror("id has been uesd");
                }
                assember.output.seekp(assember.fp);
            }
            | VAL ID {
                assember.fp = assember.output.tellp();
            } '=' EXP {
                Trace("VAL ID = EXP");
                int result = tables.list[tables.top].insert(*$2 ,constType, $5);
                
                if (result == -1){
                    yyerror("id has been uesd");
                }
                assember.output.seekp(assember.fp);
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

                            assember.funInvke(*$1,tmp->returnType);

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
                            assember.funInvke(*$1,tmp->returnType, $3);

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

            assember.output << "iadd\n";

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

            assember.output << "isub\n";

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

            assember.output << "imul\n";

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

            assember.output << "idiv\n";

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

            assember.output << "ineg\n";

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

            assember.output << "ior\n";

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

            assember.output << "iand\n";

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
            assember.ls();
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
            assember.gt();
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
            assember.eq();
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
            assember.ge();
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
            assember.le();
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
            assember.ne();
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

            assember.output << "ixor\n";

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
            if (tmp->idType == constType){
                assember.pushConstant(tmp->value);
            }
            else if (tmp->symbolTable_index != 0){
                assember.pushLocal(tmp);
            }else{
                assember.pushGlobal(tmp);
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

            $$ = tmp->arrayValue[$3->intval];
            
        }
        | VALUE {
            assember.pushConstant($1);
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