#include "AddMember.h"
#include "AddMemberUI.h"

//������
AddMember::AddMember()
{
}

//�Ҹ���
AddMember::~AddMember()
{
}

//�̱���
AddMember* AddMember::addMemberInstance = NULL;

AddMember* AddMember::getAddMemberInstance() {
	if (addMemberInstance == NULL)
	{
		addMemberInstance = new AddMember();
	}
	return addMemberInstance;
}


//addMember ���� �Լ�
void AddMember::addMemberStart(ifstream& in_fp, ofstream& out_fp) {
	AddMemberUI* boundaryUI = AddMemberUI::getAddMemberUIInstance();

	boundaryUI->startInterface(in_fp,out_fp);
}


//��� ���� �Լ�
// boundary�κ��� �Է¹��� ���� �����´�
// type�� ���� seller/buyer ����
// ������ : �迵��
void AddMember::showSignUp(ofstream& out_fp, string id, string passwd, string name, string ssn, string user_type) {

	MemberLister* memberList = MemberLister::getMembersInstance();
	AddMemberUI* boundaryUI = AddMemberUI::getAddMemberUIInstance();
	Member* mem;

	if (user_type.compare("seller") == 0)	// seller �϶�
	{
		mem = new Seller(id, passwd, name, ssn, user_type);
	}
	else if (user_type.compare("buyer") == 0)	//buyer �϶� 
	{
		mem = new Buyer(id, passwd, name, ssn, user_type);
	}
	else   // ������ �������� �ϴ� ���� (�ǹ� x)
	{
		mem = new Member();
	}

	memberList->addMembers(mem);
	//members.push_back(mem);	//member vector�� ����

	memberList->addNumberOfMember();
	//NumberOfMember++;	//member num ����

	boundaryUI->menu1_1output(out_fp, id, passwd, name, ssn, user_type); //���
}