#include<iostream>

using namespace std;

typedef enum
{
    Positive,
    Negative
}TestType;
    

typedef enum
{
    Single,
    Batch
}InputType;
    

template<InputType IInputType, TestType ITestType>
    struct DataDescriptorBase
{
    static const InputType inputype = IInputType;
    static const TestType itestType = ITestType;
    
    static const std::string testtype()
    { 
        switch (ITestType)
        {
            case Positive:
                return "positive";
            case Negative:
                return "negative";
        }
    }
};

template<InputType IInputType, TestType ITestType>
    struct DataDescriptor :
        public DataDescriptorBase<IInputType, ITestType>
{
};

#define DEFINE_DATA_DESCRIPTOR( inputtype, testtype )                                       \
                                                                                            \
template<> struct DataDescriptor<inputtype, testtype> :                                     \
public DataDescriptorBase<inputtype, testtype>                                              \
{                                                                                           \
};                                                                                          \
                                                                                            \
typedef DataDescriptor<inputtype, testtype> Descriptor##inputtype##testtype;

DEFINE_DATA_DESCRIPTOR( Single, Positive );
DEFINE_DATA_DESCRIPTOR( Batch, Positive );

#if 0
DescriptorOpenSslDefaultDigestTypeSinglePositive,
DescriptorIsalMbDefaultDigestTypeSinglePositive,
DescriptorInvalidDefaultDigestTypeSingleNegative
#endif

int main()
{
    DescriptorSinglePositive ex;

    cout << ex.testtype();
//     << Descriptor:testtype():

  //  TestType testType = Descriptor::testType;

    return 0;
}
