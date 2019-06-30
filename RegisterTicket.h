#ifndef _REGISTERTICKET_H__
#define _REGISTERTICKET_H__


#include <iostream>
#include <fstream>
#include "time.h"
#include "ticketLister.h"

using namespace std;

// class : RegisterTicket
// 설명 : 티켓 등록 기능의 control class
// 만든이 : 장유진
// 수정자 : 조용성
class RegisterTicket {

private:
	RegisterTicket();
	static RegisterTicket* RegisterTicketInstance;

public:
	~RegisterTicket();
	static RegisterTicket* getRegisterTicketInstance();
	void RegisterTicketStart(ifstream& in_fp, ofstream& out_fp);
	void addNewTicket(ofstream& out_fp, int price, string game_date_time, string game_home_team, string game_away_team, string game_seat_number, bool auction_check);
	//RegisterTicketUI 클래스를 멤버변수로 가지고 있음


};

#endif