#include <iostream>

#include "wtResponse.hpp"

class wtRequest {
	public:
		wtRequest(wtSession* session, std::string method);
		void addArgumentInt(std::string name, int value);
		wtResponse* response();
		wtRequest* submit();
		wtResponse* go();
	private:
		wtSession* session;
		wtResponse* resp;

		std::string buildUrl();
		std::string method;
};

int connIndex = 0;
