#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <utility>

using namespace std;

enum valueType {
    intType,
    floatType,
    boolType,
    charType,
    stringType,
    valueTypeError,
    unknowType,
};

struct valueInfo{
    valueInfo();
    int valueType;
    int intval;
    float floatval;
    bool boolval;
    char charval;
    string* stringval = new string();
};

valueInfo* stringValue(string *value);
valueInfo* intValue(int value);
valueInfo* floatValue(float value);
valueInfo* boolValue(bool value);
valueInfo* charValue(char value);

enum IDType{
    arrayType,
    functionType,
    constType,
    variableType,
    idTypeError,
    objectType
};

struct idInfo{
    idInfo();
    string id ;
    valueInfo *value;
    int idType ;
    vector<valueInfo*> arrayValue;
    int arrayValueType;
    int arraySize;
    int returnType;
    int returnValue;
    bool hasInit;
};

struct symbolTable{
    symbolTable();
    map<string, idInfo*> idMap;
    idInfo* lookup(string id);
    int insert(string id, int idType, valueInfo *valueInfo);
    int insert(string id, int idType, int valueType);
    int insert(string id, int idType, int arrayValueType, int arraysize);
    int insert(string id, int idType);
};

struct symbolTableList{
    symbolTableList();
    vector<symbolTable> list;
    idInfo* lookup(string id);
    void push();
    int pop();
    void dump();
    int top;
};
