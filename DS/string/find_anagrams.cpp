#include<iostream>
#include<iterator>
#include<vector>
#include<string>
#include<unordered_map>

typedef std::vector<std::string> Vector;

void anagram(const Vector _v)
{
    const std::string str1 = _v[0];
    const std::string str2 = _v[1];

    std::unordered_map<char, uint32_t> mp;

    for (std::string::const_iterator itr = str1.begin(); itr != str1.end(); itr++)
    {
        mp[*itr] += 1;
    }

    for (std::string::const_iterator itr = str2.begin(); itr != str2.end(); itr++)
    {
        if (mp.find(*itr) == mp.end())
        {
            std::cout << " mismatch  no anagrams" << std::endl;
            break;
        }
        mp[*itr] += -1;
    }

    for(std::unordered_map<char, uint32_t>::iterator itr = mp.begin(); itr != mp.end(); itr++)
    {
        if (itr->second != 0)
        {
            std::cout << "not anagram " << itr->first << " " << itr->second<<  std::endl;
            return;
        }

    }
    std::cout << " Anagrams " << str1 << " " << str2 << std::endl;
}

int main()
{
    Vector vstr;

    vstr.push_back("aabbcc");
    vstr.push_back("abc");

    for(Vector::iterator itr = vstr.begin(); itr != vstr.end(); itr++)
        std::cout << *itr << std::endl;

    anagram(vstr);

    return 0;
}
