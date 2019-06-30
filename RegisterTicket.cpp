#include "RegisterTicket.h"
#include "RegisterTicketUI.h"

RegisterTicket::RegisterTicket()
{
}


RegisterTicket::~RegisterTicket()
{
}


RegisterTicket* RegisterTicket::RegisterTicketInstance = NULL;

RegisterTicket* RegisterTicket::getRegisterTicketInstance() {
	if (RegisterTicketInstance == NULL) {
		RegisterTicketInstance = new RegisterTicket();
	}
	return RegisterTicketInstance;
}


void RegisterTicket::RegisterTicketStart(ifstream& in_fp, ofstream& out_fp) {
	RegisterTicketUI *boundaryUI = RegisterTicketUI::getRegisterTicketUIInstance();
	boundaryUI->startInterface(in_fp, out_fp);
}

// 만든이 : 김영실
void RegisterTicket::addNewTicket(ofstream& out_fp, int price, string game_date_time, string game_home_team, string game_away_team, string game_seat_number, bool auction_check) {
	RegisterTicketUI* boundaryUI = RegisterTicketUI::getRegisterTicketUIInstance();
	Time *timeManager = Time::getTimetInstance();
	TicketLister *tickets = TicketLister::getTicketsInstance();
	string id;
	Ticket* ticket;
	int index = 0; // 판매 티켓을 등록하려는 member의 index
	int num_member; // 현재 가입된 member 수
	int num_SellerTicket; //seller가 등록한 티켓 수

	//string으로 입력받은 game_date_time을 struct time함수로 알맞게 변경해줌 
	struct tm inputTime = timeManager->timeTypeSetting(game_date_time);

	if (timeManager->differTime(inputTime) < 48) {
		boundaryUI->menu3_1fail(out_fp);
		return;
	}
	//만약 현재 등록하는 티켓이 현재시간과 2일도 차이가 안난다면 티켓등록 불가

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

	Seller* temp_member = (Seller*)temp_members.at(index);	//temp_members를 seller로

	// 옥션선택여부가 1이고 남은시간이 24시간 이내일 때 auctionTicket으로 등록
	if (auction_check == 1 && timeManager->differTime(inputTime) < 24)
	{
		ticket = new AuctionTicket(price, inputTime, game_home_team, game_away_team, game_seat_number, auction_check);
	}
	else
	{
		ticket = new Ticket(price, inputTime, game_home_team, game_away_team, game_seat_number, auction_check);
	}


	int numOfTicket = tickets->getNumOfTicket();
	numOfTicket++;
	tickets->setNumOfTicket(numOfTicket);

	// 2019.06.03 조용성
	// 티켓리스트 클래스의 티켓리스트에 티켓추가하는 함수 만들어서 ticket추가
	// 티켓갯수 증가시키고 실행시켜야함
	tickets->addTicketList(ticket);


	vector<Ticket*> temp_sellerTicket = temp_member->getSeller_Ticket();	//seller의 티켓리스트를 불러옴

	temp_sellerTicket.push_back(ticket);	//seller의 티켓리스트에 넣기

	num_SellerTicket = temp_member->getNumberOfSellerTicket();	//seller의 티켓 갯수 가져오기
	num_SellerTicket++;	// seller의 티켓갯수 멤버변수 +1
	temp_member->setNumberOfSellerTicket(num_SellerTicket);	//seller의 티켓갯수 멤버변수 업데이트


	temp_member->setSeller_Ticket(temp_sellerTicket);	//seller의 티켓리스트 업데이트

	boundaryUI->menu3_1output(out_fp, price, game_date_time, game_home_team, game_away_team, game_seat_number, auction_check);
}