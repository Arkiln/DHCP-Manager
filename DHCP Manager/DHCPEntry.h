#pragma once

#include "stdafx.h"

class DHCP_ENTRY {
public:
	DHCP_ENTRY(std::string);
	DHCP_ENTRY();

	std::string const get_id() const;				// 0
	std::string const get_date() const;				// 1
	std::string const get_time() const;				// 2
	std::string const get_description() const;		// 3
	std::string const get_ip() const;				// 4
	std::string const get_hostname() const;			// 5
	std::string const get_macaddress() const;		// 6
	std::string const get_username() const;			// 7
	std::string const get_transactionid() const;	// 8
	std::string const get_qresult() const;			// 9
	std::string const get_probation() const;		// 10
	std::string const get_correlationid() const;	// 11
	std::string const get_dhcid() const;			// 12
	std::string const get_vendorclass() const;		// 14
	std::string const get_userclass() const;		// 16
	std::string const get_relayinfo() const;		// 17

	bool set_ip(std::string);
	bool set_date(std::string);
	bool set_macaddress(std::string);
	bool set_hostname(std::string);

	std::string const print() const;
	
	bool clear();

private:
	std::string data[18];
};