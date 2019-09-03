#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>


enum Param
{
  SHMGET_H_FLAGS = SHM_HUGETLB | IPC_CREAT | SHM_R | SHM_W,
  SHMGET_NOR_FLAGS = IPC_CREAT | SHM_R | SHM_W,
};

#define PAGE_SIZE 2*1024*1024


Allocator::Allocator()
    : mAllocatedSize(0), mSize(0), mAddress(NULL), mId(-1), mIdx(-1),
      mAlignment(0)
{
    std::ifstream in("/proc/sys/vm/nr_hugepages");
    if (in.is_open())
    {
        if (std::getline(in, line)) {
            long nr = strtol(line.c_str(), NULL, 10);
            }
    }
}


Allocator::~Allocator()
{
}

bool
Allocator::shmalloc(size_t size, bool isHuge)
{
  int flags(isHuge ? SHMGET_FLAGS : SHMGET_NOR_FLAGS);
  mIdx = 0;
  mId = ::shmget(IPC_PRIVATE, size, flags);
  if (mId<0) {
    mId = -errno;
    mIdx = 1;
    return false;
  }

  void* shmaddr = ::shmat(mId, NULL, 0);
  if (shmaddr==(void*) -1)
  {
    ::shmctl(mId, IPC_RMID, NULL);
    mId = -errno;
    mIdx = 2;
    return false;
  }

  mAddress = shmaddr;
  if(::shmctl(mId, IPC_RMID, NULL) != 0)
  {
    mIdx = 3;
    free();
    return false;
  }

  return true;
}


bool
Allocator::allocateBytes(size_t size, AllocType alloctype/*=ALLOC_HUGE*/, size_t alignment/*=MIN_ALIGNED_SIZE*/)
{
  mAllocatedSize = size;

  size_t pagesize = static_cast<size_t>(PAGE_SIZE);
  mSize = (size + pagesize - 1) / pagesize * pagesize; // round up

  free();
  bool result = false;
  mAddress = NULL;
  mIdx = -1;
  mId = -1;

      if (alloctype == ALLOC_HUGE)
      {
          if ((result = shmalloc(mSize, true)) == false)
          {
                 }
          else
          {
              mAlignment = PAGE_SIZE;
          }
      }

      if (!result && (alloctype != ALLOC_ALIGNED))
      {
         int ps = sysconf(_SC_PAGESIZE);
          pagesize = static_cast<size_t>(ps);

          size_t adjSz = checkAlignment(size, alignment, pagesize);

          mSize = (adjSz + pagesize - 1) / pagesize * pagesize;

          if ((result = shmalloc(mSize, false)) == false)
          {
          }
          else
          {
              mAlignment = pagesize;
          }
      }

      if (!result)
      {
        if (alignment < sizeof(void*))
        {
            alignment = sizeof(void*);
        }
        if (posix_memalign(&mAddress, alignment, size)==0)
        {
          mAlignment = alignment;
        }
      }

  } 

  return result;
}

void
Allocator::free()
{
  if (mAddress==NULL)
  {
    // Duplicate free
    return;
  }

  if (!mIsMapped)
  {
    ::free(mAddress);
      mAddress = NULL;
      return;
  }

  // undo shmat
  if (mAddress!=NULL)
  {
    if (::shmdt((const void*) mAddress) == 0)
    {
      mAddress = NULL;
    }
  }

  // undo shget
  if (mId>=0)
  {
    if (::shmctl(mId, IPC_RMID, NULL) == 0)
    {
      mId = -1;
    }
  }
}

size_t
Allocator::checkAlignment(size_t origSize, size_t alignment, size_t pagesize)
{
    size_t size = origSize;

    if (alignment < pagesize) {
        if (alignment != 0 && ((pagesize % alignment) != 0)) {
            size += pagesize;
        }
    } else if (alignment > pagesize) {
        if (alignment % pagesize == 0) {
            size += (alignment/pagesize - 1) * pagesize;
        } else {
            size += (alignment/pagesize) * pagesize;
        }
    }

    return size;
}

