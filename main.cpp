#include <iostream>
#include <fstream>
#include "memberLister.h"
#include "session.h"
#include "time.h"
#include "ticketLister.h"
#include "SearchRegisteredTicket.h"
#include "RegisterTicket.h"
#include "AddMember.h"
#include "SearchAuctionTicket.h"
#include "BidForTicket.h"
#include "SearchTicket.h"
#include "ReserveTicket.h"
#include "ChangeGuestSession.h"
#include "ChangeUserSession.h"
#include "Login.h"
#include "Logout.h"
#include "WithdrawMember.h"
#include "ManageBuyersTicket.h"

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask(ifstream & in_fp, ofstream & out_fp);

// 변수 선언
FILE* in_fp, * out_fp;	// input output 파일 포인터 선언

int main()
{
	ifstream in_fp(INPUT_FILE_NAME);
	ofstream out_fp(OUTPUT_FILE_NAME);
	doTask(in_fp, out_fp);
	return 0;
}

void doTask(ifstream& in_fp, ofstream& out_fp)
{ // 메뉴 파싱을 위한 level 구분을 위한 변수
	int menu_level_1 = 0, menu_level_2 = 0; int is_program_exit = 0;

	while (!is_program_exit)
	{ // 입력파일에서 메뉴 숫자 2개를 읽기
		in_fp >> menu_level_1;
		in_fp >> menu_level_2;

		// 메뉴 구분 및 해당 연산 수행
		switch (menu_level_1)
		{
		case 1:
		{
			switch (menu_level_2)
			{
			case 1: // 1.1. 회원가입 메뉴
			{
				AddMember* control = AddMember::getAddMemberInstance();
				control->addMemberStart(in_fp, out_fp);

				break;
			}
			case 2:	// 1.2. 회원탈퇴 메뉴
			{
				WithdrawMember* control = WithdrawMember::getWithdrawMemberInstance();
				control->withdrawMemberStart(in_fp, out_fp);
			
				break;
			}
			}
			break;
		}
		case 2:
		{
			switch (menu_level_2)
			{
			case 1:	// 2.1 로그인 메뉴
			{
				Login* control = Login::getLoginInstance();
				control->LoginStart(in_fp, out_fp);

				break;
			}
			case 2: // 2.2 로그아웃 메뉴
			{
				Logout* control = Logout::getLogoutInstance();
				control->logOutStart(out_fp);

				break;
			}
			}
			break;
		}
		case 3:
		{
			switch (menu_level_2)
			{
			case 1: // 3.1. 판매티켓 등록 메뉴
			{
				RegisterTicket* control = RegisterTicket::getRegisterTicketInstance();
				control->RegisterTicketStart(in_fp, out_fp);

				break;
			}
			case 2:	// 3.2. 등록티켓 조회 메뉴
			{
				SearchRegisteredTicket* control = SearchRegisteredTicket::getSearchRegisteredTicketInstance();
				control->SearchRegisteredTicketStart(out_fp);

				break;
			}
			}
			break;
		}
		// case 4.3, 4.4 추가 (최유진)
		case 4:
		{
			switch (menu_level_2)
			{
				case 1:		// 티켓 검색 기능
				{
					SearchTicket* control = SearchTicket::getSearchTicketInstance();
					control->SearchTicketStart(in_fp,out_fp);

					break;
				}
				
				case 2: //티켓 예약 기능
				{
					ReserveTicket* control = ReserveTicket::getReserveTicketInstance();
					control->reserveTicketStart(in_fp, out_fp);

					break;
				}

				case 3: //auction 티켓 검색
				{
					SearchAuctionTicket* control = SearchAuctionTicket::getSearchAuctionTicketInstance();
					control->SearchAuctionTicketStart(in_fp, out_fp);

					break;
				}

				case 4: // auction 참여 기능
				{
					BidForTicket* control = BidForTicket::getBidForTicketInstance();
					control->BidForTicketStart(in_fp, out_fp);
					break;
				}

				case 5: //예약 정보 조회 기능
				{
					ManageBuyersTicket* control = ManageBuyersTicket::getManageBuyersTicketInstance();
					control->ManageBuyersTicketStart(out_fp);
					break;
				}
			}
			break;
		}
		case 5:
		{
			switch (menu_level_2)
			{
				case 1: // 시간 설정 기능
				{
				
					Time* time_manage=Time::getTimetInstance();	//time 클래스 생성 ( 이름 : time_manage )
					time_manage->setTime(in_fp, out_fp);	//setTime실행
					break;
				}
			
			}
			break;
		}
		case 6:
		{
			switch (menu_level_2)
			{
				case 1: // "6.1. 세션변경“ 메뉴 부분
				{
					ChangeUserSession* control = ChangeUserSession::getChangeUserSessionInstance();
					control->ChangeUserSessionStart(in_fp, out_fp);
					
					break;

				}
				case 2:
				{

					ChangeGuestSession* control = ChangeGuestSession::getChangeGuestSessionInstance();
					control->changeGuestSessionStart(out_fp);

					break;
				}
			}
			break;
		}


		case 7:
		{
			switch (menu_level_2)
			{
				case 1: // "7.1. 종료“ 메뉴 부분
				{
					cout << "prog exit" << endl;
					out_fp << "prog exit" << endl;
					is_program_exit = 1;
					break;
				}
			}
			break;
		}
		}
		cout << endl;
	}
}