#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include "table_mgr.h"
#include "hulib.h"

using namespace std;

void print_cards(char* cards)
{
	for (int i = 0; i<9; ++i)
	{
		printf("%d,", cards[i]);
	}
	printf("  ");

	for (int i = 9; i<18; ++i)
	{
		printf("%d,", cards[i]);
	}
	printf("  ");
	for (int i = 18; i<27; ++i)
	{
		printf("%d,", cards[i]);
	}
	printf("  ");
	for (int i = 27; i<34; ++i)
	{
		printf("%d,", cards[i]);
	}
	printf("\n");
}

void test_hu()
{
	char cards[] = {
		1,0,1,0,0,2,0,2,0,
		1,1,1,0,0,3,0,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,2
	};
	if (HuLib::get_hu_info(cards, NULL, 34, 34, 33))
	{
		cout << "test_hu�ɹ�" << endl;
	}
}

#define MAX_COUNT (100 * 10000)
static BYTE s_HuCardAll[136];

void main()
{
	TableMgr::get_instance()->load();

	test_hu();
	
	for (int i = 0; i < 34; i++)
	{
		s_HuCardAll[i * 4] = i;
		s_HuCardAll[i * 4 + 1] = i;
		s_HuCardAll[i * 4 + 2] = i;
		s_HuCardAll[i * 4 + 3] = i;
	}
	
	int hu = 0;
	char cards[34] = { 0 };
	
	srand(1);
	DWORD dwTimeBegin = GetTickCount();
	for (int n = 0; n<MAX_COUNT; ++n)
	{
		random_shuffle(s_HuCardAll, s_HuCardAll + 126);		// ��������Լ�����Ӱ��
		for (int i = 0; i<9; ++i)	// 136/14 -> 9
		{
			memset(cards, 0, sizeof(cards));
			for (int j = i * 14; j < i * 14 + 10; j++)
				++cards[s_HuCardAll[j]];
			cards[33] = 4;
			if(HuLib::get_hu_info(cards, NULL, 34, 34, 33))
			{
				hu++;
			}
		}
	}
	cout << "�������:" << 9 * MAX_COUNT/10000 << "��Σ�time:" << GetTickCount() - dwTimeBegin << "ms" << endl;
	cout << "Hu: " << hu << endl;
	cin >> hu;
}