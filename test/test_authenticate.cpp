#include <wtSession.hpp>
#include <wtRequest.hpp>
#include <wtResponse.hpp>

int main() {
	wtSession* session = new wtSession();
	wtRequest* req = session->reqAuthenticate("unittest", "unittest");
	wtResponse* res = req->go();

	std::cout << "Pretty Json:" << std::endl;
	std::cout << res->getContentAsPrettyJson() << std::endl;
}
