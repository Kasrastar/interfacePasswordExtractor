#include <iostream>
#include <windows.h>
#include "lib/pg.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); 

void show_profile( std::string interface_name, std::string interface_pass){
    SetConsoleTextAttribute(console,3);
    std::cout << interface_name ;
    SetConsoleTextAttribute(console,15);
    std::cout << "'s Network Password is : " ;
    SetConsoleTextAttribute(console,6);
    if ( interface_pass.empty() )
        std::cout << "free or not connected yet" << std::endl;
    else
        std::cout << interface_pass << std::endl ;
}

int main(int argc, const char** argv){
    
    PasswordStorage obj;
    if ( argc == 1 ){
        std::vector<std::string> profiles = obj.get_profiles();
        for ( auto profile: profiles)
            show_profile(profile, obj.get_password(profile));
    } else {
        for ( int i=1; i < argc; i++ ){
            std::string profile_name = argv[i];
            show_profile( profile_name, obj.get_password(profile_name));
        }
    }
    SetConsoleTextAttribute(console, 15);
    return 0;
}