#include "wtRequest.hpp"

int connIndex = 0;

void wtRequest::addArgumentInt(std::string name, int value) {

}

void wtRequest::addArgumentString(std::string key, std::string value) {

}

wtResponse* wtRequest::response() {
	if (this->resp != nullptr) {
		this->submit();
	}

	return this->resp;
}

wtRequest* wtRequest::submit() {
	return this;
}

wtResponse* wtRequest::go() {
	connIndex++;

	std::string url = this->buildUrl();

	std::cout << "httpconn " << connIndex << " req: " << url << std::endl;

	this->resp = new wtResponse(url, session, connIndex); 

	std::cout << "httpconn " << connIndex << " res: ???" << std::endl;

	return this->resp;
}

wtRequest::wtRequest(wtSession* session, std::string method) {
	this->session = session;
	this->method = method;
}

std::string wtRequest::buildUrl() {
	return "http://" + this->session->getHost() + ":80/" + method;
}
