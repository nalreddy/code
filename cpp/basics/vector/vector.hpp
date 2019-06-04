#include"container.hpp"

namespace  ds
{
class Vector: public ds::Container
{
    public:
        Vector(int s);
        Vector(const Vector& s);
        Vector(Vector&& s);
        Vector& operator=(const Vector& s);
        ~Vector();
        double& operator [](int i);
        int size();
    private:
        double* elem;
        int sz;
};
}
