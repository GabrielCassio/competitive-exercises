#pragma once

#include <cstddef>
#include <string>

template <typename T>
class Hashing {
    private:
    public:
        inline int fold(const std::string & text){
            size_t length = text.length();
            int sum = 0;
            for (size_t i = 0; i < length - 1; i++){
                sum += text[i];
            }

            return abs(sum)%100;
        }
        
        inline int sfold(const std::string& text){
            size_t len_string = (text.length()/4);
            int sum = 0;
            for (size_t i = 0; i < len_string - 1; i++){
                std::string sub = 
            }

        }
};