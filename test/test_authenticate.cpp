#include <wtSession.hpp>
#include <wtRequest.hpp>

int main() {
	wtSession* session = new wtSession();
	wtRequest* req = session->reqAuthenticate("unittest", "unittest");
	req->go();
}
