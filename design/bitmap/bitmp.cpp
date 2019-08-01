#include<iostream>
#include <cstddef>


using namespace std;

class BitMap
{
    public:
        BitMap(size_t _size) : mRange(_size)
        {
            // size < 8 problem
            mSize = (mRange / 8);
            map = new unsigned char[mSize];
            for (int i = 0; i < mSize; i++)
            {
                map[i] = 0x00;
            }
        }

        ~BitMap()
        {
            delete []map;
        }

        void printMap()
        {
            for (int i = 0; i < mSize; i++)
            {
                cout <<"'"<<std::hex<<int(map[i])<<"'";
            }
            std::cout << "\n";
        }

        void setBit(size_t idx)
        {
            //test range
            map[idx/8] |= ((0x01 << (idx % 8)));
        }

        void  unsetBit(size_t idx)
        {
           map[idx/8] &= ~(0x01 << (idx%8));
        }

        char testBit(size_t index)
        {
            return (map[index/8] & (0x01 << (index%8))) ? 0x01 : 0x00;
        }
    private:
        size_t mRange;
        size_t mSize;
        unsigned char* map;
};

int main()
{
    BitMap mp(16);

    mp.setBit(1);
    mp.setBit(0);
    mp.setBit(8);
    mp.printMap();

    mp.unsetBit(8);
    mp.printMap();
    return 0;
}
