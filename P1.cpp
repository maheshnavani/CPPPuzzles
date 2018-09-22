This problem was recently asked by Google.
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
Bonus: Can you do this in one pass?


#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

bool TruePair(std::vector<int> vecInput, int iSum)
{
    std::unordered_set<int> setComp;
    for(int token : vecInput)
    {
        if ( setComp.find(token) != setComp.end()) 
            return true;
        else
            setComp.emplace(iSum - token);
    }
    return false;

}
int main()
{
    std::vector<int> vecInput {10, 15, 3, 7};
    std::cout << "Result for 17 = " << TruePair(vecInput,17) << "\n";
    std::cout << "Result for 19 = " << TruePair(vecInput,19) << "\n";
  
}


Output
=============

Result for 17 = 1
Result for 19 = 0
