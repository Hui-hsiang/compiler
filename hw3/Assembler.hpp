//
//  Assembler.hpp
//  Assembler
//
//  Created by 黃暉翔 on 2020/6/25.
//  Copyright © 2020 黃暉翔. All rights reserved.
//

#ifndef Assembler_hpp
#define Assembler_hpp

#include <stdio.h>

#endif /* Assembler_hpp */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include "symbolTable.hpp"
#define maxStack 15
#define maxLocals 15
using namespace std;

class Assembler{
public:
    fstream output;
    vector<string> outputString;
    string objid;
    string fileName;
    vector<streampos> if_fps;
    streampos fp;
    string nowFunction;
    vector<string> localVeriableNumber;
    vector<int> Lstack;
    map<string,vector<string>> funcStack;
    int Lcount;
    Assembler(){
        localVeriableNumber.clear();
        Lcount = 0;
    };
    string Type2String(int type){
        switch (type) {
            case unknowType:
                return  ("void ");
                break;
            case intType:
                return ("int ");
                break;
            case floatType:
                return ("float ");
                break;
            case boolType:
                return ("bool");
                break;
            case charType:
                return ("char ");
                break;
            case stringType:
                return ("string ");
                break;
            default:
                return ("void ");
                break;
        }
    }
    void objinitial(string id){
        objid = id;
        fileName = objid + ".jasm";
        output.open(fileName,ios::trunc | ios::out);
        output<<"Class " << id << endl << "{" << endl;
        outputString.push_back("}");
        
    }
    void objFinish(){
        
        output<<outputString[outputString.size()-1];
        outputString.pop_back();
        
    }
    void mainDEC(){
        
        output<<"method public static void main(java.lang.String[])" << endl;
        output<<"max_stack " << maxStack <<endl;
        output<<"max_Locals " << maxLocals << endl;
        output<<"{"<<endl;
        outputString.push_back("return\n}\n");
        
    }
    void mainFinish(){
        
        output<<outputString[outputString.size()-1];
        outputString.pop_back();
        
    }
    
    void globalVar(int type , string id){
        
        output << "field static " << Type2String(type) <<  id << endl;
        
    }
    void globalVar(int type , string id, valueInfo* value){
        
        output << "field static " << Type2String(type) <<  id << " = " ;
        switch (value->valueType) {
            case intType:
                output << value->intval;
                break;
            case floatType:
                output << value->floatval;
                break;
            case boolType:
                
                if (value->boolval){
                    output << "1";
                }else{
                    output << "0";
                }
                break;
            case charType:
                output << value->charval;
                break;
            case stringType:
                output << "\"" << *(value->stringval) << "\"" ;
                break;
            default:
                output << value->intval;
                break;
        }
        output << endl;
        
        
    }
    void localVar(string id){
        localVeriableNumber = funcStack[nowFunction];
        localVeriableNumber.push_back(id);
        

        funcStack[nowFunction] = localVeriableNumber;
        
    }
    void localVar(string id, valueInfo* value){
        
        localVeriableNumber = funcStack[nowFunction];
        
        localVeriableNumber.push_back(id);
        
        

        
        

        output << "istore " << localVeriableNumber.size() - 1<<endl;

        
        funcStack[nowFunction] = localVeriableNumber;

    }
    void enterBlock(){
        
        
        
        
        
        
    }
    void leaveBlock(string id){
        
        
        
        
        
    
        funcStack[id] = localVeriableNumber;
        localVeriableNumber.clear();
    }
    void pushGlobal(idInfo* id){
        
        output << "getstatic ";
        output << Type2String(id->value->valueType) << " ";
        output << objid << "." << id->id << endl;
        
    }
    void pushLocal(idInfo* id){
        
        output << "iload ";
        vector<string> stack = funcStack[nowFunction];
        for (int i=0;i<stack.size();i++){
            if (stack[i] == id->id){
            output << i <<endl;
            }
        }
        
    }
    void putGlobal(idInfo* id){
        
        output << "putstatic ";
        output << Type2String(id->value->valueType) << " ";
        output << objid << "." << id->id << endl;
        
    }
    void putLocal(idInfo* id){
        
        output << "istore ";
        vector<string> stack = funcStack[nowFunction];
        for (int i=0;i<stack.size();i++){
            if (stack[i] == id->id){
            output << i <<endl;
            }
        }
        
    }
    void pushConstant(valueInfo * value){
        
        switch (value->valueType) {
            case intType:
                output << "ldc " << value->intval;
                break;
            case floatType:
                output << "ldc " << value->floatval;
                break;
            case boolType:
                output << "iconst_";
                if (value->boolval){
                    output << "1";
                }else{
                    output << "0";
                }
                break;
            case charType:
                output << "ldc " << value->charval;
                break;
            case stringType:
                output << "ldc \"" << *(value->stringval) << "\"";
                break;
            default:
                output << "ldc " << value->intval;
                break;
        }
        output << endl;
        
    }
    void funDEC(string id, int type){
        
        output << "method public static ";
        output << Type2String(type);
        output << id;
        output << "(" ;
        output << ")" << endl;
        output <<"max_stack " << maxStack <<endl;
        output <<"max_Locals " << maxLocals << endl;
        output <<"{"<<endl;
        outputString.push_back("return\n}\n");
        
        nowFunction = id;
    }
    
