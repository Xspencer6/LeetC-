#include <algorithm>
#include <map>
#include <string>
#include <iostream>

std::string customSortString(std::string order, std::string s){
    std::map<char, int> maps;
    std::string answer;

    // count the number of occurrence per char in s
    // store in map
    for (auto c : s) maps[c]++;

    // traverse through the order and append each occurrence of char to answer
    // delete that key value in maps
    for (auto c : order){
        if (maps.find(c) != maps.end()){    // that character exists in the string
            answer.append(maps[c], c);      // append that character n times where n is equal to its count to the answer
            maps.erase(c);  // erase from the maps so that all leftovers will be traverse later
        }
    }

    // check for remaining values in string (characters that are not included in order)
    for (auto x : maps){
        std::string temp(x.second, x.first);    // append the char and its number of occurrence to the string temp
        answer += temp;
    }

    return answer;
}

int main(){
    std::string test = "aabcd";
    std::string order = "dcb";

    std::cout << customSortString(order, test);

    return 0;
}