// split.cpp : �������̨Ӧ�ó������ڵ㡣
//
// mj_lesson.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include<time.h>
#include "hulib.h"

void check_hu()
{
	char cards[] = {
		0,
		3,1,1,1,1,1,1,1,3,		// ��
		0,0,0,0,0,0,0,0,0,		// Ͳ
		0,0,0,0,0,0,0,0,0,		// ��
		0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0
	};
	bool hu = false;
	int n = 1000 * 10000;
	int begin = time(NULL);
	std::cout << "ѡ����ַ������Ծ�������" << n / 10000 * 9 << "���" << std::endl;
	for (int j = 0; j < n; ++j) {
		for (int i = 1; i <= 9; ++i) {
			cards[i]++;
			hu = can_hu(cards);
			cards[i]--;
		}
	}
	std::cout << hu << std::endl;
	std::cout << "��ʱ:" << time(NULL) - begin << "��" << std::endl;
}

int main()
{
	check_hu();

	getchar();
	return 0;
}


