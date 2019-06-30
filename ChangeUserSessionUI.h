#ifndef __CHANGEUSERSESSIONUI_H__
#define __CHANGEUSERSESSIONUI_H__

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// class : ChangeUserSessionUI
// 설명 : 세션을 입력한 user로 만드는 기능의 boundary class
// 만든이 : 김영실
class ChangeUserSessionUI {
private:
	static ChangeUserSessionUI* ChangeUserSessionUIInstance;
	ChangeUserSessionUI();

public:
	~ChangeUserSessionUI();
	static ChangeUserSessionUI* getChangeUserSessionUIInstance();
	void startInterface(ifstream& in_fp, ofstream& out_fp);

	void menu6_1output(ofstream& out_fp, string input_id);
	void menu6_1fail(ofstream& out_fp);

};

#endif