    void funDEC(string id,vector<idInfo*>* arg, int type){
        
        output << "method public static ";
        output << Type2String(type);
        output << id;
        output<< "(" ;
        for (int i=0;i<(*arg).size();i++){
            
            string tmp = (*arg)[i]->id;
            localVeriableNumber.push_back(tmp);
            
            if(i == (*arg).size() - 1){
                output << Type2String((*arg)[i]->value->valueType);
            
            }
            else{
                output << Type2String((*arg)[i]->value->valueType) << ", ";
            }
        }
        output<< ")" << endl;
        output<<"max_stack " << maxStack <<endl;
        output<<"max_Locals " << maxLocals << endl;
        output<<"{"<<endl;
        if (type == unknowType){
            outputString.push_back("return\n}\n");
        }
        else{
            outputString.push_back("ireturn\n}\n");
        }
        
        funcStack[id] = localVeriableNumber;
        nowFunction = id;

    }
    void funFinish(){
        
        output<<outputString[outputString.size()-1];
        outputString.pop_back();
        
    }
    void funInvke(string id, int type){
        nowFunction = id;
        
        output << "invokestatic ";
        output << Type2String(type);
        output << objid << "." << id;
        output<< "(" ;
        output<< ")" << endl;
        
        
    }
    void funInvke(string id, int type, vector<valueInfo*>* arg){
        nowFunction = id;
        
        output << "invokestatic ";
        output << Type2String(type);
        output << objid << "." << id;
        output<< "(" ;
        for (int i=0;i<(*arg).size();i++){
            
            if(i == (*arg).size() - 1){
                output << Type2String((*arg)[i]->valueType);
            
            }
            else{
                output << Type2String((*arg)[i]->valueType) << ", ";
            }
        }
        output<< ")" << endl;
        
        
    }
    void ls(){
        
        
        output << "isub" << endl;
        output << "iflt L" << Lcount++ << endl;
        output << "iconst_0" << endl;
        output << "goto L" << Lcount << endl;
        output << "L" << Lcount - 1 <<": iconst_1\n";
        output << "L" << Lcount++ << ":\n";
        
        
    }
    void gt(){
        
        
        output << "isub" << endl;
        output << "ifgt L" << Lcount++ << endl;
        output << "iconst_0" << endl;
        output << "goto L" << Lcount << endl;
        output << "L" << Lcount - 1 <<": iconst_1\n";
        output << "L" << Lcount++ << ":\n";
        
        
    }
    void eq(){
        
        
        output << "isub" << endl;
        output << "ifeq L" << Lcount++ << endl;
        output << "iconst_0" << endl;
        output << "goto L" << Lcount << endl;
        output << "L" << Lcount - 1 <<": iconst_1\n";
        output << "L" << Lcount++ << ":\n";

        
    }
    void ge(){
        
        
        output << "isub" << endl;
        output << "ifge L" << Lcount++ << endl;
        output << "iconst_0" << endl;
        output << "goto L" << Lcount << endl;
        output << "L" << Lcount - 1 <<": iconst_1\n";
        output << "L" << Lcount++ << ":\n";
        
        
    }
    void le(){
        
        
        output << "isub" << endl;
        output << "ifle L" << Lcount++ << endl;
        output << "iconst_0" << endl;
        output << "goto L" << Lcount << endl;
        output << "L" << Lcount - 1 <<": iconst_1\n";
        output << "L" << Lcount++ << ":\n";
        
        
    }
    void ne(){
        
        
        output << "isub" << endl;
        output << "ifne L" << Lcount++ << endl;
        output << "iconst_0" << endl;
        output << "goto L" << Lcount << endl;
        output << "L" << Lcount - 1 <<": iconst_1\n";
        output << "L" << Lcount++ << ":\n";
        
        
    }
    void ifCondition(){
        
        
        output << "ifeq L";
        Lstack.push_back(Lcount);
        output << Lcount++ << endl;
        
        
        
        
    }
    void ifFinish(){
        
        
        
        output << "goto L";
        fp = output.tellp();
        if_fps.push_back(fp);
        output << "      ";
        
        output <<endl<< "L" << Lstack[Lstack.size()-1] << ":"<<endl;
        Lstack.pop_back();
        Lstack.push_back(Lcount);
        Lcount++;
        
        
    }

