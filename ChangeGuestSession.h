#ifndef __CHANGEGUESTSESSION_H__
#define __CHANGEGUESTSESSION_H__

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// class : ChangeGuestSession
// 설명 : 세션을 guest로 만드는 기능의 control class
// 만든이 : 김영실
class ChangeGuestSession {
private:
	ChangeGuestSession();
	static ChangeGuestSession* ChangeGuestSessionInstance;


public:
	~ChangeGuestSession();
	static ChangeGuestSession* getChangeGuestSessionInstance();
	void changeGuestSessionStart(ofstream& out_fp);
	void ChangeGuest(ofstream& out_fp);
};

#endif