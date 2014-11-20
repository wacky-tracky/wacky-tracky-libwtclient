#include "wtRequest.hpp"

int connIndex = 0;

int wtRequest::getPort() {
	return 8082;
}

void wtRequest::addArgumentInt(std::string key, int value) {
	this->arguments[key] = "" + value;
}

void wtRequest::addArgumentString(std::string key, std::string value) {
	this->arguments[key] = value;
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

	std::cout << "conn " << connIndex << " req: " << url << std::endl;

	this->resp = new wtResponse(url, session, connIndex); 

	std::cout << "conn " << connIndex << " res: ???" << std::endl;

	return this->resp;
}

wtRequest::wtRequest(wtSession* session, std::string method) {
	this->session = session;
	this->method = method;
	this->resp = nullptr;
}

wtRequest::~wtRequest() {
	if(!this->resp)
		delete this->resp;
}

std::string wtRequest::buildUrl() {
	std::string url = "http://" + this->session->getHost() + ":8082/" + method;

	int argumentIndex = 0;

	for (std::map<std::string, std::string>::iterator it = this->arguments.begin(); it != this->arguments.end(); ++it) {
		if (argumentIndex == 0) {
			url += "?";
		} else {
			url += "&";
		}

		argumentIndex++;

		url += it->first + "=" + it->second;
	}

	return url;
}
