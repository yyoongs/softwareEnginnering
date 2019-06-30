#include "time.h"
#include "ticketLister.h"


Time* Time::timeInstance = NULL;

Time* Time::getTimetInstance() {
	if (timeInstance == NULL) {
		timeInstance = new Time();
	}
	return timeInstance;
}


Time::Time() {

}

Time::~Time() {

}

//timer의 현재시간 time struct를 가져오는 함수
tm Time::getTime() {
	return currentTime;
}

//2019.05.30 조용성

//현재시간 설정 함수
void Time::setTime(ifstream& in_fp, ofstream& out_fp) {
	string inputTime;
	in_fp >> inputTime;
//	time_t time_current, time_now;
	char* context = NULL;	//남은 문자열이 들어갈 context
	int date[5];	// token화 한 date 정보가 들어갈 int형 배열
	int i=0;	
	char *strBuffer = new char[50];	//입력받은 값을 복사할 문자열 ( 입력받은 길이는 50으로 제한 ) // 날짜입력받는거라 문제없을 듯
	strcpy_s(strBuffer,50, inputTime.c_str());	//txt파일에서 받아온 정보를 50길이만큼 buffer에 복사
	char *token = strtok_s(strBuffer, ":",&context);	//strtok_s를 사용하여 ":"로 나눔
	while (token != nullptr)
	{
		date[i] = atoi(string(token).c_str());	//잘려진 token을 date에 넣는데 atoi를 사용해 string형을 int형으로 넣음
		i++;
		token = strtok_s(nullptr, ":",&context);	// 다음 buffer를 찾기위해 nullptr을 넣어서 순환시켜줌
	}

	currentTime.tm_year = date[0];
	currentTime.tm_mon = date[1];
	currentTime.tm_mday = date[2];
	currentTime.tm_hour = date[3];
	currentTime.tm_min = date[4];
	currentTime.tm_sec = 0;
	// currentTime 구조체에 날짜를 넣어줌

	currentTime.tm_year -= 1900;
	currentTime.tm_mon -= 1;
	// time 함수 계산시 1900년 기준이라 1900을 빼주고
	// 월도 0부터 시작이라 -1

	TicketLister* ticket_manage = TicketLister::getTicketsInstance();
	ticket_manage->TicketUpdate();	//티켓의 시간을 확인해 경매티켓으로 업데이트
	ticket_manage->TicketExpired();	//티켓의 남은시간이 6시간 이하일때 경매 종료
	ticket_manage->TicketDelete();	//티켓이 1년이상 지났을 때 삭제
	

	cout << "5.1. 현재시간 설정" << endl;
	cout << "> " << inputTime << endl;
	out_fp << "5.1. 현재시간 설정" << endl;
	out_fp << "> " << inputTime << endl << endl;

}

// 입력받은 time을 timer에 저장된 현재시간과 비교하여 차이를 hour단위로 출력
int Time::differTime(tm inputTime) {
	time_t time_current, time_input;

	
	inputTime.tm_year -= 1900;
	inputTime.tm_mon -= 1;
	
	// time_t 형식은 1900년부터 지금까지의 지나간 초
	time_current = mktime(&currentTime);	// tm 형식을 time_t형식의 초단위로 바꿈
	time_input = mktime(&inputTime);
	
	double differSecond;
	differSecond = difftime(time_input, time_current);	// 두 time_t 형식의 차이를 리턴

	int calculateDate[3];
	
	calculateDate[0] = (int)(differSecond / (60 * 60 * 24));
	differSecond -= calculateDate[0] * 60 * 60 * 24;
	//day 계산
	calculateDate[1] = (int)(differSecond / (60 * 60));
	differSecond -= calculateDate[1] * 60 * 60;
	//hour 계산
	calculateDate[2] = (int)(differSecond / 60);
	differSecond -= calculateDate[2] * 60;
	//min 계산

	return calculateDate[0] * 24 + calculateDate[1];	// day에 24를 곱한값 + 시간
	// ex) 2일 = 48시간 / 1일 6시간 = 30시간
}

// string으로 받아온 date를 tm 형태로 반환시켜주는 함수
tm Time::timeTypeSetting(string date) {
	char* context = NULL;	//남은 문자열이 들어갈 context
	int dateSet[5];	// token화 한 date 정보가 들어갈 int형 배열
	int i = 0;
	char *strBuffer = new char[50];	//입력받은 값을 복사할 문자열 ( 입력받은 길이는 50으로 제한 ) // 날짜입력받는거라 문제없을 듯
	strcpy_s(strBuffer, 50, date.c_str());	//txt파일에서 받아온 정보를 50길이만큼 buffer에 복사
	char *token = strtok_s(strBuffer, ":", &context);	//strtok_s를 사용하여 ":"로 나눔
	while (token != nullptr)
	{
		dateSet[i] = atoi(string(token).c_str());	//잘려진 token을 date에 넣는데 atoi를 사용해 string형을 int형으로 넣음
		i++;
		token = strtok_s(nullptr, ":", &context);	// 다음 buffer를 찾기위해 nullptr을 넣어서 순환시켜줌
	}

	struct tm inputTime;
	inputTime.tm_year = dateSet[0];
	inputTime.tm_mon = dateSet[1];
	inputTime.tm_mday = dateSet[2];
	inputTime.tm_hour = dateSet[3];
	inputTime.tm_min = dateSet[4];
	inputTime.tm_sec = 0;

	return inputTime;
}