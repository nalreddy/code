#include<iostream>
#include<unordered_map>
#include<climits>

using namespace std;


int main()
{
	unordered_map<char, pair<int,int>> mp;
	unordered_map<char, pair<int,int> > ::iterator mpit;

	string str;

	cout << " Enter string " << endl;
	cin >> str;
	cout << " Entered string " << str << endl;
	for (int i = 0; i < str.length(); i++) {
		pair<int, int> p;
		if (mp.find(str[i]) == mp.end()) {
			p.first = i;
			p.second = 1;
			mp[str[i]] = p;
		} else {
			p = mp[str[i]];
			p.first = i;
			p.second = ++p.second;
			mp[str[i]] = p;
		}
//		cout << " map " << p.first << " " << p.second << " " << str[i] << endl;
	}
	pair<int, int > temp;
	pair<int, int > p(INT_MAX, 1);

	for(mpit = mp.begin(); mpit != mp.end(); mpit++)
	{
		temp = mpit->second;

		if ( p.first > temp.first && temp.second == 1)
		{
			p = temp;
		}
	}
	cout << "First unique character " << str[p.first] <<" " <<  p.first << " " << p.second << endl;
	return 0;
}
