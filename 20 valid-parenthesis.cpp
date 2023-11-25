class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack; // implement a stack that pushes open bracket and pops close bracket
        unordered_map<char, char> maps = {{')', '('}, {'}', '{'}, {']', '['}};   // create a map for brackets

        for (char x : s){
            // if it equals to maps.end(), it means x is open bracket
            if (maps.find(x) == maps.end()) stack.push(x);

            // if else triggers, we encounter a closing bracket
            // if the top element did not match the maps[x] means it is a mismatch and return false
            else{ 
                if(stack.empty() || stack.top() != maps[x]) return false; 
                // if it match, pop stack
                stack.pop();   
             }   
        }
        return stack.empty();   // if stack is empty, parenthesis is valid, else false.

    }
};
