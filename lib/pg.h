#ifndef PG 
#define PG

    #include <iostream>
    #include <vector>
    
    class PasswordStorage {
        public:

            std::string extract_string(const std::string , const int);
            std::vector<std::string> get_profiles();
            std::string get_password( const std::string);
    };

#endif
