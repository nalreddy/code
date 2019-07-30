#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

void search(const string& str, const string& seq)
{
    unordered_map<char, uint64_t> seq_map;

    for (string::const_iterator itr = seq.begin(); itr != seq.end(); itr++)
    {
        seq_map[*itr] += 1;
        std::cout << *itr;
    }

    uint64_t start  = 0;
    uint64_t curlen = 0;
    uint64_t minlen = 999999;
    uint64_t str_len = str.length();
    uint64_t seq_len = seq.length();
    unordered_map<char, uint64_t> cur_map;

    std::cout << " str_len " << str_len << std::endl;
    for (uint64_t i = 0; (start < str_len && ( str_len - start) >= seq_len ) && ( i < str_len) /* limit i <  str.length() */;)
    {
         std::cout << "debug curlen " << curlen << " seq_len " << seq_len << " minlen " << minlen << "start " << start << " i = " << i << std::endl;
        char idx = str[i];
        cur_map[idx] += 1;
        if (idx == seq[curlen])
        {
            if(seq_map[idx] == cur_map[idx])
                curlen++;
            std::cout << "char "  << idx;

            if (curlen == seq_len && curlen <= minlen)
            {
                minlen = curlen;
                std::cout << "curlen " << curlen << " seq_len " << seq_len << " minlen " << minlen << "start " << start << " i = " << i << std::endl;
                curlen = 0;
                cur_map.clear();
                start++;
                i = start;
            }

        }
        i++;
    }

    std::cout << " Minlen " <<minlen;
//    std::cout << "  Minstring" << minstring;

}

int main()
{
    string str = "aa";
    string seq = "aa";

    search(str, seq);

    return 0;
}
