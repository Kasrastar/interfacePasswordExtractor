#include <iostream>
#include <string>
#include "Trim.h"

Trim::Trim( const std::string str ){
    if ( !str.empty() )
        setTrimString(str);
}

void Trim::setTrimString( const std::string str ) {
    this->trimString = str;
}

std::string Trim::getTrimString() const {
    return this->trimString;
}

std::string Trim::ltrim( const std::string &str) {
    size_t start = str.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : str.substr(start);
}

std::string Trim::rtrim( const std::string &str) {
    size_t end = str.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}

std::string Trim::trim() {
    return rtrim(ltrim(getTrimString()));
}
