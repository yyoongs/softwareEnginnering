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

//timer�� ����ð� time struct�� �������� �Լ�
tm Time::getTime() {
	return currentTime;
}

//2019.05.30 ���뼺

//����ð� ���� �Լ�
void Time::setTime(ifstream& in_fp, ofstream& out_fp) {
	string inputTime;
	in_fp >> inputTime;
//	time_t time_current, time_now;
	char* context = NULL;	//���� ���ڿ��� �� context
	int date[5];	// tokenȭ �� date ������ �� int�� �迭
	int i=0;	
	char *strBuffer = new char[50];	//�Է¹��� ���� ������ ���ڿ� ( �Է¹��� ���̴� 50���� ���� ) // ��¥�Է¹޴°Ŷ� �������� ��
	strcpy_s(strBuffer,50, inputTime.c_str());	//txt���Ͽ��� �޾ƿ� ������ 50���̸�ŭ buffer�� ����
	char *token = strtok_s(strBuffer, ":",&context);	//strtok_s�� ����Ͽ� ":"�� ����
	while (token != nullptr)
	{
		date[i] = atoi(string(token).c_str());	//�߷��� token�� date�� �ִµ� atoi�� ����� string���� int������ ����
		i++;
		token = strtok_s(nullptr, ":",&context);	// ���� buffer�� ã������ nullptr�� �־ ��ȯ������
	}

	currentTime.tm_year = date[0];
	currentTime.tm_mon = date[1];
	currentTime.tm_mday = date[2];
	currentTime.tm_hour = date[3];
	currentTime.tm_min = date[4];
	currentTime.tm_sec = 0;
	// currentTime ����ü�� ��¥�� �־���

	currentTime.tm_year -= 1900;
	currentTime.tm_mon -= 1;
	// time �Լ� ���� 1900�� �����̶� 1900�� ���ְ�
	// ���� 0���� �����̶� -1

	TicketLister* ticket_manage = TicketLister::getTicketsInstance();
	ticket_manage->TicketUpdate();	//Ƽ���� �ð��� Ȯ���� ���Ƽ������ ������Ʈ
	ticket_manage->TicketExpired();	//Ƽ���� �����ð��� 6�ð� �����϶� ��� ����
	ticket_manage->TicketDelete();	//Ƽ���� 1���̻� ������ �� ����
	

	cout << "5.1. ����ð� ����" << endl;
	cout << "> " << inputTime << endl;
	out_fp << "5.1. ����ð� ����" << endl;
	out_fp << "> " << inputTime << endl << endl;

}

// �Է¹��� time�� timer�� ����� ����ð��� ���Ͽ� ���̸� hour������ ���
int Time::differTime(tm inputTime) {
	time_t time_current, time_input;

	
	inputTime.tm_year -= 1900;
	inputTime.tm_mon -= 1;
	
	// time_t ������ 1900����� ���ݱ����� ������ ��
	time_current = mktime(&currentTime);	// tm ������ time_t������ �ʴ����� �ٲ�
	time_input = mktime(&inputTime);
	
	double differSecond;
	differSecond = difftime(time_input, time_current);	// �� time_t ������ ���̸� ����

	int calculateDate[3];
	
	calculateDate[0] = (int)(differSecond / (60 * 60 * 24));
	differSecond -= calculateDate[0] * 60 * 60 * 24;
	//day ���
	calculateDate[1] = (int)(differSecond / (60 * 60));
	differSecond -= calculateDate[1] * 60 * 60;
	//hour ���
	calculateDate[2] = (int)(differSecond / 60);
	differSecond -= calculateDate[2] * 60;
	//min ���

	return calculateDate[0] * 24 + calculateDate[1];	// day�� 24�� ���Ѱ� + �ð�
	// ex) 2�� = 48�ð� / 1�� 6�ð� = 30�ð�
}

// string���� �޾ƿ� date�� tm ���·� ��ȯ�����ִ� �Լ�
tm Time::timeTypeSetting(string date) {
	char* context = NULL;	//���� ���ڿ��� �� context
	int dateSet[5];	// tokenȭ �� date ������ �� int�� �迭
	int i = 0;
	char *strBuffer = new char[50];	//�Է¹��� ���� ������ ���ڿ� ( �Է¹��� ���̴� 50���� ���� ) // ��¥�Է¹޴°Ŷ� �������� ��
	strcpy_s(strBuffer, 50, date.c_str());	//txt���Ͽ��� �޾ƿ� ������ 50���̸�ŭ buffer�� ����
	char *token = strtok_s(strBuffer, ":", &context);	//strtok_s�� ����Ͽ� ":"�� ����
	while (token != nullptr)
	{
		dateSet[i] = atoi(string(token).c_str());	//�߷��� token�� date�� �ִµ� atoi�� ����� string���� int������ ����
		i++;
		token = strtok_s(nullptr, ":", &context);	// ���� buffer�� ã������ nullptr�� �־ ��ȯ������
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