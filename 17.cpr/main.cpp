#include <iostream>
#include <cpr/cpr.h>

int main() {
	cpr::Response rsp = cpr::Get(cpr::Url{"https://baidu.com"});
	
	std::cout << rsp.status_code << std::endl;
	std::cout << rsp.text << std::endl;

    return 0;
}