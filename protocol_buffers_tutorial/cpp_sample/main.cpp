#include "main.hpp"

int main(int argc, char* argv[])
{

    Person p;

    p.set_name("Ian");

    std::cout << p.name() << std::endl;

    return 0;
}