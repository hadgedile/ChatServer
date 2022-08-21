#include"json.hpp"
using json = nlohmann::json;

#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

//json序列化实例
string func1(){
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhangsan";
    js["to"] = "lisi";
    js["msg"] = "hello , what are you doing now?";
    
    string str=js.dump();
   // cout<<js<<endl;
    cout<<str.c_str()<<endl;
    return str;
}
string func3(){
    json js;

    //序列化一个VECTOR容器
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);

    js["list"] = vec;

    //序列化一个map容器
    map<int,string> m;
    m.insert({1,"黄山"});
    m.insert({2,"华山"});
    m.insert({3,"泰山"});


    js["path"]=m;

    string sendBuf=js.dump();
    return sendBuf;
}

int main(){
    string recvBuf=func1();
    //反序列化
    json jsbuf=json::parse(recvBuf);
    cout<<jsbuf["msg_type"]<<endl;
    cout<<jsbuf["from"]<<endl;
    cout<<jsbuf["to"]<<endl;
    cout<<jsbuf["msg"]<<endl;
    return 0;
}