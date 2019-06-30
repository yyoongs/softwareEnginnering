#ifndef _LoginUI_H__
#define _LoginUI_H__

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// class : LoginUI
// 설명 : 세션을 입력한 user로 로그인하는 기능의 boundary class
// 만든이 : 김영실
// 수정자 : 장유진
class LoginUI
{

private:
	LoginUI();
	static LoginUI* LoginUIInstance;

public:
	void startInterface(ifstream& in_fp, ofstream& out_fp);
	static LoginUI* getLoginUIInstance();
	~LoginUI();
	void menu2_1output(ofstream& out_fp, string id, string passwd);
	void menu2_1fail(ofstream& out_fp);
};


#endif _LoginUI_H__
