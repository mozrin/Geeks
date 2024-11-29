#include <bits/stdc++.h>

#include "mydefinitions.h"
#include "exercises.cpp"

const std::string EXERCISE_CHOICE = "Exercise_0904";

int main()
{
    std::map<std::string, std::function<int()>> functions;
    
    functions["Exercise_0904"] = Exercise_0904;
    
    if (functions.find(EXERCISE_CHOICE) != functions.end())
    {
        functions[EXERCISE_CHOICE]();
        
        return 0;
    }
  
    return 1;
}