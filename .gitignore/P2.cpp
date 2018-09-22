This problem was asked by Uber.
Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].
Follow-up: what if you can't use division?


#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

std::vector<int> Multiplier(std::vector<int> vecInput)
{
    std::vector<int> vecOutput(vecInput.size(),1);
    for ( int i=0; i < vecInput.size() ; i++)
    {
        for (int j= 0 ; j < vecOutput.size(); j++)
        {
            if ( i == j) continue;
            vecOutput[j] *= vecInput[i];
        }
    }
            
    
    return  vecOutput;
}

int main()
{
    std::vector<int> vecInput {1, 2, 3, 4, 5};
    std::vector<int> vecOutput = Multiplier(vecInput);
    std::cout << "[";
    for (int token : vecOutput) std::cout << token << "," ;
    std::cout << "]\n";
    
  
}
