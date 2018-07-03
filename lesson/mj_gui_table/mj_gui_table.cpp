// mj_gui_table.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <time.h>
#include <iostream>
#include "table_mgr.h"
#include "hulib.h"

// ��������
void test_no_gui()
{
	char cards[] = {
		1,0,1,0,0,2,0,2,0,
		1,1,1,0,0,3,0,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,2
	};
	int hu = HuLib::get_hu_info(cards, 34, 34);
	std::cout << "hu:" << hu << std::endl;
}

void test_4_gui()
{
	char cards[] = {
		1,0,1,0,0,2,0,2,0,
		1,1,1,0,0,3,0,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,2
	};
	int hu = HuLib::get_hu_info(cards, 33, 34);
	std::cout << "hu:" << hu << std::endl;
}

void test_8_gui()
{
	char cards[] = {
		1,0,1,0,0,1,0,0,2,
		1,0,1,0,0,2,0,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,2,3
	};
	int hu = 0;
	int begin = time(NULL);
	for (int i = 0; i < 1000*10000; ++i) {
		hu = HuLib::get_hu_info(cards, 32, 33);
	}
	std::cout << "hu:" << hu << " use time:"<<time(NULL)-begin<<"��"<<std::endl;
	getchar();
}

int main()
{
	TableMgr::init();
	TableMgr::load();
	test_no_gui();
	test_4_gui();
	test_8_gui();
    return 0;
}

