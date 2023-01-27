# interfacePasswordExtractor
Win users may need see them saved password for interfaces. 
some users forgot them wi-fi passwords and with little knowledge thay try to reset router or paying extra money
but by using this application they could find any saved interface password or by one time running this application collect every single stored password.

## usage
* Clone repo into your computer
* move to cloned directory
* compiling application using following commands
  * compile pg.cpp.
    > g++ -c lib\pg.cpp
  * compile Trim.cpp.
    > g++ -c lib\Trim.cpp
  * compile main.cpp.
    > g++ -c main.cpp
  * build executable program. 
    > g++ -o main.exe *.o
 
 after all now you have to option :
 1. execute program without argument to see all interfaces stored password
    > main.exe
 2. execute program with multiple argument to see selected interface stored password
    > main.exe interface_name1 interface_name2 ...
  
fill free to use and enjoy ;) don't forget give ⭐
