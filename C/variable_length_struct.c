class Container
{
struct packing Header
{
    const uint64_t  index;
    uint32_t        xn;
    const uint8_t   type;
    const uint8_t   data_size;

    Header(uint32_t _xn, const Data& _ld) :
        index(_ld.id()), xn(_txn), type(_ld.type()), data_size(_ld.size())  {}

    Header(uint32_t _xn, Type::Id _type, uint8_t _size, uint64_t _id) :
        id(_id), xn(_txn), type(_type), data_size(_size) {}
};

Header      m_hdr;
uint8_t     m_data[0];

}
sizeof(Container) == sizeof(Container::Header));
