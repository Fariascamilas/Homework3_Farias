#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <fstream>

class VectorGenerator{
public:
    std::vector<double> dVec;
    std::vector<std::string> sVec;
    std::vector<std::pair<int,int>> iMat;
    VectorGenerator(){}

    template<typename T>
    void processData(T param){
        if constexpr(std::is_same_v<T,double>){
            dVec.insert(param);
        }
        else if constexpr(std::is_same_v<T,std::string>){
            sVec.insert(param);
        }
        else if constexpr(std::is_same_v<T,std::pair<int,int>>){
            iMat.insert(param);
        }
    }
};
/*
template<typename T>
class VectorGenerator{
public:
    std::vector<T> data;
    void processData(T param){
        if constexpr(std::is_same_v<T,double>){

        }
    }
};
*/
class TagGenerator{
public:
    std::vector<std::pair<std::string,std::string>> JSON;
    void addTags(VectorGenerator data){
        std::string palabras = "[";
        std::string doubles = "[";
        std::string matriz = "[";
        for(auto d : data.dVec){
            if(d == data.dVec.back()){
                doubles += std::to_string(d) + "]";
            }
            else{
                doubles += std::to_string(d) + ", ";
            }
        }
        for(auto s : data.sVec){
            if(s == data.sVec.back()){
                palabras += s + "]";
            }
            else{
                palabras += s + ", ";
            }
        }
        for(auto l : data.iMat){
            std::string intList = "[" + std::to_string(l.first) + ", " + std::to_string(l.second) + "]"; 
            if(l == data.iMat.back()){
                matriz += intList + "]";
            }
            else{
                matriz += intList + ", ";
            }
        }
        JSON.push_back({"vec_doubles",doubles});
        JSON.push_back({"palabras",palabras});
        JSON.push_back({"listas",matriz});
    }
    void createJSON(){
        std::string json = "{\n";
        for (auto par : JSON){
            if(par == JSON.back()){
                json += par.first + " : " + par.second + "\n}";
            }
            else{
                json += par.first + " : " + par.second + ",\n";
            }
        }
        std::ofstream outf("myJSON.json");
        if(!outf){
            throw std::runtime_error("Error con el archivo de entrada (JSON)");
        }
        outf<<json;
        outf.close();
    }
};