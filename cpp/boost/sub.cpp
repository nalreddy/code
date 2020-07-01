#include<iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <regex>

using namespace std;

int main()
{
    boost::property_tree::ptree pt;
    std::ostringstream ss;

    pt.add("jsonrpc", "2.0");
    pt.add("id", 1);
    pt.add( "method", "bdev_set_options");
    boost::property_tree::ptree params;

    params.add( "bdev-io-pool-size", 65350 );
    params.add( "bdev-io-cache_size", 250 );
    pt.add_child("params", params);
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

