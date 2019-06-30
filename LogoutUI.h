#ifndef _LOGOUTUI_H__
#define _LOGOUTUI_H__

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// class : LogoutUI
// 설명 : 세션을 로그아웃하는 기능의 boundary class
// 만든이 : 김영실
// 수정자 : 장유진
class LogoutUI
{

private:
	LogoutUI();
	static LogoutUI* logoutUIInstance;

public:
	void startInterface(ofstream & out_fp);
	static LogoutUI* getLogoutUIInstance();
	~LogoutUI();
	void menu2_2output(ofstream& out_fp, string id);

};


#endif _LOGOUTUI_H__
