#include "ManageBuyersTicket.h"
#include "ManageBuyersTicketUI.h"

ManageBuyersTicket::ManageBuyersTicket()
{
}


ManageBuyersTicket::~ManageBuyersTicket()
{
}


ManageBuyersTicket* ManageBuyersTicket::ManageBuyersTicketInstance = NULL;

ManageBuyersTicket* ManageBuyersTicket::getManageBuyersTicketInstance() {
	if (ManageBuyersTicketInstance == NULL) {
		ManageBuyersTicketInstance = new ManageBuyersTicket();
	}
	return ManageBuyersTicketInstance;
}

void ManageBuyersTicket::ManageBuyersTicketStart(ofstream& out_fp) {
	ManageBuyersTicketUI *boundaryUI = ManageBuyersTicketUI::getManageBuyersTicketUIInstance();
	// boundaryUI ����
	boundaryUI->startInterface(out_fp);
}

// �Ǹ��� ���Ƽ�� ��ȸ
// ������ : ���뼺
void ManageBuyersTicket::searchTicket(ofstream& out_fp) {
	ManageBuyersTicketUI *boundaryUI = ManageBuyersTicketUI::getManageBuyersTicketUIInstance();
	string id;
	int index = 0;
	int num_member;
	int num_ticket;

	// ������ ���̵� ������ memberlister�� memberlist���� ��ġ�ϴ� member�� ã�� buyer�� buyerticketlist���� ���
	Session* session_manage = Session::getSessionInstance();
	id = session_manage->getId();
	MemberLister* members__manage = MemberLister::getMembersInstance();
	num_member = members__manage->getNumberOfMember();
	vector<Member*> temp_members = members__manage->getMembers();
	for (int i = 0; i < num_member; i++) {
		if (id == temp_members.at(i)->getId()) {
			index = i;
			break;
		}
	}
	Buyer* temp_member = (Buyer*)temp_members.at(index);
	vector<Ticket*> temp_buyerTicket = temp_member->getBuyer_Ticket();
	num_ticket = temp_member->getNumberOfBuyerTicket();
	boundaryUI->menu4_5output(out_fp, temp_buyerTicket, num_ticket);

}