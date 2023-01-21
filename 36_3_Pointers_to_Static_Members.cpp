#include <iostream>
struct Text
{
    std::string text;
    // Now Text can be implicitly converted into a const char*
    /*explicit*/ operator const char*() const { return text.data(); }
    // ^^^^^^^
    // to disable implicit conversion
};

int main(){
    Text t;
    t.text = "Hello world!";
    //Ok
    const char* copyoftext = t;
    std::cout << copyoftext;
    return 0;
}