// char_sep_example_1.cpp
#include <iostream>
#include <boost/tokenizer.hpp>
#include <string>

int main()
{
    std::string str = "ce2c59f5-aea2-4caf-bf1e-efec05b5d7c6:2-1 Size: 65536 2-2 Size: 653434";
    typedef boost::tokenizer<boost::char_separator<char> > 
        tokenizer;
    boost::char_separator<char> sep(":");
    tokenizer tokens(str, sep);
    for (tokenizer::iterator tok_iter = tokens.begin();
            tok_iter != tokens.end(); ++tok_iter)
        std::cout << "<" << *tok_iter << "> ";
    std::cout << "\n";
    return EXIT_SUCCESS;
}
