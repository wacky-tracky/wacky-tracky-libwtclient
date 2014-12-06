#ifndef __WT_RESPONSE_H__
#define __WT_RESPONSE_H__

#include <iostream>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>

#include "wtSession.hpp"

struct responseData_t {
	char *memory;
	size_t size;
};

class wtResponse {
	public:
		wtResponse(std::string url, wtSession* session, int connIndex);
		std::string getContent();
		Json::Value getContentAsJson();
		std::string getContentAsPrettyJson();

		void saveCookiesInSession();
	private:
		std::string connName();
		void perform();
		std::string url;
		wtSession* session;
		int connIndex; 

		CURL* curl;
		CURLcode res;

		size_t writeCallback(void *contents, size_t realsize);
		static size_t curlwriter(void* contents, size_t size, size_t nmemb, void* wtResponsePointer);

		responseData_t responseData;
};
#endif
