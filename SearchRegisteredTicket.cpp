#include "SearchRegisteredTicket.h"
#include "SearchRegisteredTicketUI.h"

SearchRegisteredTicket::SearchRegisteredTicket()
{
}


SearchRegisteredTicket::~SearchRegisteredTicket()
{
}


SearchRegisteredTicket* SearchRegisteredTicket::SearchRegisteredTicketInstance = NULL;

SearchRegisteredTicket* SearchRegisteredTicket::getSearchRegisteredTicketInstance() {
	if (SearchRegisteredTicketInstance == NULL) {
		SearchRegisteredTicketInstance = new SearchRegisteredTicket();
	}
	return SearchRegisteredTicketInstance;
}

void SearchRegisteredTicket::SearchRegisteredTicketStart(ofstream& out_fp) {

	SearchRegisteredTicketUI *boundaryUI = SearchRegisteredTicketUI::getSearchRegisteredTicketUIInstance();
	// boundaryUI 생성
	boundaryUI->startInterface(out_fp);

}

void SearchRegisteredTicket::searchTicket(ofstream& out_fp) {
	SearchRegisteredTicketUI *boundaryUI = SearchRegisteredTicketUI::getSearchRegisteredTicketUIInstance();

	string id;
	int index = 0;
	int num_member;
	int num_ticket;

	//세션의 아이디를 가져와서 memberlister의 memberlist에서 id와 일치하는 member를 찾아서 반환
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

	//seller의 티켓리스트를 가져와서 boundaryUI에서 출력
	Seller* temp_member = (Seller*)temp_members.at(index);

	vector<Ticket*> temp_sellerTicket = temp_member->getSeller_Ticket();

	num_ticket = temp_member->getNumberOfSellerTicket();


	boundaryUI->menu3_2output(out_fp, temp_sellerTicket, num_ticket);

}