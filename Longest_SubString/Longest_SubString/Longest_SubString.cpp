// Longest_SubString.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <string>
#include <algorithm>

using namespace std;

/*
问题3：在一个字符串中寻找没有重复字母的最长子串，区分大小写
	如：“abcabcbb”,则结果为“abc”
	如“bbbbbb”，则结果为“b”
	如：“pwwkew”,则结果为“wke”
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int freq[256] = { 0 }; //定义存放对应字符出现频率的一个数组
		int l = 0;
		int r = 0; //滑动窗口s[l...r]中存放无重复字符子串

		int maxLength = 0; //无重复字符子串最大长度


		while (l<s.length())
		{
			if (r<s.length()&&freq[s[r]]==0)
			{
				freq[s[r]]++;
				r++;
			}
			else
			{
				freq[s[l]]--;
				l++;
			}
			//经过上述遍历后，r已经指向下一个需要遍历元素位置，所以实际子串长度，使用r-1来计算
			maxLength = max(maxLength, r - l);
		}

		return maxLength;
	}
};
int main()
{
	string str = "abcabcbb";

	int maxSubLen = Solution().lengthOfLongestSubstring(str);

	cout << str << " 的最大无重复子串的长度为：" << maxSubLen << endl;

    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
