#ifndef _LOGOUTUI_H__
#define _LOGOUTUI_H__

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// class : LogoutUI
// ���� : ������ �α׾ƿ��ϴ� ����� boundary class
// ������ : �迵��
// ������ : ������
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
