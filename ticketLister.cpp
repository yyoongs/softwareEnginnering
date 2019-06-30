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

	//2019.05.31 조용성
	
	for (int i = 0; i < NumOfTicket; i++) {
		t = tickets.at(i);
		tm ticketTime = t->getDateAndTime();
		int differTime = timer->differTime(ticketTime); //시간차이 계산
		if (differTime < 24)
		{
			int ticket_price = t->getPrice();
			tm ticket_date_time = t->getDateAndTime();
			string ticket_home = t->getHometeam();
			string ticket_away = t->getAwayteam();
			string ticket_seat = t->getSeatPosition();
			bool ticket_auction = t->getAuctionChoice();

			tickets.erase(tickets.begin() + i);	//ticket 삭제

			auction = new AuctionTicket(ticket_price, ticket_date_time, ticket_home, ticket_away, ticket_seat, ticket_auction);
			tickets.insert(tickets.begin() + i, auction);
			// 티켓리스트에서 삭제하고 옥션티켓으로 생성해서 새로 넣음
		}

	}
}


// 티켓 만료 
// 구매자가 있을 경우 availableSale 을 0으로
// 낙찰
void TicketLister::TicketExpired() {
	Ticket* t;
//	AuctionTicket* auction;
	Time* timer = Time::getTimetInstance();

	//2019.05.31 조용성
	for (int i = 0; i < NumOfTicket; i++) {
		t = tickets.at(i);
		AuctionTicket* auctionTicket = (AuctionTicket*)t;
		tm ticketTime = t->getDateAndTime();
		int differTime = timer->differTime(ticketTime); //시간차이 계산
		if (differTime < 6)	// 경기시간과 차이가 6보다 작을 때
		{
			cout << auctionTicket->getBuyerId() << endl;
			if (auctionTicket->getBuyerId() != "" )	//낙찰자가 있을 때
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

				Buyer* temp_member = (Buyer*)temp_members.at(index);	//temp_members를 seller로

				vector<Ticket*> temp_BuyerTicket = temp_member->getBuyer_Ticket();	//seller의 티켓리스트를 불러옴

				temp_BuyerTicket.push_back(t);	//seller의 티켓리스트에 넣기

				num_BuyerTicket = temp_member->getNumberOfBuyerTicket();	//seller의 티켓 갯수 가져오기
				num_BuyerTicket++;	// seller의 티켓갯수 멤버변수 +1
				temp_member->setNumberOfBuyerTicket(num_BuyerTicket);	//seller의 티켓갯수 멤버변수 업데이트


				temp_member->setBuyer_Ticket(temp_BuyerTicket);	//seller의 티켓리스트 업데이트
				//구매자 리스트에 추가하고 티켓에다가 판매완료체크
			}
			//낙찰자가 없을 때
			else  
			{
				auctionTicket->setAvailableSale(false);
				//아무일도 일어나지 않음
			}
		}

	}
}


// 1년지난 티켓 삭제
// 만든이 : 조용성
void TicketLister::TicketDelete() {
	Ticket* t;
	Time* timer = Time::getTimetInstance();
	// 티켓리스터의 티켓리스트에서 삭제
	for (int i = 0; i < NumOfTicket; i++) {
		t = tickets.at(i);
		tm ticketTime = t->getDateAndTime();
		int differTime = timer->differTime(ticketTime); //시간차이 계산
		if (differTime < -8760)	// 경기시간과 차이가 1년(8760시간)이상 차이날 때
		{
			tickets.erase(tickets.begin() + i);	//ticket 삭제
			NumOfTicket--;
			i--;
		}
	}
	//판매자의 티켓리스트에서 삭제
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
				int differTime1 = timer->differTime(ticketTime1); //시간차이 계산
				if (differTime1 < -8760)	// 경기시간과 차이가 1년(8760시간)이상 차이날 때
				{
					sellerTicketList.erase(sellerTicketList.begin() + j);	//ticket 삭제
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


//티켓을 추가하고 티켓리스트를 시간순으로 변경
// 만든이 : 조용성
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
			int first = timer->differTime(ticketTime); //시간차이 계산

			tm ticketTime2 = tickets.at(j + 1)->getDateAndTime();
			int second = timer->differTime(ticketTime2); //시간차이 계산

			if (first > second)
			{
				tickets.insert(tickets.begin() + j, tickets.at(j + 1));
				tickets.erase(tickets.begin() + j + 2);
			}
		}
	}

}