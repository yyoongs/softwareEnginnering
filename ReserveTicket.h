#include "ticket.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// class : ReserveTicket
// ���� : Ƽ�� ���� ����� control class
// ������ : �迵��
// ������ : ���뼺 ������
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

