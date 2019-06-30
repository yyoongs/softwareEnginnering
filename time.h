#ifndef __time_H__
#define __time_H__

#include <fstream>
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

// class : Time
// 설명 : 설정한 현재시간을 변수로 가지며, 시간에 관련된 기능을 수행해주는 timer control class
// 만든이 : 조용성
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