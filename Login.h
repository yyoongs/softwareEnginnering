#ifndef _LOGIN_H__
#define _LOGIN_H__

#include "memberLister.h"
#include <iostream>
#include <fstream>

using namespace std;

// class : Login
// 설명 : 세션을 입력한 user로 로그인하는 기능의 control class
// 만든이 : 김영실
// 수정자 : 장유진
class Login
{

private:
	Login();
	static Login* LoginInstance;

public:
	static Login* getLoginInstance();
	void LoginStart(ifstream& in_fp, ofstream& out_fp);
	void showLogin(ofstream& out_fp, string id, string passwd);
	~Login();
};

#endif