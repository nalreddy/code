#include<iostream>
#include<set>
#include<string>
class Message
{
    public:
        Message(int _x) { x = _x;}
        bool operator< (const Message & msgObj) const
        {
            return (this->x < msgObj.x);
        }

        bool operator== (const Message & msgObj) const
        {
            std::cout << "called";
            return (this->x == msgObj.x);
        }

        friend std::ostream& operator<<(std::ostream& os, const Message& obj);
    private:
        int x;
};
std::ostream& operator<<(std::ostream& os, const Message& obj)
{
    os<<obj.x;
    return os;
}

int main()
{
    std::set<Message> test;
    Message m1(1);
    Message m2(2);

    test.insert(m1);
    test.insert(m2);

    if(test.find(m1) != test.end())
        std::cout << "found" << std::endl;
    return 0;
}
