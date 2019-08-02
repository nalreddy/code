#include<iostream>
#include<set>

using namespace std;

int main()
{
    set<int> st;

    st.insert(1);
    st.insert(2);
    st.insert(1);
    st.insert(4);
    st.insert(1);

    if(st.find(1) != st.end()) {
            cout << "found element "<< endl;
    }
    set<int> :: iterator it;
    for ( it = st.begin(); it != st.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}
