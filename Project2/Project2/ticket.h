#ifndef __TICKET_H__
#define __TICKET_H__

#include <string>
#include <iostream>

using namespace std;

class ticket
{
private:
	int price; //�������
	string game_date_time; //��� ��¥ �� �ð�
	string game_home_team; //Ȩ��
	string game_away_team; //�������
	int game_seat_number; //�¼���ġ
	bool auction_check; //��ż��ÿ���

public:
	ticket();
	~ticket();

};

#endif