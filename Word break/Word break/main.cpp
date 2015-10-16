//
//  main.cpp
//  Word break
//
//  Created by 李佳 on 14/11/30.
//  Copyright (c) 2014年 LiJia. All rights reserved.
//

#include <iostream>
#include <unordered_set>
using namespace std;

/*class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int start = 0;
        int end = 1;
        
        string tmpStr = s.substr(start, end - start);
        while (end < s.length()) {
            if (std::find(dict.begin(), dict.end(), tmpStr) != dict.end())
            {
                start = end;
            }
            end++;
            tmpStr = s.substr(start, end - start);
        }
        
        return std::find(dict.begin(), dict.end(), tmpStr) != dict.end();
    }
}; */

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        
        bool *dp = new bool[s.length() * sizeof(bool)];
        
        for (int i = 0; i < s.length(); ++i)
        {
            dp[i] = std::find(dict.begin(), dict.end(), s.substr(0, i + 1)) != dict.end();
            if (dp[i])
                continue;
            else
            {
                for (int j = 0; j < i; ++j)
                {
                    if (dp[j])
                    {
                        dp[i] = (std::find(dict.begin(), dict.end(), s.substr(j + 1, i - j)) != dict.end()) | dp[i];
                    }
                }
            }
        }
        
        bool result = dp[s.length() - 1];
        delete []dp;
        return result;
    }
};

int main(int argc, const char * argv[])
{
    string input("leetcodeabcx");
    unordered_set<string> dict({"leet", "code", "ab", "cx"});
    
    Solution obj;
    std::cout << obj.wordBreak(input, dict)<< std::endl;
    return 0;
}
