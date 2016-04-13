#pragma once

#include "stdafx.h"

struct IPADDRESS {
	int first;			// 192
	int second;			// 168
	int third;			// 10
	int fourth;			// 41

	bool operator++(int);
	bool operator<(const IPADDRESS &) const;
	bool operator<=(const IPADDRESS &) const;
	bool operator>(const IPADDRESS &) const;
	bool operator>=(const IPADDRESS &) const;
	bool operator==(const IPADDRESS &) const;
	bool operator!=(const IPADDRESS &) const;

	IPADDRESS(std::string);

	std::string print() const;

};

