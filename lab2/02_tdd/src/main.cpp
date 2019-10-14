#include <iostream>
#include "Dummy.h"
#include "TextWrapper.h"

int main(int argc, char* argv[])
{
    auto dummy = Dummy{};
    std::cout << dummy.hello() << std::endl;
    
    
    auto x = TextWrapper{};
    std::cout << x.wrap("ab") << std::endl;
    return 0;
}
