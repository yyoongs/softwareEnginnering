#include "ReserveTicket.h"
#include "ReserveTicketUI.h"
#include "ticketLister.h"
#include "session.h"
#include "memberLister.h"

ReserveTicket::ReserveTicket()
{
}


ReserveTicket::~ReserveTicket()
{
}

ReserveTicket* ReserveTicket::ReserveTicketInstance = NULL;

ReserveTicket* ReserveTicket::getReserveTicketInstance() {
	if (ReserveTicketInstance == NULL) {
		ReserveTicketInstance = new ReserveTicket();
	}
	return ReserveTicketInstance;
}

void ReserveTicket::reserveTicketStart(ifstream& in_fp, ofstream& out_fp)
{
	ReserveTicketUI* boundaryUI = ReserveTicketUI::getReserveTicketUIInstance();

	boundaryUI->startInterface(in_fp, out_fp);
}

// ������ : ������
void ReserveTicket::reserveTicket(ofstream& out_fp, string dateAndTime, string away, string seat) {
	ReserveTicketUI* boundaryUI = ReserveTicketUI::getReserveTicketUIInstance();
	Ticket* t;

	string id;
	int index = 0;
	int num_member;
	int num_ticket;

	Session* session_manage = Session::getSessionInstance();
	id = session_manage->getId();	//���� ������ �ҷ��� id�� �����´�
	MemberLister* members__manage = MemberLister::getMembersInstance();
	num_member = members__manage->getNumberOfMember();	// ����Ŵ��� Ŭ������ ��������� �����´�
	vector<Member*> temp_members = members__manage->getMembers();	// ��� ���͸� �����´�

	for (int i = 0; i < num_member; i++) {
		if (id == temp_members.at(i)->getId()) {
			index = i;
			break;
		}
	}
	// session�� id�� member vector�� id�� ��ġ�ϴ� member�� index�� �����´�

	Buyer* temp_buyer = (Buyer*)temp_members.at(index);
	// ������ member�� �ε����� �̿��Ͽ� buyer����
	TicketLister* ticketLister = TicketLister::getTicketsInstance();
	int NumOfTicket = ticketLister->getNumOfTicket();
	vector<Ticket*> tickets = ticketLister->getTicketList();
	for (int i = 0; i < NumOfTicket; i++) {
		t = tickets.at(i);
		if (t->getAvailableSale() == true && t->getAwayteam() == away && t->checkDateAndTime(dateAndTime) && t->getSeatPosition() == seat) {
			// �Է°��� �˸��� ���� ��������
			// �������� Ƽ�� ���͸� ������
			t->setAvailableSale(false);	//Ƽ���� �ǸŰ��ɿ��θ� false�� �ٲ�
			
			ticketLister->setTicketList(i); // Ƽ�ϸ������� i��°�� Ƽ�� �Ǹſ��� ������Ʈ

			vector<Ticket*> temp_BuyerTicket = temp_buyer->getBuyer_Ticket();
			temp_BuyerTicket.push_back(t);	//�������� Ƽ�Ϻ��Ϳ� �ش� Ƽ���� �־���
			temp_buyer->setBuyer_Ticket(temp_BuyerTicket);

			num_ticket = temp_buyer->getNumberOfBuyerTicket();	//������ Ƽ�ϰ��� ���� �����ͼ�
			num_ticket++;	//+1
			temp_buyer->setNumberOfBuyerTicket(num_ticket);	//���� ����

			boundaryUI->menu4_2output(out_fp, t);
		}
	}
}
