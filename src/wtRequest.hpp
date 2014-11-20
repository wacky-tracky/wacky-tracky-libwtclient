#ifndef __WT_REQUEST_H__
#define __WT_REQUEST_H__

#include <iostream>
#include <map>

class wtResponse;
class wtSession;

class wtRequest {
	public:
		wtRequest(wtSession* session, std::string method);
		~wtRequest();
		void addArgumentInt(std::string name, int value);
		void addArgumentString(std::string key, std::string value);
		wtResponse* response();
		wtRequest* submit();
		wtResponse* go();
		int getPort();
	private:
		wtSession* session;
		wtResponse* resp;

		std::string buildUrl();
		std::string method;

		std::map<std::string, std::string> arguments;
};

#include "wtResponse.hpp"

#endif
