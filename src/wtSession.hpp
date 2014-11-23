#ifndef __WT_SESSION_H__
#define __WT_SESSION_H__

#include <iostream>

class wtRequest;

class wtSession {
	public:
		std::string getHost();

		wtRequest* reqAuthenticate(std::string username, std::string password);
};

std::string hashPassword(std::string);

#include "wtRequest.hpp"

#endif