    void elseFinish(){
        
        streampos now_fp;

        output << "goto L"<<Lstack[Lstack.size()-1]<<endl;
        output << "L" << Lstack[Lstack.size()-1] <<":"<<endl;
        now_fp = output.tellp();
        
        for(int i=0; i<if_fps.size();i++){
            output.seekp(if_fps[i]);
            output << Lstack[Lstack.size()-1];
        }
        if_fps.clear();
        output.seekp(now_fp);
        Lstack.pop_back();
        
        
    }
    
    void whileLoopBegin(){
        
        
        output << "L" << Lcount << ":\n";
        Lstack.push_back(Lcount);
        Lcount++;
        
        
    
    }
    void whileLoopIn(){
        
        
        output << "ifeq L" << Lcount << "\n";
        Lstack.push_back(Lcount);
        Lcount++;
        
        
    }
    void whileLoopexit(){
        
        
        output << "goto L" << Lstack[Lstack.size() - 2] << "\n";
        output << "L" << Lstack[Lstack.size() - 1] << ":\n";
        Lstack.pop_back();
        Lstack.pop_back();
        

    }
    void forLoopBegin(int Global, idInfo* id, valueInfo* from, valueInfo* end){
        pushConstant(from);
        if (Global == 0){
            putLocal(id);
            pushLocal(id);
        }
        else {
            putGlobal(id);
            pushGlobal(id);
        }
        whileLoopBegin();
        pushConstant(end);
        ls();
        whileLoopIn();
        
        
    }
    void forLoopFinish(int Global, idInfo* id, valueInfo* from, valueInfo* end){
        valueInfo* one = intValue(1);
        if (Global == 0){
            pushLocal(id);
        }
        else {
            pushGlobal(id);
        }
        pushConstant(one);
        output << "iadd\n";
        if (Global == 0){
            putLocal(id);
            pushLocal(id);
        }
        else {
            putGlobal(id);
            pushGlobal(id);
        }
        whileLoopexit();
    }
    
};
