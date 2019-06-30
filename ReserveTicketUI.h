#include <iostream>
#include <fstream>
#include "ticket.h"


using namespace std;

// class : ReserveTicketUI
// ���� : Ƽ�� ���� ����� boundary class
// ������ : �迵��
// ������ : ���뼺 ������
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
