#include "stdafx.h"
#include "DHCPEntry.h"

DHCP_ENTRY::DHCP_ENTRY(std::string input) {
	int entrypos = 0;
	std::string temp;

	for (unsigned int i = 0; i <= input.size(); i++){
		if (input[i] == ',') {
			data[entrypos] = temp;
			temp.clear();
			entrypos++;
		}
		else {
			temp += input[i];
		}
	}
	data[entrypos] = temp;
}

DHCP_ENTRY::DHCP_ENTRY() {
	for (unsigned int i = 0; i < 17; i++) {
		data[i] = '0';
	}
}

std::string const DHCP_ENTRY::get_id() const {
	return data[0];
}

std::string const DHCP_ENTRY::get_date() const {
	return data[1];
}

std::string const DHCP_ENTRY::get_time() const {
	return data[2];
}

std::string const DHCP_ENTRY::get_description() const {
	return data[3];
}

std::string const DHCP_ENTRY::get_ip() const {
	return data[4];
}

std::string const DHCP_ENTRY::get_hostname() const {
	return data[5];
}

std::string const DHCP_ENTRY::get_macaddress() const {
	return data[6];
}

std::string const DHCP_ENTRY::get_username() const {
	return data[7];
}

std::string const DHCP_ENTRY::get_transactionid() const {
	return data[8];
}

std::string const DHCP_ENTRY::get_qresult() const {
	return data[9];
}

std::string const DHCP_ENTRY::get_probation() const {
	return data[10];
}

std::string const DHCP_ENTRY::get_correlationid() const {
	return data[11];
}

std::string const DHCP_ENTRY::get_dhcid() const {
	return data[12];
}

std::string const DHCP_ENTRY::get_vendorclass() const {
	return data[14];
}

std::string const DHCP_ENTRY::get_userclass() const {
	return data[16];
}

std::string const DHCP_ENTRY::get_relayinfo() const {
	return data[17];
}

bool DHCP_ENTRY::set_ip(std::string input) {
	data[4] = input;
	return true;
}

bool DHCP_ENTRY::set_date(std::string input) {
	data[1] = input;
	return true;
}

bool DHCP_ENTRY::set_macaddress(std::string input) {
	data[6] = input;
	return true;
}

bool DHCP_ENTRY::set_hostname(std::string input) {
	data[5] = input;
	return true;
}

std::string const DHCP_ENTRY::print() const {
	std::string output;

	output = "ID:\t\t\t" + get_id() + "\r\n";
	output += "Date:\t\t\t" + get_date() + "\r\n";
	output += "Description:\t\t" + get_description() + "\r\n";
	output += "IP:\t\t\t" + get_ip() + "\r\n";
	output += "Hostname:\t\t" + get_hostname() + "\r\n";
	output += "Mac Address:\t\t" + get_macaddress() + "\r\n";
	output += "Username:\t\t" + get_username() + "\r\n";
	output += "Transaction ID:\t\t" + get_transactionid() + "\r\n";
	output += "QResult:\t\t" + get_qresult() + "\r\n";
	output += "Probation Time:\t\t" + get_probation() + "\r\n";
	output += "Correlation ID:\t\t" + get_correlationid() + "\r\n";
	output += "DHCID:\t\t\t" + get_dhcid() + "\r\n";
	output += "Vendor Class:\t\t" + get_vendorclass() + "\r\n";
	output += "User Class:\t\t" + get_userclass() + "\r\n";
	output += "Relay Information:\t" + get_relayinfo() + "\r\n";

	return output;
}

bool DHCP_ENTRY::clear() {
	for (unsigned int i = 0; i < 18; i++) {
		data[i].clear();
		return true;
	}
	return false;
}