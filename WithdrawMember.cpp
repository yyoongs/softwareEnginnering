#include "WithdrawMember.h"
#include "WithdrawMemberUI.h"
#include "session.h"


WithdrawMember::WithdrawMember()
{
}


WithdrawMember::~WithdrawMember()
{
}

WithdrawMember* WithdrawMember::getWithdrawMemberInstance() {
	if (withdrawMemberInstance == NULL)
	{
		withdrawMemberInstance = new WithdrawMember();
	}
	return withdrawMemberInstance;
}

WithdrawMember* WithdrawMember::withdrawMemberInstance = NULL;

void WithdrawMember::showWithdraw(ofstream& out_fp) {
	bool id_exist = false;
	int index;
	int num;
	Session* session_manage = Session::getSessionInstance();
	MemberLister* memberList = MemberLister::getMembersInstance();
	WithdrawMemberUI* boundaryUI = WithdrawMemberUI::getWithdrawMemberUIInstance();
	string id = session_manage->getId();	//���� ������ id�� �����´�

	for (int i = 0; i < memberList->getNumberOfMember(); i++) {
		if (id == memberList->getMembers().at(i)->getId()) {
			id_exist = true;
			index = i;
			break;
		}
	}		// for���� ���鼭 ��� ���͵��߿� ����� ���̵� ���� ���ǰ� �������
			// �� ��� ������ �ε����� ��ȯ

	// ��ġ�ϴ� ������Ͱ� ������ ��
	if (id_exist == true) {
		Member* temp_member = memberList->getMembers().at(index);	//���Ŭ���� ������ ����
		if (temp_member->getUser_type() == "seller") {
			Seller* temp_seller = (Seller*)temp_member;	//�Ǹ����� ��� seller�� ����ȯ
			if (temp_seller->getNumberOfSellerTicket() != 0) {	// �Ǹ����� Ƽ���� ���� �� 
				boundaryUI->menu1_2fail(out_fp); //ȸ������ �ȵɶ� ��¹�
				return;
			}
		}
		session_manage->setId("");	//������ ���̵� ""�� �ٲ� (guest id)
		memberList->getMembers().erase(memberList->getMembers().begin() + index);	//��������� �ش� Ŭ������ ����

		
		//member �� �Ҹ��� ����Ѵٰ� �ؼ� �־�ý��ϴ�. ���ڵ� ��� ��밡��									
		//vector<Member*> list = memberList->getMembers();
		//list.at(index)->~Member();

		num = memberList->getNumberOfMember();
		num -= 1;
		memberList->setNumberOfMember(num);	//member num -1
		session_manage->deleteSessionId(id); // Session class������ ���� �α��ε� id list���� ȸ�� Ż���� id�� �����.

		boundaryUI->menu1_2output(out_fp, id); //ȸ������ �Ϸ�� ��¹�
	}
}

	void WithdrawMember ::withdrawMemberStart(ifstream& in_fp, ofstream& out_fp) {
		WithdrawMemberUI* boundaryUI = WithdrawMemberUI::getWithdrawMemberUIInstance();

		boundaryUI->startInterface(in_fp, out_fp);
	}