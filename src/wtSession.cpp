#include "wtSession.hpp"
#include <cstring>
#include <openssl/sha.h>
#include <sstream>

std::string wtSession::getHost() {
	return "hosted.wacky-tracky.com";
}

std::string hashPassword(std::string password) {
	const char* ibuf = password.c_str(); 
	unsigned char hash[20];
	
	SHA1((const unsigned char*)ibuf, strlen(ibuf), hash);

	std::stringstream ss; 

	for (int i = 0; i < 20; i++) {
		ss << std::hex << (int) hash[i];
	}
	
	return ss.str();
}

wtRequest* wtSession::reqAuthenticate(std::string username, std::string password) {
	wtRequest* req = new wtRequest(this, "authenticate");
	req->addArgumentString("username", username);
	req->addArgumentString("password", hashPassword(password));

	return req;
}

void wtSession::registerCookie(std::string value) {

}
