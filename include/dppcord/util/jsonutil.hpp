#ifndef JSONUTILS_HPP
#define JSONUTILS_HPP

#include "nlohmann/json.hpp"
#include <string>
#include <iostream>

#include "dppcord/core/objects/Snowflake.hpp"


namespace dppcord{



template <typename T>
inline T tryGetJson(const std::string& key, const nlohmann::json& json, const T& default_val){
    if(json.find(key) != json.end() && !json[key].is_null())
        return json[key].get<T>();
    std::cout << "Couldng load " << key << " loading default value instead\n";
    return default_val;
}

template <typename T>
inline T tryGetJson(const std::string& key, const nlohmann::json& json){
    return tryGetJson<T>(key,json,T());
}

inline Snowflake tryGetSnowflake(const std::string& key, const nlohmann::json& json){
    return Snowflake(tryGetJson<std::string>(key,json));
}

}

#endif