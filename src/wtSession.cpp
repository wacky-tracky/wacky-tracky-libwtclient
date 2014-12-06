#include "wtSession.hpp"

std::string wtSession::getHost() {
	return "hosted.wacky-tracky.com";
}

std::string hashPassword(std::string password) {
	return "94e060874450b5ea724bb6ce5ca7be4f6a73416b"; // sha1 for "unittest"
}

wtRequest* wtSession::reqAuthenticate(std::string username, std::string password) {
	wtRequest* req = new wtRequest(this, "authenticate");
	req->addArgumentString("username", username);
	req->addArgumentString("password", hashPassword(password));

	return req;
}

void wtSession::registerCookie(std::string value) {

}
