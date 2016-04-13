// DHCP Manager.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DHCPEntry.h"
using namespace std;

bool read_history(DHCP_ENTRY & output, istream & history_file) {
	output.clear();
	string rawdata;
	if (getline(history_file, rawdata)) {
		string temp;
		unsigned int pos = 0;

		for (unsigned int i = 0; i < rawdata.size(); i++) {
			if ((rawdata[i] == '\t') || (rawdata[i] == ' ')){
				if (pos == 3) {
					// Reads Hostname from history (if available)
					output.set_hostname(temp);
					temp.clear();
					pos++;
				}
				if (pos == 2) {
					// Reads Mac Address from history
					output.set_macaddress(temp);
					temp.clear();
					pos++;
				}
				if (pos == 1) {
					// Reads Date from history
					output.set_date(temp);
					temp.clear();
					pos++;
				}
				if (pos == 0) {
					// Reads IP address from history
					output.set_ip(temp);
					temp.clear();
					pos++;
				}
			}
			else {
				temp += rawdata[i];
			}
		}

		return true;
	}
	else {
		return false;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	string history_FilePath = "C:\\Users\\sleblanc\\documents\\visual studio 2013\\Projects\\DHCPhistorylogger\\DHCPhistorylogger\\DHCPhistory.log";

	ifstream history_file(history_FilePath.c_str());
	
	DHCP_ENTRY current_entry;

	while (read_history(current_entry, history_file)) {
		current_entry.print();
	}

	cin.get();

	return 0;
}

