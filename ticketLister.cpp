#include "ticketLister.h"
#include "session.h"
#include "memberLister.h"
#include "time.h"

TicketLister* TicketLister::ticketsInstance = NULL;

TicketLister* TicketLister::getTicketsInstance() {
	if (ticketsInstance == NULL) {
		ticketsInstance = new TicketLister();
	}
	return ticketsInstance;
}

TicketLister::TicketLister() {
	NumOfTicket = 0;
}

TicketLister::~TicketLister() {

}


int TicketLister::getNumOfTicket() {
	return NumOfTicket;
}

void TicketLister::setNumOfTicket(int num) {
	NumOfTicket = num;
}

vector<Ticket*> TicketLister::getTicketList() {
	return tickets;
}

void TicketLister::setTicketList(int i) {

	tickets.at(i)->setAvailableSale(false);
}

void TicketLister::TicketUpdate() {
	Ticket* t;
	AuctionTicket* auction;
	Time* timer = Time::getTimetInstance();

	//2019.05.31 ���뼺
	
	for (int i = 0; i < NumOfTicket; i++) {
		t = tickets.at(i);
		tm ticketTime = t->getDateAndTime();
		int differTime = timer->differTime(ticketTime); //�ð����� ���
		if (differTime < 24)
		{
			int ticket_price = t->getPrice();
			tm ticket_date_time = t->getDateAndTime();
			string ticket_home = t->getHometeam();
			string ticket_away = t->getAwayteam();
			string ticket_seat = t->getSeatPosition();
			bool ticket_auction = t->getAuctionChoice();

			tickets.erase(tickets.begin() + i);	//ticket ����

			auction = new AuctionTicket(ticket_price, ticket_date_time, ticket_home, ticket_away, ticket_seat, ticket_auction);
			tickets.insert(tickets.begin() + i, auction);
			// Ƽ�ϸ���Ʈ���� �����ϰ� ����Ƽ������ �����ؼ� ���� ����
		}

	}
}


// Ƽ�� ���� 
// �����ڰ� ���� ��� availableSale �� 0����
// ����
void TicketLister::TicketExpired() {
	Ticket* t;
//	AuctionTicket* auction;
	Time* timer = Time::getTimetInstance();

	//2019.05.31 ���뼺
	for (int i = 0; i < NumOfTicket; i++) {
		t = tickets.at(i);
		AuctionTicket* auctionTicket = (AuctionTicket*)t;
		tm ticketTime = t->getDateAndTime();
		int differTime = timer->differTime(ticketTime); //�ð����� ���
		if (differTime < 6)	// ���ð��� ���̰� 6���� ���� ��
		{
			cout << auctionTicket->getBuyerId() << endl;
			if (auctionTicket->getBuyerId() != "" )	//�����ڰ� ���� ��
			{
				auctionTicket->setAvailableSale(false);
				string id;
				int num_member, index, num_BuyerTicket;
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

				Buyer* temp_member = (Buyer*)temp_members.at(index);	//temp_members�� seller��

				vector<Ticket*> temp_BuyerTicket = temp_member->getBuyer_Ticket();	//seller�� Ƽ�ϸ���Ʈ�� �ҷ���

				temp_BuyerTicket.push_back(t);	//seller�� Ƽ�ϸ���Ʈ�� �ֱ�

				num_BuyerTicket = temp_member->getNumberOfBuyerTicket();	//seller�� Ƽ�� ���� ��������
				num_BuyerTicket++;	// seller�� Ƽ�ϰ��� ������� +1
				temp_member->setNumberOfBuyerTicket(num_BuyerTicket);	//seller�� Ƽ�ϰ��� ������� ������Ʈ


				temp_member->setBuyer_Ticket(temp_BuyerTicket);	//seller�� Ƽ�ϸ���Ʈ ������Ʈ
				//������ ����Ʈ�� �߰��ϰ� Ƽ�Ͽ��ٰ� �ǸſϷ�üũ
			}
			//�����ڰ� ���� ��
			else  
			{
				auctionTicket->setAvailableSale(false);
				//�ƹ��ϵ� �Ͼ�� ����
			}
		}

	}
}


// 1������ Ƽ�� ����
// ������ : ���뼺
void TicketLister::TicketDelete() {
	Ticket* t;
	Time* timer = Time::getTimetInstance();
	// Ƽ�ϸ������� Ƽ�ϸ���Ʈ���� ����
	for (int i = 0; i < NumOfTicket; i++) {
		t = tickets.at(i);
		tm ticketTime = t->getDateAndTime();
		int differTime = timer->differTime(ticketTime); //�ð����� ���
		if (differTime < -8760)	// ���ð��� ���̰� 1��(8760�ð�)�̻� ���̳� ��
		{
			tickets.erase(tickets.begin() + i);	//ticket ����
			NumOfTicket--;
			i--;
		}
	}
	//�Ǹ����� Ƽ�ϸ���Ʈ���� ����
	MemberLister* memberLister = MemberLister::getMembersInstance();
	int i,j;
	vector<Member*> memberList = memberLister->getMembers();
	for (i = 0; i < memberLister->getNumberOfMember(); i++)
	{
		if (memberList.at(i)->getUser_type() == "seller")
		{
			Seller* temp_seller = (Seller*)memberList.at(i);
			vector<Ticket*> sellerTicketList = temp_seller->getSeller_Ticket();
			Ticket* ticket;
			for (j = 0; j < sellerTicketList.size(); j++) {
				ticket = sellerTicketList.at(j);
				tm ticketTime1 = ticket->getDateAndTime();
				int differTime1 = timer->differTime(ticketTime1); //�ð����� ���
				if (differTime1 < -8760)	// ���ð��� ���̰� 1��(8760�ð�)�̻� ���̳� ��
				{
					sellerTicketList.erase(sellerTicketList.begin() + j);	//ticket ����
					j--;
					temp_seller->setSellerTicketList(sellerTicketList);

					int num = temp_seller->getNumberOfSellerTicket();
					num--;
					temp_seller->setNumberOfSellerTicket(num);

				}
			}
		}
	}
}


//Ƽ���� �߰��ϰ� Ƽ�ϸ���Ʈ�� �ð������� ����
// ������ : ���뼺
void TicketLister::addTicketList(Ticket* ticket) {

	tickets.push_back(ticket);
	Time* timer = Time::getTimetInstance();
	int i, j;
	int ticketNum = NumOfTicket;
	for (i = 0; i < ticketNum; i++)
	{
		for (j = 0; j < (ticketNum - 1); j++)
		{
			tm ticketTime = tickets.at(j)->getDateAndTime();
			int first = timer->differTime(ticketTime); //�ð����� ���

			tm ticketTime2 = tickets.at(j + 1)->getDateAndTime();
			int second = timer->differTime(ticketTime2); //�ð����� ���

			if (first > second)
			{
				tickets.insert(tickets.begin() + j, tickets.at(j + 1));
				tickets.erase(tickets.begin() + j + 2);
			}
		}
	}

}