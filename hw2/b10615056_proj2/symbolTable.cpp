#include "symbolTable.hpp"


valueInfo* stringValue(string *value){
    valueInfo *info = new valueInfo();
    info->valueType = stringType;
    info->stringval = value;
    return info;
}
valueInfo* intValue(int value){
    valueInfo *info = new valueInfo();
    info->valueType = intType;
    info->intval = value;
    return info;
}
valueInfo* floatValue(float value){
    valueInfo *info = new valueInfo();
    info->valueType = floatType;
    info->floatval = value;
    return info;
}
valueInfo* boolValue(bool value){
    valueInfo *info = new valueInfo();
    info->valueType = boolType;
    info->boolval = value;
    return info;
}
valueInfo* charValue(char value){
    valueInfo *info = new valueInfo();
    info->valueType = charType;
    info->charval = value;
    return info;
}



valueInfo::valueInfo(){
    valueType = valueTypeError;
    int intval = 0;
    float floatval = 0;
    bool boolval = 0;
    char charval = 0;
    string *stringval = new string();
}

idInfo::idInfo(){
    string id ="";
    valueInfo *value = NULL;
    int idType = idTypeError;
    vector<valueInfo> arrayValue;
    int arrayValueType = unknowType;
    int arraySize = 0;
    int returnType= unknowType;
    bool hasInit = false;
}

symbolTable::symbolTable(){
    idMap.clear();
}

idInfo* symbolTable::lookup(string id){
    if (idMap.find(id) != idMap.end()){
        return idMap[id];
    }
    return NULL;
}
int symbolTable::insert(string id, int idType, valueInfo* valueInfo){
    if (idMap.find(id) != idMap.end()){
        return -1;
    }
    idInfo *tmp = new idInfo;
    tmp->id = id;
    tmp->idType = idType;
    tmp->value = valueInfo;
    tmp->hasInit = true;
    idMap[id] = tmp;
    return 1;
}
int symbolTable::insert(string id, int idType, int valueType){
    if (idMap.find(id) != idMap.end()){
        return -1;
    }
    if (idType == functionType){
        idInfo *tmp = new idInfo;
        tmp->id = id;
        tmp->idType = idType;
        tmp->returnType = valueType;
        idMap[id] = tmp;
    }
    idInfo *tmp = new idInfo;
    tmp->id = id;
    tmp->idType = idType;
    tmp->value = new valueInfo();
    tmp->value->valueType = valueType;
    tmp->hasInit = false;
    idMap[id] = tmp;
    return 1;
}
int symbolTable::insert(string id, int idType, int arrayValueType, int arraysize){
    if (idMap.find(id) != idMap.end()){
        return -1;
    }
    idInfo *tmp = new idInfo;
    tmp->id = id;
    tmp->idType = idType;
    tmp->arrayValueType = arrayValueType;
    tmp->arraySize = arraysize;
    for (int i=0;i<arraysize;i++){
        valueInfo *buf = new valueInfo;
        buf->valueType = arrayValueType;
        tmp->arrayValue.push_back(buf);
    }
    tmp->hasInit = true;
    idMap[id] = tmp;
    return 1;
}
int symbolTable::insert(string id, int idType){
    if (idMap.find(id) != idMap.end()){
        return -1;
    }
    idInfo *tmp = new idInfo();
    tmp->idType = idType;
    tmp->id = id;
    tmp->value = NULL;
    tmp->hasInit = false;
    idMap[id] = tmp;
    return 1;
}
symbolTableList::symbolTableList(){
    top = 0;
    list.push_back(symbolTable());
}

idInfo* symbolTableList::lookup(string id){
    for (int i=top; i>=0;i--){
        idInfo *tmp = list[i].lookup(id);
        if (tmp != NULL){
            return tmp;
        }
    }
    return NULL;
}
void symbolTableList::push(){
    list.push_back(symbolTable());
    ++top;

}
int symbolTableList::pop(){
    if (list.empty()){
        return -1;
    }

    list.pop_back();
    --top;
    return 1;
}
void symbolTableList::dump(){
    cout << "dump\n";
    int count = 1;
    for (int i=0;i<list.size();i++){
        if (!list[i].idMap.empty()){
            cout << "index: " << count << "\n";
            count ++;
            map<string, idInfo*>::iterator itr;
            for (itr = list[i].idMap.begin(); itr != list[i].idMap.end(); itr ++){
                cout << "id: " << itr->first << "\ttype: ";
                switch (itr->second->idType) {
                    case 0:
                        cout << "array\t[" ;
                        for (int i =0; i < itr->second->arraySize;i++){
                            switch (itr->second->arrayValueType) {
                                case intType:
                                    cout << itr->second->arrayValue[i]->intval ;
                                    break;
                                case floatType:
                                    cout << itr->second->arrayValue[i]->floatval ;
                                    break;
                                case boolType:
                                    cout << itr->second->arrayValue[i]->boolval ;
                                break;
                                case charType:
                                    cout << itr->second->arrayValue[i]->charval ;
                                break;
                                case stringType:
                                    cout << itr->second->arrayValue[i]->stringval ;
                                break;
                                case valueTypeError:
                                    cout << "value Type Error";
                                break;
                                default:
                                    cout << "unknow Type";
                                    break;
                            }
                            if (i != itr->second->arraySize - 1){
                                cout << ", ";
                            }
                        }
                        cout << "]\n";
                        break;
                    case 1:
                        cout << "function\n";
                        break;
                    case 2:
                        cout << "const\t";
                        switch (itr->second->value->valueType) {
                            case intType:
                                cout << itr->second->value->intval << endl;
                                break;
                            case floatType:
                                cout << itr->second->value->floatval<< endl ;
                                break;
                            case boolType:
                                cout << itr->second->value->boolval<< endl ;
                            break;
                            case charType:
                                cout << itr->second->value->charval << endl;
                            break;
                            case stringType:
                                cout << itr->second->value->stringval<< endl ;
                            break;
                            case valueTypeError:
                                cout << "value Type Error"<< endl;
                            break;
                            default:
                                cout << "unknow Type"<< endl;
                                break;
                        }
                        break;
                    case 3:
                        cout << "varible\t";
                        switch (itr->second->value->valueType) {
                            case intType:
                                cout << itr->second->value->intval << endl;
                                break;
                            case floatType:
                                cout << itr->second->value->floatval<< endl ;
                                break;
                            case boolType:
                                cout << itr->second->value->boolval<< endl ;
                            break;
                            case charType:
                                cout << itr->second->value->charval << endl;
                            break;
                            case stringType:
                                cout << itr->second->value->stringval<< endl ;
                            break;
                            case valueTypeError:
                                cout << "value Type Error"<< endl;
                            break;
                            default:
                                cout << "unknow Type"<< endl;
                                break;
                        }
                        break;
                    case 4:
                        cout << "error\n";
                        break;
                    case 5:
                        cout << "object\n";
                        break;
                    default:
                        break;
                }
            }
        }
    }
}
