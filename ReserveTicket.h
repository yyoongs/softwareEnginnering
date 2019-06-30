#include "ticket.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// class : ReserveTicket
// 설명 : 티켓 예약 기능의 control class
// 만든이 : 김영실
// 수정자 : 조용성 장유진
class ReserveTicket {

private:
	ReserveTicket();
	static ReserveTicket* ReserveTicketInstance;

public:
	~ReserveTicket();
	static ReserveTicket* getReserveTicketInstance();
	void reserveTicketStart(ifstream& in_fp, ofstream& out_fp);
	void reserveTicket(ofstream& out_fp, string dateAndTime, string away, string seat);
};

