#include "wtSession.hpp"

std::string wtSession::getHost() {
	return "hosted.wacky-tracky.com";
}

std::string hashPassword(std::string password) {
	return password;
}

wtRequest* wtSession::reqAuthenticate(std::string username, std::string password) {
	wtRequest* req = new wtRequest(this, "authenticate");
	req->addArgumentString("username", username);
	req->addArgumentString("password", hashPassword(password));

	return req;
}
