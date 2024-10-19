#pragma once
#include<iostream>
#include<vector>
#include<string>

#define N 50
std::vector<std::string> _src(N);
static int i = 0;

void src_init()
{

	while (true) {
		std::getline(std::cin, _src[i]); // 按行读取输入

		_src[i] += std::to_string(i);
		if (_src[i].empty()) { // 检查是否输入空行
			break;
		}

		i++;
	}

	std::cout << i << std::endl;

	return;
}

