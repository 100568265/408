#include <iostream>
#include <string>
#include "sqlist.h"

int nativePatternMatch(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();

    for(int i = 0; i <= n - m; ++i) {
        //比较主串和模式串
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) ++j; //如果匹配，继续比较下一个字符
        if (j == m) return i;   //匹配成功，返回位置
    }
    return -1;  //如果不成功，返回-1
}

int main() {
    std::string text = "ABC ABCDAB ABCDABCDABDE";
    std::string pattern = "ABCDABD";
    int result = nativePatternMatch(text, pattern);
    std::cout << result << std::endl;
}





