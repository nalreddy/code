#include<iostream>
#include<vector>

enum JobOpCode
{
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    MAX,
    INVAL
};

class Job
{
    public:
        Job(size_t _arg1, size_t _arg2) : mArg1(_arg1), mArg2(_arg2), mCurIndex(0)
    {
    }
        ~Job() { }

        void addSubJob(const JobOpCode opcode)
        {
            std::cout << "addSubJob " << opcode << std::endl;
            mSubjobs.push_back(opcode);
        }

        JobOpCode getSubJob()
        {
#if 0
            if (static_cast<JobOpCode>(mCurIndex) >= MAX)
                return  INVAL;
#endif
            std::cout << " getSubjob" << mCurIndex << std::endl;
//            mCurIndex++;
            return mSubjobs[mCurIndex++];
        }

        void doSubTask(const JobOpCode opcode)
        {
            switch(opcode)
            {
                case ADD:
                    std::cout << " ADD " << mArg1 + mArg2;
                    break;
                case SUB:
                    std::cout << " SUB " << mArg1 - mArg2;
                    break;
                case MUL:
                    std::cout <<  " MUL " <<  mArg1 * mArg2;
                    break;
                case DIV:
                    std::cout <<  " DIV " <<  mArg1 / mArg2;
                    break;
                case MOD:
                    std::cout <<  " MOD " <<  mArg1 %  mArg2;
                    break;
                default:
                    std::cout << " Invlid op ";
                    break;
            }
            std::cout << std::endl;
        }


    private:
        typedef std::vector<JobOpCode> SubJobTypeQueue;
        size_t mArg1;
        size_t mArg2;
        size_t mCurIndex;
        SubJobTypeQueue mSubjobs;
};
