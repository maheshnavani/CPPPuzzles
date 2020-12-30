
//
// DigitSum  Lottery Ticket :  
// 1 .. 10 , Digit sum is coupon 
// 1 -> 2
// 2 -> 1
// 3 -> 1
// ....
// 9 -> 1

// Find MaxFreq and MaxTime the MaxFreq occures 

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>
#include <string>
#include <vector>

std::string NumberToString(int Number)
{
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}

int sum(int i) {
    std::string s = NumberToString(i);
    int sum = 0;
    for (int k = 0; k < s.length(); k++)
        sum += s[k] - 48;
    return sum;
}

int computerefdigitsum(int i, int blocksize) {
    int tmp = i / blocksize;
    return sum(tmp);
}
int main()
{
    std::cout << "Hello World!\n";
    int n1 = 36227; //48444
    int n2 = 49969;//55924
    // Expected results 1,941

    // 1. find block size
    int blocksize = 100;
    int refCountSize = (NumberToString(blocksize).length() - 1) * 9;
    std::cout << "refCountSize =" << refCountSize << std::endl;
         

    // 2. Find Reference Count for given block size
    std::vector<int> referenceCount(refCountSize + 1);
    for (int i = 0; i <= refCountSize; i++) referenceCount.push_back(0);
    for (int i = 0; i < blocksize; i++) {
        int digitsum = sum(i);
        referenceCount[digitsum]++;
    }

    for (int i = 0; i <= refCountSize; i++)
        std::cout << i << ":" << referenceCount[i] << std::endl;
    std::map<int, int> freq;
    
    for (int n = n1; n <= n2; n++) {
        if (n % blocksize == 0) {
            std::cout << "Step 1:" << n << std::endl;
            for (auto e : freq)
                std::cout << e.first << ":" << e.second << std::endl;

            int k = n;

            while ( k <= ( n2 - blocksize)) {
                int refdigitsum = computerefdigitsum(k, blocksize);
                std::cout << "k=" << k << "|refdigitsum=" << refdigitsum << std::endl;
                
                for (int i = 0; i <= refCountSize; i++) {
                    freq[refdigitsum +  i ] += referenceCount[i];
                }
                

                std::cout << "Step 2: from:" << k << " to " << k+blocksize-1 << std::endl;
                for (auto e : freq)
                    std::cout << e.first << ":" << e.second << std::endl;
                k += blocksize;
            }
            int digitsum = sum(k);
            std::cout << "k=" << k << "|digitsum=" << digitsum << std::endl;
            freq[digitsum]++;

            n = k ;
        }
        else 
        
        {
            int digitsum = sum(n);
            std::cout << "n=" << n << "|digitsum=" << digitsum << std::endl;
            freq[digitsum]++;
        }
    }
    std::cout << "Step 3:" << std::endl;
    for (auto e : freq)
        std::cout << e.first << ":" << e.second << std::endl;

    int maxFreq = 0;
    int maxWays = 0;
    for (auto e : freq) {
        if (e.second > maxFreq) {
            maxFreq = e.second;
            maxWays = 1;
        }
        else if (e.second == maxFreq) {
            maxWays++;
        }

    }
    std::cout << "Result=" << maxFreq << ":" << maxWays << std::endl;
}
