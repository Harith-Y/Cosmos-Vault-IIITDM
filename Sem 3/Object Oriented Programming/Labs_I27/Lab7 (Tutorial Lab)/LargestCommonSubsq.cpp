#include "MyString.hpp"

char* MyString :: largestCommonSubsequence(const char* str1, const char* str2) {
    if ((strLen(str1) == 0) || (strLen(str2) == 0)) {
        char* emptyStr = new char[1];
        emptyStr[0] = '\0';
        return emptyStr;
    }


    if (str1[strLen(str1) - 1] == str2[strLen(str2) - 1]) {
        // Find LCS of the prefixes of both strings (excluding the last character)
        char* lcsPrefix = largestCommonSubsequence(str1, str2);
        int prefixLength = strLen(lcsPrefix);

        char* result = new char[prefixLength + 2];  // +1 for the new character, +1 for null terminator

        strCpy(result, lcsPrefix); 
        result[prefixLength] = str1[strLen(str1) - 1];
        result[prefixLength + 1] = '\0';

        delete[] lcsPrefix;
        return result;

    } 
    
    else {
        char* lcs1 = largestCommonSubsequence(str1, str2 + 1);
        char* lcs2 = largestCommonSubsequence(str1 + 1, str2);

        if (strLen(lcs1) > strLen(lcs2)) {
            delete[] lcs2;
            return lcs1;
        } 
        
        else {
            delete[] lcs1;
            return lcs2;
        }
    }
}
