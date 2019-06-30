#include "ManageBuyersTicketUI.h"
#include "ManageBuyersTicket.h"
#include "time.h"

ManageBuyersTicketUI::ManageBuyersTicketUI()
{

}


ManageBuyersTicketUI::~ManageBuyersTicketUI()
{
}




ManageBuyersTicketUI* ManageBuyersTicketUI::ManageBuyersTicketUIInstance = NULL;

ManageBuyersTicketUI* ManageBuyersTicketUI::getManageBuyersTicketUIInstance() {
	if (ManageBuyersTicketUIInstance == NULL) {
		ManageBuyersTicketUIInstance = new ManageBuyersTicketUI();
	}
	return ManageBuyersTicketUIInstance;
}

void ManageBuyersTicketUI::startInterface(ofstream & out_fp) {
	ManageBuyersTicket* control = ManageBuyersTicket::getManageBuyersTicketInstance();
	control->searchTicket(out_fp);
}


void ManageBuyersTicketUI::menu4_5output(ofstream& out_fp, vector<Ticket*> temp_buyerTicket, int num_ticket) {
	Time* timer = Time::getTimetInstance();
	cout << "4.5. ���� ���� ��ȸ" << endl;
	out_fp << "4.5. ���� ���� ��ȸ" << endl;

	for (int i = 0; i < num_ticket; i++) {
		Ticket* ticket = temp_buyerTicket.at(i);
		AuctionTicket* t = (AuctionTicket*)ticket;
		// ����Ƽ���� �ƴѰ�� ticket�� price�� ���
		if (t->getAuctionChoice() == false)
		{
			cout << "> " << ticket->getPrice() << " ";
			out_fp << "> " << ticket->getPrice() << " ";
			ticket->showDateAndTime(out_fp);

			cout << ticket->getHometeam() << " " << ticket->getAwayteam() << " " << ticket->getSeatPosition() << endl;

			out_fp << ticket->getHometeam() << " " << ticket->getAwayteam() << " " << ticket->getSeatPosition() << endl << endl;
		}
		// ������ ������ Ƽ���� ������ ���� ��� �����ݾ� ���
		else if(timer->differTime(t->getDateAndTime()) < 24 && t->getAuctionChoice() == true){
			cout << "> " << t->getPrice() << " ";
			out_fp << "> " << t->getPrice() << " ";
			t->showDateAndTime(out_fp);

			cout << t->getHometeam() << " " << t->getAwayteam() << " " << t->getSeatPosition() << endl;

			out_fp << t->getHometeam() << " " << t->getAwayteam() << " " << t->getSeatPosition() << endl << endl;
		}
		else // ������ ���������� ������ ���� �ʾ��� ��� �Ϲ�Ƽ�� �Ǹűݾ� ���
		{
			cout << "> " << ticket->getPrice() << " ";
			out_fp << "> " << ticket->getPrice() << " ";
			ticket->showDateAndTime(out_fp);

			cout << ticket->getHometeam() << " " << ticket->getAwayteam() << " " << ticket->getSeatPosition() << endl;

			out_fp << ticket->getHometeam() << " " << ticket->getAwayteam() << " " << ticket->getSeatPosition() << endl << endl;
		}
	}
}