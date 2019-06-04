namespace pool
{

enum optype 
{
    READ,
    WRITE,
    EXECUTE,
    FETCH,
    MAXOPCOUNT = 4 
};

class task_node
{
    public:

    private:
        uint8_t optype;
        void* data;
};

}
