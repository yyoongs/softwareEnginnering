#ifndef _REGISTERTICKETUI_H__
#define _REGISTERTICKETUI_H__

#include <iostream>
#include <fstream>
#include "memberLister.h"
#include "session.h"

using namespace std;

// class : RegisterTicket
// ���� : Ƽ�� ��� ����� boundary class
// ������ : ������
// ������ : ���뼺
class RegisterTicketUI
{

private:
	static RegisterTicketUI* RegisterTicketUIInstance;
	RegisterTicketUI();

public:
	~RegisterTicketUI();
	static RegisterTicketUI* getRegisterTicketUIInstance();
	void startInterface(ifstream & in_fp, ofstream& out_fp);
	void menu3_1output(ofstream& out_fp, int price, string game_date_time, string game_home_team, string game_away_team, string game_seat_number, bool auction_check);
	void menu3_1fail(ofstream& out_fp);
};


#endif _REGISTERTICKETUI_H__
