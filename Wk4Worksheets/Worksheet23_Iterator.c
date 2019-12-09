# ifndef TYPE

# define TYPE  int
# define TYPE_SIZE sizeof(int)
# define TYPE int
# define EQ(a, b) (a == b)

# endif 

#include <assert.h>
#include"dynArray.h"

//void dynArrayRemoveAt (struct dynArray * dy, int index);

struct dynArrayIterator {
struct dynArray * da;
int currentIndex;
};

void dynArrayIteratorInit (struct dynArray *da, struct dynArrayIterator *itr) {
    itr->da = da;
    itr->currentIndex = 0;
}

int dynArrayIteratorHasNext (struct dynArrayIterator *itr) {
    assert(itr != 0);
    if (itr->currentIndex < itr->da->size)
    {
        return 1;
    }
    return 0;
}

TYPE dynArrayIteratorNext (struct dynArrayIterator *itr) {
    assert(itr != 0);
    if (dynArrayIteratorHasNext(itr))
    {
        return itr->da->data[itr->currentIndex + 1];
    }
    return 0;
}

void dynArrayIteratorRemove (struct dynArrayIterator *itr) {
    assert(itr != 0);
    
    removeAtDynArr(itr->da, itr->currentIndex);
    itr->currentIndex--;
}

 int main( int argc, char* argv[]) {
     return 0;
 }