#include "AddMember.h"
#include "AddMemberUI.h"

//생성자
AddMember::AddMember()
{
}

//소멸자
AddMember::~AddMember()
{
}

//싱글턴
AddMember* AddMember::addMemberInstance = NULL;

AddMember* AddMember::getAddMemberInstance() {
	if (addMemberInstance == NULL)
	{
		addMemberInstance = new AddMember();
	}
	return addMemberInstance;
}


//addMember 시작 함수
void AddMember::addMemberStart(ifstream& in_fp, ofstream& out_fp) {
	AddMemberUI* boundaryUI = AddMemberUI::getAddMemberUIInstance();

	boundaryUI->startInterface(in_fp,out_fp);
}


//기능 수행 함수
// boundary로부터 입력받은 값을 가져온다
// type에 따라 seller/buyer 생성
// 만든이 : 김영실
void AddMember::showSignUp(ofstream& out_fp, string id, string passwd, string name, string ssn, string user_type) {

	MemberLister* memberList = MemberLister::getMembersInstance();
	AddMemberUI* boundaryUI = AddMemberUI::getAddMemberUIInstance();
	Member* mem;

	if (user_type.compare("seller") == 0)	// seller 일때
	{
		mem = new Seller(id, passwd, name, ssn, user_type);
	}
	else if (user_type.compare("buyer") == 0)	//buyer 일때 
	{
		mem = new Buyer(id, passwd, name, ssn, user_type);
	}
	else   // 없을시 에러떠서 일단 생성 (의미 x)
	{
		mem = new Member();
	}

	memberList->addMembers(mem);
	//members.push_back(mem);	//member vector에 넣음

	memberList->addNumberOfMember();
	//NumberOfMember++;	//member num 증가

	boundaryUI->menu1_1output(out_fp, id, passwd, name, ssn, user_type); //출력
}