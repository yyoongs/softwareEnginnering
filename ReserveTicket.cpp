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

// 만든이 : 장유진
void ReserveTicket::reserveTicket(ofstream& out_fp, string dateAndTime, string away, string seat) {
	ReserveTicketUI* boundaryUI = ReserveTicketUI::getReserveTicketUIInstance();
	Ticket* t;

	string id;
	int index = 0;
	int num_member;
	int num_ticket;

	Session* session_manage = Session::getSessionInstance();
	id = session_manage->getId();	//현재 세션을 불러와 id를 가져온다
	MemberLister* members__manage = MemberLister::getMembersInstance();
	num_member = members__manage->getNumberOfMember();	// 멤버매니저 클래스의 멤버갯수를 가져온다
	vector<Member*> temp_members = members__manage->getMembers();	// 멤버 벡터를 가져온다

	for (int i = 0; i < num_member; i++) {
		if (id == temp_members.at(i)->getId()) {
			index = i;
			break;
		}
	}
	// session의 id와 member vector속 id와 일치하는 member의 index를 가져온다

	Buyer* temp_buyer = (Buyer*)temp_members.at(index);
	// 가져온 member의 인덱스를 이용하여 buyer생성
	TicketLister* ticketLister = TicketLister::getTicketsInstance();
	int NumOfTicket = ticketLister->getNumOfTicket();
	vector<Ticket*> tickets = ticketLister->getTicketList();
	for (int i = 0; i < NumOfTicket; i++) {
		t = tickets.at(i);
		if (t->getAvailableSale() == true && t->getAwayteam() == away && t->checkDateAndTime(dateAndTime) && t->getSeatPosition() == seat) {
			// 입력값에 알맞은 값을 가져오면
			// 구매자의 티켓 벡터를 가져옴
			t->setAvailableSale(false);	//티켓의 판매가능여부를 false로 바꿈
			
			ticketLister->setTicketList(i); // 티켓리스터의 i번째에 티켓 판매여부 업데이트

			vector<Ticket*> temp_BuyerTicket = temp_buyer->getBuyer_Ticket();
			temp_BuyerTicket.push_back(t);	//구매자의 티켓벡터에 해당 티켓을 넣어줌
			temp_buyer->setBuyer_Ticket(temp_BuyerTicket);

			num_ticket = temp_buyer->getNumberOfBuyerTicket();	//구매자 티켓갯수 변수 가져와서
			num_ticket++;	//+1
			temp_buyer->setNumberOfBuyerTicket(num_ticket);	//변수 설정

			boundaryUI->menu4_2output(out_fp, t);
		}
	}
}
