#include "WithdrawMember.h"
#include "WithdrawMemberUI.h"
#include "session.h"


WithdrawMember::WithdrawMember()
{
}


WithdrawMember::~WithdrawMember()
{
}

WithdrawMember* WithdrawMember::getWithdrawMemberInstance() {
	if (withdrawMemberInstance == NULL)
	{
		withdrawMemberInstance = new WithdrawMember();
	}
	return withdrawMemberInstance;
}

WithdrawMember* WithdrawMember::withdrawMemberInstance = NULL;

void WithdrawMember::showWithdraw(ofstream& out_fp) {
	bool id_exist = false;
	int index;
	int num;
	Session* session_manage = Session::getSessionInstance();
	MemberLister* memberList = MemberLister::getMembersInstance();
	WithdrawMemberUI* boundaryUI = WithdrawMemberUI::getWithdrawMemberUIInstance();
	string id = session_manage->getId();	//현재 세션의 id를 가져온다

	for (int i = 0; i < memberList->getNumberOfMember(); i++) {
		if (id == memberList->getMembers().at(i)->getId()) {
			id_exist = true;
			index = i;
			break;
		}
	}		// for문을 돌면서 멤버 벡터들중에 멤버의 아이디가 현재 세션과 같을경우
			// 그 멤버 벡터의 인덱스를 반환

	// 일치하는 멤버벡터가 존재할 때
	if (id_exist == true) {
		Member* temp_member = memberList->getMembers().at(index);	//멤버클래스 포인터 생성
		if (temp_member->getUser_type() == "seller") {
			Seller* temp_seller = (Seller*)temp_member;	//판매자일 경우 seller로 형변환
			if (temp_seller->getNumberOfSellerTicket() != 0) {	// 판매중인 티켓이 있을 때 
				boundaryUI->menu1_2fail(out_fp); //회원가입 안될때 출력물
				return;
			}
		}
		session_manage->setId("");	//세션의 아이디를 ""로 바꿈 (guest id)
		memberList->getMembers().erase(memberList->getMembers().begin() + index);	//멤버변수의 해당 클래스를 삭제

		
		//member 의 소멸자 써야한다고 해서 넣어봤습니다. 위코드 대신 사용가능									
		//vector<Member*> list = memberList->getMembers();
		//list.at(index)->~Member();

		num = memberList->getNumberOfMember();
		num -= 1;
		memberList->setNumberOfMember(num);	//member num -1
		session_manage->deleteSessionId(id); // Session class에서의 현재 로그인된 id list에서 회원 탈퇴한 id를 지운다.

		boundaryUI->menu1_2output(out_fp, id); //회원가입 완료시 출력물
	}
}

	void WithdrawMember ::withdrawMemberStart(ifstream& in_fp, ofstream& out_fp) {
		WithdrawMemberUI* boundaryUI = WithdrawMemberUI::getWithdrawMemberUIInstance();

		boundaryUI->startInterface(in_fp, out_fp);
	}