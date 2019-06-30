#ifndef _WITHDRAWMEMBERUI_H__
#define _WITHDRAWMEMBERUI_H__
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// class : WithdrawMemberUI
// 설명 : 회원탈퇴 기능의 boundary class
// 만든이 : 김영실
// 수정자 : 장유진
class WithdrawMemberUI
{

private:
	WithdrawMemberUI();
	static WithdrawMemberUI* withdrawMemberUIInstance;

public:
	void startInterface(ifstream & in_fp, ofstream & out_fp);
	static WithdrawMemberUI* getWithdrawMemberUIInstance();
	~WithdrawMemberUI();
	void menu1_2output(ofstream& out_fp, string id);
	void menu1_2fail(ofstream& out_fp);
};

#endif _WITHDRAWMEMBERUI_H__