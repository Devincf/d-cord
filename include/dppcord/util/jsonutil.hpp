#ifndef JSONUTILS_HPP
#define JSONUTILS_HPP

#include "rapidjson/document.h"
#include <string>
#include <iostream>

#include "dppcord/core/objects/Snowflake.hpp"


namespace dppcord{



inline bool jsonIsSet(const std::string& key, const rapidjson::Document& json)
{
    return (json.find(key) != json.end() && !json[key].is_null());
}

template <typename T>
inline T tryGetJson(const std::string& key, const rapidjson::Document& json, const T& default_val){
    if(jsonIsSet(key,json))
        return json[key].get<T>();
    //std::cout << "Couldng load " << key << " loading default value instead\n";
    return default_val;
}

template <typename T>
inline T tryGetJson(const std::string& key, const rapidjson::Document& json){
    return tryGetJson<T>(key,json,T());
}

inline Snowflake tryGetSnowflake(const std::string& key, const rapidjson::Document& json){
    return Snowflake(tryGetJson<std::string>(key,json));
}

}

#endif