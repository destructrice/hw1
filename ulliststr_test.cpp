/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
int main(int argc, char* argv[]) {
    ULListStr* creedthoughts = new ULListStr;
    creedthoughts->push_back("Hey-o,");
    creedthoughts->push_back("everyone");
    creedthoughts->push_back("out");
    creedthoughts->push_back("there");
    creedthoughts->push_back("in");
    creedthoughts->push_back("SyberWorld.");
    creedthoughts->push_back("It's");
    creedthoughts->push_back("old");
    creedthoughts->push_back("Creed");
    creedthoughts->push_back("Bratton");
    creedthoughts->push_back("coming");

    creedthoughts->push_front("dangerous.");
    creedthoughts->push_front("and");
    creedthoughts->push_front("small");
    creedthoughts->push_front("They're");
    creedthoughts->push_front("motorcycles.");
    creedthoughts->push_front("beat");
    creedthoughts->push_front("can't");
    creedthoughts->push_front("you");
    creedthoughts->push_front("me");
    creedthoughts->push_front("To");
    creedthoughts->push_front("Car?");
    creedthoughts->display();
    creedthoughts->pop_back();
    creedthoughts->pop_back();
    creedthoughts->pop_front();
    creedthoughts->pop_back();
    creedthoughts->pop_back();
    creedthoughts->pop_back();
    creedthoughts->pop_front();
    creedthoughts->pop_back();
    creedthoughts->pop_back();
    creedthoughts->pop_back();
    std::cout << creedthoughts->front() << std::endl;
    std::cout << creedthoughts->back() << std::endl;
    std::cout << creedthoughts->get(2) << std::endl;
    std::cout << creedthoughts->get(11) << std::endl;




    creedthoughts->display();
    creedthoughts->clear();
    delete (creedthoughts);
    return 0;
}
