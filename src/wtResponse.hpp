#ifndef __WT_RESPONSE_H__
#define __WT_RESPONSE_H__

#include "wtSession.hpp"

#include <iostream>

class wtResponse {
	public:
		wtResponse(std::string url, wtSession* session, int connIndex);

	private:
		std::string url;
		wtSession* session;
		int connIndex; 
};
#endif
