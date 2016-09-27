// author xiangwei wangxiangwei.cpp@gmail.com
// 2016 9 
// to config parameter from file
#include <stdio.h>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
class Configure
{
public:
    Configure(){}
    Configure(std::string config_file_path)
    {
        std::fstream config_file;
        config_file.open(config_file_path.c_str(),std::fstream::in);
        if(config_file.is_open() == false)
        {
            printf("can not open file %s\n",config_file_path.c_str());
        }
        std::string config_line;
        while(std::getline(config_file,config_line))
        {
            std::stringstream config_line_stream(config_line);
            std::string key,value;
            if(std::getline(config_line_stream,key,'='))
            {
                if(std::getline(config_line_stream,value))
                {
                    parameters.insert(std::make_pair(key,value)); 
                }
            }
        }    
    }
    /*std::string GetValue(std::string key)
    {
        if(parameters.find(key)==parameters.end())
            printf("can not find parameter %s\n",key.c_str());
        return parameters[key];
    }*/
    template<typename T>
    T GetValue(std::string key)
    {
        if(parameters.find(key)==parameters.end())
        {
            printf("can not find parameter %s\n",key.c_str());
            return false;
        }
        T value;
        std::string value_s = parameters[key];
        std::stringstream value_stream(value_s);
        value_stream>>value;
        return value;

    }
    template<typename T>
    bool GetValue(std::string key,T &value)
    {
        if(parameters.find(key)==parameters.end())
        {
            printf("can not find parameter %s\n",key.c_str());
            return false;
        }
        std::string value_s = parameters[key];
        std::stringstream value_stream(value_s);
        value_stream>>value;
        return true;

    }
private:
    std::map< std::string,std::string> parameters;

};
