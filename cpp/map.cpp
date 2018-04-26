#include<iostream>
#include<map>
#include<iterator>
#include<string>

using namespace std;

class User
{
    std::string m_id;
    std::string m_name;
public:
    User(std::string name, std::string id)
    :m_id(id), m_name(name)
    {}
    const std::string& getId() const {
        return m_id;
    }
    const std::string& getName() const {
        return m_name;
    }
    bool operator< (const User& userObj) const
    {
        if(userObj.m_id < this->m_id)
            return true;
    }
};

int main() 
{
#if 0
    map <int, string> mp;

    mp.insert(pair <int, string> (-1, "one"));
    mp.insert(pair <int , string> (2, "two"));
    mp.insert(pair <int, string> (3, "three"));

    map <int, string> :: iterator it;


#endif

    std::map<User, int> m_UserInfoMap;
 
    m_UserInfoMap.insert(std::make_pair<User, int>(User("Mr.X", "3"), 100) );
    m_UserInfoMap.insert(std::make_pair<User, int>(User("Mr.X", "1"), 120) );
    m_UserInfoMap.insert(std::make_pair<User, int>(User("Mr.Z", "2"), 300) );
 
    std::map<User, int>::iterator it = m_UserInfoMap.begin();
    for(; it != m_UserInfoMap.end(); it++)
    {
        std::cout<<it->first.getName()<<" :: "<<it->second<<std::endl;
    }
    return 0;
}
