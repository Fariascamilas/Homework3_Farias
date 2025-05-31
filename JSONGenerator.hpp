#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <fstream>
#include <concepts>
template <typename T>
concept ValidParam = std::is_same_v<T,std::string> || std::is_same_v<T,std::pair<int,int>> || std::is_same_v<T,double>;

template<ValidParam T>
class VectorGenerator{
private:
    std::vector<T> data;
public:
    VectorGenerator(){}
    void addData(T param){
        if constexpr(std::is_same_v<T,double>){
            data.insert(std::to_string(param));
        }
        else if constexpr(std::is_same_v<T,std::string>){
            data.insert(param);
        }
        else if constexpr(std::is_same_v<T,std::pair<int,int>>){
            std::string str = "[" + std::to_string(param.first) + ", " + std::to_string(param.second) + "]";
            data.insert(str);
        }
    }
    std::vector<std::string> getData() const{
        return data;
    }
    std::string processData() const{
        std::string str = "[";
        if constexpr(std::is_same_v<T,std::string>){
            for(auto val : data){
                if(str == data.back()){
                    str += val + "]";
                }
                else{
                    str += val + ", ";
                }
            }
        }
    }
};

/*
class TagGenerator{
public:
    std::vector<std::pair<std::string,std::string>> JSON;
    void addTags(VectorGenerator data){

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
}; */