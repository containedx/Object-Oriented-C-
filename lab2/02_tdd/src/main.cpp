#include <iostream>
#include "Dummy.h"
#include "TextWrapper.h"


int main(int argc, char* argv[])
{
    auto dummy = Dummy{};
    cout << dummy.hello() << endl;
    
    
    auto x = TextWrapper{};
    cout << x.wrap("ab") << endl;
    cout << x.wrapInColumns("a b c defghs", 2);



    return 0;
}
