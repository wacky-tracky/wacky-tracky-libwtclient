#ifndef __WT_SESSION_H__
#define __WT_SESSION_H__

#include <iostream>

class wtRequest;

class wtSession {
	public:
		std::string getHost();

		wtRequest* reqAuthenticate(std::string username, std::string password);

	private:
		std::map<std::string, std::string> cookieJar;
};

#include "wtRequest.hpp"

#endif
