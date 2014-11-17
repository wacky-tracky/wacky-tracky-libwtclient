#include "wtResponse.hpp"

wtResponse::wtResponse(std::string url, wtSession* session, int connIndex) {
	this->url = url;
	this->session = session;
	this->connIndex = connIndex;
}
