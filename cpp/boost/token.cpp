#if 0// char_sep_example_1.cpp
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
#endif
#include <iostream>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;

int main()
{
    std::string input = "192.1.23.1:3041 192.1.23.2:3042 192.1.23.3:3043";
    std::string copy(input);
    std::vector<std::string> lines;
    boost::split(lines, copy, boost::is_any_of(" "));
    BOOST_FOREACH(std::string& line, lines)
    {
        cout << " line " << line << endl;
        std::vector<std::string> tokens;
        boost::split(tokens, line, boost::is_any_of(":"));
        cout << "Tokens " << tokens[0] << " "  << tokens[1] << endl;
    }

    //boost::lexical_cast<signed int>(tokens[2])
    return 0;
}
