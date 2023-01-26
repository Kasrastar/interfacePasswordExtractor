#ifndef TRIM 
#define TRIM
    
    #include <iostream>

    class Trim {

        private:
            const std::string WHITESPACE = " \n\r\t\f\v";
            std::string trimString = ""; 

            std::string ltrim(const std::string &);
            std::string rtrim(const std::string &);        

        public:

            Trim( const std::string );

            void setTrimString(const std::string);
            std::string getTrimString() const;

            std::string trim();
    };

#endif