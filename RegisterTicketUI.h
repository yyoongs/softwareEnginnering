#ifndef _REGISTERTICKETUI_H__
#define _REGISTERTICKETUI_H__

#include <iostream>
#include <fstream>
#include "memberLister.h"
#include "session.h"

using namespace std;

// class : RegisterTicket
// 설명 : 티켓 등록 기능의 boundary class
// 만든이 : 장유진
// 수정자 : 조용성
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
