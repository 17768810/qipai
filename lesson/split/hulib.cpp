#include "stdafx.h"
#include "hulib.h"

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

bool check_color_sub(char* cards)
{
	char c[9];
	memcpy(c, cards, 9);
	for (int i = 0; i < 9; ++i) {
		if (c[i] == 0) continue;
		else if (c[i] == 1) {
			if (i + 2 >= 9) return false;
			if (c[i + 1] < 1 || c[i + 2] < 1) return false;
			c[i + 1] -= 1;
			c[i + 2] -= 1;
		}
		else if (c[i] == 2) {
			if (i + 2 >= 9) return false;
			if (c[i + 1] < 2 || c[i + 2] < 2) return false;
			c[i + 1] -= 2;
			c[i + 2] -= 2;
		}
		else if (c[i] == 3) {
		}
		else if (c[i] == 4) {
			if (i + 2 >= 9) return false;
			if (c[i + 1] < 1 || c[i + 2] < 1) return false;
			c[i + 1] -= 1;
			c[i + 2] -= 1;
		}
	}
	return true;
}

bool check_color(char* cards,bool& eye)
{
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		sum += cards[i];
	}
	if (sum == 0) return true;
	int yu = sum % 3;
	if (yu == 1) return false;
	if (yu == 2 && eye) return false;

	if (yu == 0) return check_color_sub(cards);

	// ѡ��
	char eyes[7];
	char eye_num=0;

	for (int i = 0; i < 9; i++) {
		if (cards[i] >= 2) eyes[eye_num++] = i;
	}

	// û�н�
	if (eye_num == 0) return false;

	eye = true;

	for (int i = 0; i < eye_num; ++i) {
		cards[eyes[i]] -= 2;
		bool result = check_color_sub(cards);
		cards[eyes[i]] += 2;
		if (result) return true;
	}
	return false;
}


bool can_hu(char* cards)
{
	// �л��Ʋ��ܺ�
	for (int i = 35; i <= 42; ++i) {
		if (cards[i] != 0) return false;
	}

	bool eye = false;

	if (!check_zi(cards, eye)) {
		return false;
	}

	// ����Ѿ��н����������ֻ�ɫ�Ĳ�ֽ��
	//�����
	if (!check_color(&cards[1], eye)) return false;

	//�����
	if (!check_color(&cards[10], eye)) return false;

	//���Ͳ
	if (!check_color(&cards[19], eye)) return false;

	return true;
}