#include "anagram.h"
#include<bits/stdc++.h>
using namespace std;

string removeSpaces(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    str.erase(remove(str.begin(),str.end(),' '),str.end());
    return str;
}

bool Anagram::WordPairIsAnagram(const std::string& word1, const std::string& word2) {
    
    string word1_str=word1;
    string word2_str=word2;
    
    word1_str=removeSpaces(word1_str);
    word2_str=removeSpaces(word2_str);
    
    int word1_len=word1_str.length();
    int word2_len=word2_str.length();

    if(word1_len!=word2_len)
    {
        return false;
    }

    sort(word1_str.begin(),word1_str.end());
    sort(word2_str.begin(),word2_str.end());

   if(word1_str.compare(word2_str)==0)
    {
        return true;
    }

    return false;
}

std::vector<std::string> Anagram::SelectAnagrams(const std::string& word,
        const std::vector<std::string>& candidates) 
{
    vector<string> wordAnagrams={};
    
    for(string str:candidates)
    {
        if(WordPairIsAnagram(word,str))
        {
            wordAnagrams.push_back(str);
        }
    }
    return wordAnagrams;
}
