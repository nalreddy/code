#include<iostream>
#include<vector>

namespace sched
{
    enum SubJobOpCode
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
            Job(size_t _arg1, size_t _arg2) : mArg1(_arg1), mArg2(_arg2), mCurIndex(0);
            {
            }
            ~Job() { }
            void addSubJob(const sched::SubJobOpCode opcode)
            {
                mSubjobs.push_back(opcode);
            }

            sched::SubJobOpCode getSubJob()
            {
                mCurIndex++;
                 return mSubjobs[mCurIndex];
            }

            void doSubTask(const SubJobOpCode opcode)
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
            typedef std::vector<SubJobOpCode, MAX> SubJobTypeQueue;
            size_t mArg1;
            size_t mArg2;
            size_t mCurIndex;
            SubJobTypeQueue mSubjobs;
    };
}
