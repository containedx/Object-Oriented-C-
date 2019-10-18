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

    cout << x.realtextwrapper("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse ut quam libero. Curabitur eu pellentesque turpis. Vivamus rhoncus porttitor orci, eu blandit urna malesuada non. Nulla eget sagittis augue, nec commodo arcu. Ut malesuada efficitur felis id feugiat. Cras nec consectetur dui, eu consectetur nisi. Ut pharetra elementum posuere. Mauris suscipit feugiat urna. Etiam vitae tellus non odio rutrum porttitor. Praesent commodo aliquet dolor molestie viverra. Nulla sollicitudin eu velit sed sagittis. Ut gravida feugiat leo, eget rutrum elit luctus eget. Nullam vel enim consectetur, sollicitudin justo dictum, ullamcorper enim. Phasellus eget mi mauris. Praesent ac mauris ut lorem porttitor gravida id eget mauris. ", 50);


    return 0;
}
