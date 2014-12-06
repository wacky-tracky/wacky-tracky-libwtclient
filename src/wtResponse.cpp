#include "wtResponse.hpp"
#include <cstring>
#include <sstream>

void wtResponse::saveCookiesInSession() {
	this->session->registerCookie("sessionId", "0");
}

std::string wtResponse::connName() {
	std::stringstream ss;
	ss << "conn " << this->connIndex << " ";

	return ss.str();
}

std::string wtResponse::getContent() {
	return std::string(this->responseData.memory);
}

Json::Value wtResponse::getContentAsJson() {
	Json::Value root;
	Json::Reader reader;

	bool parsingSuccessful = reader.parse(this->getContent(), root, false);

	if (!parsingSuccessful) {
		std::cout << "parse fail" << std::endl;
	}


	return root;
}

std::string wtResponse::getContentAsPrettyJson() {
	Json::Value root = getContentAsJson();

	return Json::StyledWriter().write(root);
}

void wtResponse::perform() {
	this->res = curl_easy_perform(curl);

	std::cout << this->connName() << "curl result: " << this->res << ", length " << this->responseData.size << std::endl;
	std::cout << this->connName() << "res content \n-----" << std::endl << this->responseData.memory << std::endl << "-----" << std::endl;

	curl_easy_cleanup(this->curl);
}

size_t wtResponse::curlwriter(void *contents, size_t size, size_t nmemb, void* wtResponsePointer) {
	wtResponse* wtRes = (wtResponse*)wtResponsePointer;

	return wtRes->writeCallback(contents, size * nmemb);
}

wtResponse::wtResponse(std::string url, wtSession* session, int connIndex) {
	this->url = url;
	this->session = session;
	this->connIndex = connIndex;

	this->curl = curl_easy_init();

	this->responseData.memory = (char*) malloc(1);
	this->responseData.size = 0;

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &curlwriter);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);
	
		this->perform();
	}
}

size_t wtResponse::writeCallback(void *contents, size_t realsize) {
	this->responseData.memory = (char*) realloc(this->responseData.memory, this->responseData.size + realsize + 1);

	if (this->responseData.memory == NULL) {
		return 0;
	}

	memcpy(&(this->responseData.memory[this->responseData.size]), contents, realsize);
	this->responseData.size += realsize;
	this->responseData.memory[this->responseData.size] = 0;

	return realsize;
}
