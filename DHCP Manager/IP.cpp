#include "stdafx.h"
#include "IP.h"

bool IPADDRESS::operator++(int) {
	if (fourth == 255) {
		fourth = 0;
		if (third == 255) {
			third = 0;
			if (second == 255) {
				second = 0;
				if (first == 255) {
					first = 0;
					return false;
				}
				else {
					first++;
					return true;
				}
			}
			else {
				second++;
				return true;
			}
		}
		else {
			third++;
			return true;
		}
	}
	else {
		fourth++;
		return true;
	}
}

bool IPADDRESS::operator<(const IPADDRESS & right) const{
	if (this->first == right.first) {
		if (this->second == right.second) {
			if (this->third == right.third) {
				return this->fourth < right.fourth;
			}
			else {
				return this->third < right.third;
			}
		}
		else {
			return this->second < right.second;
		}
	}
	else {
		return this->first < right.first;
	}
}

bool IPADDRESS::operator<=(const IPADDRESS & right) const {
	if (this->first == right.first) {
		if (this->second == right.second) {
			if (this->third == right.third) {
				return this->fourth <= right.fourth;
			}
			else {
				return this->third <= right.third;
			}
		}
		else {
			return this->second <= right.second;
		}
	}
	else {
		return this->first <= right.first;
	}
}

bool IPADDRESS::operator>(const IPADDRESS & right) const {
	if (this->first == right.first) {
		if (this->second == right.second) {
			if (this->third == right.third) {
				return this->fourth > right.fourth;
			}
			else {
				return this->third > right.third;
			}
		}
		else {
			return this->second > right.second;
		}
	}
	else {
		return this->first > right.first;
	}
}

bool IPADDRESS::operator==(const IPADDRESS & right) const {
	if ((this->first == right.first) && (this->second == right.second) && (this->third == right.third) && (this->first == right.first)) {
		return true;
	}
	else {
		return false;
	}
}

bool IPADDRESS::operator!=(const IPADDRESS & right) const {
	if ((this->first == right.first) && (this->second == right.second) && (this->third == right.third) && (this->first == right.first)) {
		return false;
	}
	else {
		return true;
	}
}

IPADDRESS::IPADDRESS(std::string input) {
	std::size_t found = input.find(".");
	std::size_t next;

	first = atoi((input.substr(0, found)).c_str());
	next = input.find(".", ++found);
	second = atoi(input.substr(found, next).c_str());
	found = next;
	next = input.find(".", ++found);
	third = atoi(input.substr(found, next).c_str());
	found = next;
	next = input.find(".", ++found);
	fourth = atoi(input.substr(found, next).c_str());
}

std::string IPADDRESS::print() const {
	std::string output = "";
	output.append(std::to_string(first));
	output += '.';
	output.append(std::to_string(second));
	output += '.';
	output.append(std::to_string(third));
	output += '.';
	output.append(std::to_string(fourth));
	return output;
}