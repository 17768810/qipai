#pragma once
#include<string>
#include<vector>

enum OP_TYPE
{
	OP_invalid = 0,
	OP_left_chi = 1<<1,
	OP_right_chi = 1<<2,
	OP_center_chi = 1<<3,
	OP_peng = 1<<4,
	OP_an_gang = 1<<5,
	OP_dian_gang = 1<<6,
	OP_jia_gang = 1<<7
};

struct CHI_PENG_GANG {
	char center_card;
	std::string type; // "left_chi","right_chi","center_chi","peng","an_gang","dian_gang","jia_gang"
	char provider;    // ��˭�ṩ��
};

int get_card_index(char card);

std::string get_card_str(char card);

int get_color(char card);

std::string get_color_str(char card);

int get_card_value(char card);

// �Ƶı�ʾ����1����������ʾ����cards[],�±��ʾ��Ӧ�ƣ�ֵ��ʾ���м��ţ���������2��1����cards[1]=2
// �����ܵ���ʹ��vector<CHI_PENG_GANG>
// �Ƶĳԡ������ܲ���

int get_chi_type(char* cards,char card_index);
void chi(char* cards, std::vector<CHI_PENG_GANG>& chi_peng_gang,char card_index,OP_TYPE op);

// ��
bool can_peng(char* cards, char card_index);
void peng(char* cards, std::vector<CHI_PENG_GANG>& chi_peng_gang, char card_index, char provider);

//����
bool can_an_gang(char* cards, char card_index, int left_cards_num);
void an_gang(char* cards, std::vector<CHI_PENG_GANG>& chi_peng_gang, char card_index);

//���
bool can_dian_gang(char* cards, char card_index, int left_cards_num);
void dian_gang(char* cards, std::vector<CHI_PENG_GANG>& chi_peng_gang, char card_index,char provider);

//�Ӹ�
bool can_jia_gang(char* cards, std::vector<CHI_PENG_GANG>& chi_peng_gang, char card_index, int left_cards_num);
void jia_gang(char* cards, std::vector<CHI_PENG_GANG>& chi_peng_gang, char card_index, char provider);