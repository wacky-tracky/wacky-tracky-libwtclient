#include <wtCommon.hpp>

int main() {
	wtSession session();

	wtRequest request = session.reqAuthenticate("unittest", "unittest");
	request->peform();
	request->saveCookiesInSession();

	ListOfLists lol = session.reqListLists();
}
