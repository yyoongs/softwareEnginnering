#ifndef __CHANGEGUESTSESSION_H__
#define __CHANGEGUESTSESSION_H__

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// class : ChangeGuestSession
// ���� : ������ guest�� ����� ����� control class
// ������ : �迵��
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