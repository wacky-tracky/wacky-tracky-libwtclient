#ifndef __WT_SESSION_H__
#define __WT_SESSION_H__

#include <iostream>
#include <map>

class wtRequest;

class wtSession {
	public:
		std::string getHost();

		wtRequest* reqAuthenticate(std::string username, std::string password);

		void registerCookie(std::string key, std::string value);

	private:
		std::map<std::string, std::string> cookieJar;
};

std::string hashPassword(std::string);

#include "wtRequest.hpp"

#endif
