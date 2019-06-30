#include <iostream>
#include <fstream>
#include "ticket.h"


using namespace std;

// class : SearchTicketUI
// ���� : Ƽ�� �˻� ����� boundary class
// ������ : �迵��
// ������ : ���뼺
class SearchTicketUI
{

private:
	SearchTicketUI();
	static SearchTicketUI* SearchTicketUIInstance;

public:
	~SearchTicketUI();
	static SearchTicketUI* getSearchTicketUIInstance();
	void startInterface(ifstream & in_fp, ofstream& out_fp);
	void menu4_1output1(ofstream& out_fp);
	void menu4_1output2(ofstream& out_fp, Ticket* t);
};
