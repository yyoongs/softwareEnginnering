#include "LogoutUI.h"
#include "Logout.h"

LogoutUI::LogoutUI()
{
}


LogoutUI::~LogoutUI()
{
}

LogoutUI* LogoutUI::logoutUIInstance = NULL;

LogoutUI* LogoutUI::getLogoutUIInstance() {
	if (logoutUIInstance == NULL)
	{
		logoutUIInstance = new LogoutUI();
	}
	return logoutUIInstance;
}


void LogoutUI :: menu2_2output(ofstream& out_fp, string id) {
	cout << "2.2. ·Î±×¾Æ¿ô" << endl;
	cout << "> " << id << endl;
	out_fp << "2.2. ·Î±×¾Æ¿ô" << endl;
	out_fp << "> " << id << endl << endl;
}

void LogoutUI::startInterface(ofstream& out_fp) {
	Logout *control = Logout ::getLogoutInstance();
	control->showLogout(out_fp);

}