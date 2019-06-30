#ifndef _WITHDRAWMEMBER_H__
#define _WITHDRAWMEMBER_H__

#include "memberLister.h"
#include <iostream>
#include <fstream>


using namespace std;
// class : WithdrawMember
// ���� : ȸ��Ż�� ����� control class
// ������ : �迵��
// ������ : ������
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
