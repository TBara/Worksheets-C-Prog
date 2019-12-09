#ifndef TYPE
#define TYPE int
#endif

#ifndef LT
#define LT(A, B) ((A) < (B))
#endif

#ifndef EQ
#define EQ(A, B) ((A) == (B))
#endif

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

struct dyArray{
   TYPE *data;
   int capacity;
   int size;
};

int compare(TYPE left, TYPE right){
	int nodeLeft, nodeRight;

	nodeLeft = (int) left;
	nodeRight = (int) right;

	if(nodeLeft < nodeRight)
		return -1;
	else if(nodeLeft > nodeRight)
		return 1;
	else
		return 0;

}

void heapRemoveFirst(struct dyArray *heap)
{
   int last = dyArraySize(heap) - 1;
   assert(dyArraySize(heap) > 0); /* make sure we have at least one element */
                                  /* Copy the last element to the first  position */
   dyArrayPut(heap, 0, dyArrayrGet(heap, last));
   dyArrayRemoveAt(heap, last); /* Remove last element.*/
   adjustHeap(heap, last, 0);   /* Rebuild heap */
}


void swap(struct dyArray *v, int i, int j)
{ /* swap elements i j */
   TYPE temp = dyArrayGet(v, i);
   dyArrayPut(v, i, dyArrayGet(v, j));
   dyArrayPut(v, j, temp);
}


int indexSmallest(struct dyArray *v, int i, int j)
{
   /* return index of smallest element */
   if (LT(dyArrayGet(v, i), dyArrayGet(v, j)))
      return i;
   return j;
}


TYPE heapGetFirst(struct dyArray *heap)
{
   assert(dyArraySize(heap) > 0);
   return dyArrayGet(heap, 0);
}


void heapRemoveFirst(struct dyArray *heap)
{
   int last = dyArraySize(heap) - 1;
   assert(dyArraySize(heap) > 0); /* make sure we have at least one element */
                                  /* Copy the last element to the first  position */
   dyArrayPut(heap, 0, dyArrayrGet(heap, last));
   dyArrayRemoveAt(heap, last); /* Remove last element.*/
   adjustHeap(heap, last, 0);   /* Rebuild heap */
}


void adjustHeap(struct dyArray *heap, int max, int pos)
{
   int leftChild = 2*pos + 1;
   int rightChild = 2*pos +2;
   int smallestChild;
    
   if (rightChild < max)
   {
      smallestChild = indexSmallest(heap, leftChild, rightChild);
      if (heap->data[smallestChild] < heap->data[pos])
      {
         swap(heap, smallestChild, pos);
         adjustHeap(heap, max, smallestChild);
      }
      
   } else if (leftChild < max)
   {
      if (heap->data[leftChild] < heap->data[pos]  )
      {
         swap(heap, leftChild, pos);
         adjustHeap(heap, max, leftChild);
      }
      
   }
   
}

void heapAdd(struct dyArray *heap, TYPE newValue)
{
   dyArrayAdd(heap, newValue); /* adds to end – now need to adjust position */
   int pos = heap->size -1;
   int parent;

   while (pos !=0 )
   {
      parent = pos/2;
      if(heap->data[parent] > heap->data[pos]){
         swap(heap, parent, pos);
         pos = parent;
      } else
      {
         return;
      }
      
   }
}
