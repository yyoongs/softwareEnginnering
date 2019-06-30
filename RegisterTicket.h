#ifndef _REGISTERTICKET_H__
#define _REGISTERTICKET_H__


#include <iostream>
#include <fstream>
#include "time.h"
#include "ticketLister.h"

using namespace std;

// class : RegisterTicket
// ���� : Ƽ�� ��� ����� control class
// ������ : ������
// ������ : ���뼺
class RegisterTicket {

private:
	RegisterTicket();
	static RegisterTicket* RegisterTicketInstance;

public:
	~RegisterTicket();
	static RegisterTicket* getRegisterTicketInstance();
	void RegisterTicketStart(ifstream& in_fp, ofstream& out_fp);
	void addNewTicket(ofstream& out_fp, int price, string game_date_time, string game_home_team, string game_away_team, string game_seat_number, bool auction_check);
	//RegisterTicketUI Ŭ������ ��������� ������ ����


};

#endif