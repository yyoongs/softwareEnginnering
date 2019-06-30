#ifndef __CHANGEGUESTSESSIONUI_H__
#define __CHANGEGUESTSESSIONUI_H__

#include <string>
#include <vector>
#include <iostream>

using namespace std;


// class : ChangeGuestSessionUI
// 설명 : 세션을 guest로 만드는 기능의 boundary class
// 만든이 : 김영실
class ChangeGuestSessionUI {
private:
	static ChangeGuestSessionUI* ChangeGuestSessionUIInstance;
	ChangeGuestSessionUI();
public:
	~ChangeGuestSessionUI();
	static ChangeGuestSessionUI* getChangeGuestSessionUIInstance();
	void startInterface(ofstream& out_fp);
	void menu6_2output(ofstream& out_fp);

};

#endif