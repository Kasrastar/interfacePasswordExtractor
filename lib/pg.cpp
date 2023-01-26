#include <iostream>
#include <vector>
#include <memory>
#include <array>
#include <algorithm>
#include "pg.h"
#include "Trim.h"


std::string exec( const char* cmd) {

    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

std::string PasswordStorage::extract_string(const std::string str , const int index) {
    bool visit = false;
    std::string result;
    for ( int i = index ; str[i] != '\n'; i++ ){
        if ( str[i] == ':'){
            visit = true;
            continue;
        }
        if (visit)
            result += str[i];
    }
    return result;
}

std::vector<std::string> PasswordStorage::get_profiles(){
    
    const std::string command = "netsh wlan show profiles";
    std::string result = exec(command.c_str());
    std::vector<std::string> profiles;
    int found = result.find("All User Profile");
    while (found != std::string::npos){
        Trim obj(extract_string(result, found));
        profiles.push_back(obj.trim());
        found = result.find("All User Profile", found+15);
    }
    return profiles;
}

std::string PasswordStorage::get_password( const std::string profile ){
    
    std::string command = "netsh wlan show profile \"interface\" key=clear";
    command.replace(command.find("interface"), 9, profile );
    std::string result = exec(command.c_str());
    return extract_string(result, result.find("Key Content"));
}