#include <iostream>
#include <fstream>
#include "ticket.h"


using namespace std;

// class : ReserveTicketUI
// 설명 : 티켓 예약 기능의 boundary class
// 만든이 : 김영실
// 수정자 : 조용성 장유진
class ReserveTicketUI
{

private:
	ReserveTicketUI();
	static ReserveTicketUI* ReserveTicketUIInstance;

public:
	~ReserveTicketUI();
	static ReserveTicketUI* getReserveTicketUIInstance();
	void startInterface(ifstream & in_fp, ofstream& out_fp);
	void menu4_2output(ofstream& out_fp, Ticket* t);
};
