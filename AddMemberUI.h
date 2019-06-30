#ifndef _ADDMEMBERUI_H__
#define _ADDMEMBERUI_H__

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// class : AddMemberUI
// 설명 : 로그인시 사용될 boundary함수 
// 만든이 : 김영실
class AddMemberUI
{

private:
	AddMemberUI();
	static AddMemberUI* addMemberUIInstance;

public:
	void startInterface(ifstream & in_fp, ofstream & out_fp);
	static AddMemberUI* getAddMemberUIInstance();
	~AddMemberUI();
	void menu1_1output(ofstream& out_fp, string id, string passwd, string name, string ssn, string user_type);
};


#endif _ADDMEMBERUI_H__
