#ifndef _WITHDRAWMEMBER_H__
#define _WITHDRAWMEMBER_H__

#include "memberLister.h"
#include <iostream>
#include <fstream>


using namespace std;
// class : WithdrawMember
// 설명 : 회원탈퇴 기능의 control class
// 만든이 : 김영실
// 수정자 : 장유진
class WithdrawMember
{

private:
	WithdrawMember();
	static WithdrawMember* withdrawMemberInstance;

public:
	static WithdrawMember* getWithdrawMemberInstance();
	void withdrawMemberStart(ifstream& in_fp, ofstream& out_fp);
	void showWithdraw(ofstream& out_fp);
	~WithdrawMember();
};

#endif
