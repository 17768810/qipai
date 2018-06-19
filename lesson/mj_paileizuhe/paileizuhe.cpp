#include <vector>
#include "paileizuhe.h"


// �����Ƿ������������
bool check_zi(char* cards, bool& eye)
{
	for (int i = 28; i <= 34; ++i) {
		if (cards[i] == 0) continue;

		if (cards[i] == 1 || cards[i] == 4) return false;

		if (eye && cards[i] == 2) return false;

		if (cards[i] == 2) eye = true;
	}

	return true;
}

//�����cards�Ǻ��оŸ�Ԫ�ص�����
bool check_color(char* cards, bool& eye)
{
	struct T {
		int t;	//
		int i;	//��������
		T(int t,int i) {
			this->t = t;
			this->i = i;
		}
	};
	std::vector<T> items;
	//��ȡ�������
	for (int i = 0; i < 9; ++i)
	{
		if (i == 0) continue;

		// 1����ֻ���� ˳�ӵĿ���
		if (i == 1) {
			items.push_back(T(1,i));
		}
		// 2���� ����˳��
		else if (i == 2) {
			items.push_back(T(1, i));
			items.push_back(T(1, i));
		}
		// 3���� 1��˳�Ӻ�1������
		else if (i == 3) {
			items.push_back(T(2, i));
			items.push_back(T(1, i));
		}
		// 4���� 2��˳�Ӻ�1������
		else if (i == 3) {
			items.push_back(T(2, i));
			items.push_back(T(1, i));
			items.push_back(T(1, i));
		}
	}

	// ������ϣ�ѡ��3*n + 2���n���ƣ�������ϣ������ʣ��1�Խ������ܺ�
}

bool can_hu(char* cards)
{
	// �л��Ʋ��ܺ�
	for (int i = 35; i <= 42; ++i) {
		if (cards[i] != 0) return false;
	}
	bool eye = false;

	// ��鶫���ϱ��з���
	if (!check_zi(cards, eye)) return false;

	//�����
	if (!check_color(&cards[1], eye)) return false;

	//�����
	if (!check_color(&cards[10], eye)) return false;

	//���Ͳ
	if (!check_color(&cards[19], eye)) return false;

	return true;
}