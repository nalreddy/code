
#pragma once
#ifndef _ALLOCATOR_H
#define _ALLOCATOR_H 1

#include <sys/types.h>
#include <stdint.h>
#include <boost/utility.hpp>

class Allocator : public boost::noncopyable
{
 public:
  enum AllocType
  {
      ALLOC_HUGE,
      ALLOC_MM,
      ALLOC_ALIGNED
  };
  Allocator();
  virtual ~Allocator();
  bool allocateBytes(size_t size, AllocType alloctype=ALLOC_HUGE, size_t alignment=MIN_ALIGNED_SIZE);           
  void free();
  inline void* get() const { return mAddress; }

 private:
  bool shmalloc(size_t size, bool isHuge);

 protected:
  size_t mAllocatedSize;
  size_t mSize;
  void* mAddress;
  int mId;
  int mIdx;
  size_t mAlignment;
};

class ArrayAllocation : public Allocator
{
 public:
   T element_type;

  ArrayAllocation() : Allocator()  {}
  ArrayAllocation(uint64_t count, AllocType alloctype=ALLOC_HUGE, size_t alignment=MIN_ALIGNED_SIZE) : Allocator()
  {
    allocateArray(count, alloctype, alignment);
  }

  bool allocateArray(uint64_t count, AllocType alloctype=ALLOC_HUGE, size_t alignment=MIN_ALIGNED_SIZE)
  {
    bool rtn = Allocator::allocateBytes(count*sizeof(T), alloctype, alignment);
    if (rtn)
    {
      T * p = reinterpret_cast<T*>(mAddress);
      for(uint64_t i=0; i<count; i++)
      {
        new (p) T();
        p++;
      }
    }
    return rtn;
  }

  T & operator[](uint64_t i) const 
  {
    return (reinterpret_cast<T*>(mAddress))[i];
  }

  T* get() const
  {
    return reinterpret_cast<T*>(mAddress);
  }

  size_t size() const
  {
    return mSize / sizeof(T);
  }
};

#endif 
