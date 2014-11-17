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
