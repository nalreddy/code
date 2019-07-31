template<Base::DigType T>
class Digest
{
    public:
        Digest(const uint8_t* data, const size_t len): (mData), mLen(len);
        getDigest()
        {
            Base::getStrategy(T).docalc(data, len);
        }

        ~Digest() {}
    private:
        const uint8_t* mData;
        const mLen;
};
