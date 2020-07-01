#include<iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <regex>

using namespace std;

int main()
{
    boost::property_tree::ptree pt;
    std::ostringstream ss;
    int block_s = 65350;
    int num = 256;
    pt.add( "func_name", "bdev_set_options");
    pt.add( "--bdev-io-pool-size",  block_s);
    pt.add( "--bdev-io-cache_size", num);
#if 0
    //List entries for the inode
    BOOST_FOREACH(const DirPair& entry, inoDirMap)
    {
        const std::string key = ( boost::format( "DirectoryEntries.%1%" ) %
                boost::lexical_cast<std::string>(entry.first) ).str();
        pt.add( key, entry.second);
    }

#endif
    boost::property_tree::json_parser::write_json(ss, pt);
    
    cout << ss.str() << endl;

     std::regex reg("\\\"([0-9]+\\.{0,1}[0-9]*)\\\"");
     std::string result = std::regex_replace(ss.str(), reg, "$1");

     cout << "result " << result << endl;
    return 0;
}

