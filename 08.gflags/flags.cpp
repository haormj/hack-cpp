#include "flags.h"

DEFINE_bool(big_menu, false, "Include 'advanced' options in the menu listing");
DEFINE_string(languages, "english,french,german",
                 "comma-separated list of languages to offer in the 'lang' menu");

void print() {
	std::cout << FLAGS_big_menu << std::endl;
	std::cout << FLAGS_languages << std::endl;
}