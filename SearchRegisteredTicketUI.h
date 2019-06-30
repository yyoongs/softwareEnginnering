#ifndef _SEARCHREGISTETREDTICKETUI_H__
#define _SEARCHREGISTETREDTICKETUI_H__

#include <iostream>
#include <fstream>
#include "memberLister.h"
#include "session.h"

using namespace std;

// class : SearchRegisteredTicket
// ���� : �Ǹ����� �Ǹ�Ƽ�� ��ȸ ����� control class
// ������ : ������
// ������ : ���뼺
class SearchRegisteredTicketUI
{

private:
	static SearchRegisteredTicketUI* SearchRegisteredTicketUIInstance;
	SearchRegisteredTicketUI();

public:
	~SearchRegisteredTicketUI();
	static SearchRegisteredTicketUI* getSearchRegisteredTicketUIInstance();
	void startInterface(ofstream & out_fp);
	void menu3_2output(ofstream& out_fp, vector<Ticket*> temp_sellerTicket, int num_ticket);

};

#endif