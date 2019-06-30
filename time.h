#ifndef __time_H__
#define __time_H__

#include <fstream>
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

// class : Time
// ���� : ������ ����ð��� ������ ������, �ð��� ���õ� ����� �������ִ� timer control class
// ������ : ���뼺
// 2019.05.30 
class Time {
private:
	static Time* timeInstance;
	struct tm currentTime;
	Time();

public:
	static Time* getTimetInstance();
	tm getTime();
	void setTime(ifstream& in_fp, ofstream& out_fp);
	int differTime(tm inputTime);
	tm timeTypeSetting(string date);
	~Time();

};

#endif