#ifndef _SEARCHREGISTETREDTICKET_H__
#define _SEARCHREGISTETREDTICKET_H__

#include <iostream>
#include <fstream>

using namespace std;

// class : SearchRegisteredTicket
// ���� : �Ǹ����� �Ǹ�Ƽ�� ��ȸ ����� control class
// ������ : ������
// ������ : ���뼺
class SearchRegisteredTicket {

private:
	SearchRegisteredTicket();
	static SearchRegisteredTicket* SearchRegisteredTicketInstance;

public:
	~SearchRegisteredTicket();
	static SearchRegisteredTicket* getSearchRegisteredTicketInstance();
	void SearchRegisteredTicketStart(ofstream& out_fp);
	void searchTicket(ofstream& out_fp);
	//SearchRegisteredTicketUI Ŭ������ ��������� ������ ����


};

#endif