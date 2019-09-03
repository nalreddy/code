class Container
{

    class ConstIterator
    {
        public:
            ConstIterator& operator ++()
            {
                m_array = reinterpret_cast<const Array*>(reinterpret_cast<uintptr_t>(m_array) + m_array->data_size());
                return *this;
            }

            const Array& operator *()
            {
                return *m_array;
            }

            const Array* operator ->()
            {
                return m_array;
            }

            bool operator ==(const ConstIterator& it) const
            {
                return m_array == it.m_array;
            }

            bool operator !=(const ConstIterator& it) const
            {
                return !(operator ==(it));
            }

        private:
            const Array*  m_array;

            ConstIterator(const void* addr) : m_array(reinterpret_cast<const Array*>(addr)) {}

            friend struct CacheBuffer;
    };

    ConstIterator begin() const
    {
        return ConstIterator(m_data);
    }

    ConstIterator end() const
    {
        return ConstIterator(m_data + size());
    }

    private:
        m_data;
}
