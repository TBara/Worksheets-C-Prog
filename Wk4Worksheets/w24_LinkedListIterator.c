# ifndef TYPE

# define TYPE  int
# define TYPE_SIZE sizeof(int)
# define TYPE int
# define EQ(a, b) (a == b)

# endif 

#include <assert.h>
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>

struct dlink
{
    TYPE value;
    struct dlink *next;
    struct dlink *prev;
};

struct linkedList
{
    int size;
    struct dlink *frontSentinel;
    struct dlink *backSentinel;
};
 
struct linkedListIterator
{
    struct linkedList *lst;
    struct dlink *currentLink;
};

void _removeLink(struct linkedList *lst, struct dlink *lnk);

void linkedListIteratorInit(struct linkedList *lst, struct linkedListIterator *itr)
{
    itr->lst = lst;
    itr->currentLink = itr->lst->frontSentinel;
}

int linkedListIteratorHasNext(struct linkedListIterator *itr)
{
    assert(itr != 0);
    if (itr->currentLink->next != itr->lst->backSentinel)
    {
        itr->currentLink = itr->currentLink->next;
        return 1;
    }
    return 0;
}

TYPE linkedListIteratorNext(struct linkedListIterator *itr)
{
    return itr->currentLink->value;
}

/* think about the next one carefully. Draw a picture. What should itr->currentLink be pointing to after the remove operation? */
void linkedListIteratorRemove(struct linkedListIterator *itr)
{
    assert(itr != 0);

    struct dlink* lnk = itr->currentLink;
    itr->currentLink = itr->currentLink->prev; //Make sure surrent points to an element
    _removeLink(itr->lst, lnk);
}

int linkedListIsEmpty(struct linkedList *q)
{
    return q->size == 0;
}

void _removeLink(struct linkedList *q, struct dlink *lnk)
{
    if (!linkedListIsEmpty(q))
    {
        lnk->prev->next = lnk->next;
        lnk->next->prev = lnk->prev;

        q->size--;
        free(lnk);
    }
    
}


int main (int argc, const char * argv[]) {

    struct linkedList *myStack;

	myStack =  createLinkedList(3);

	addBackList(myStack, 0);
	addBackList(myStack, 1);
	addBackList(myStack, 2);
	addBackList(myStack, 3);

	struct linkedListIter *myIter;
	myIter = createlinkedListIter(myStack);

	while(linkedListIteratorHasNext(myIter))
		{
			TYPE val = nextlinkedListIter(myIter);
			if(val != 2)
				printf("The next value in the stack is: %d\n", val);
			else {
				printf("The next value in the stack is: %d\n", val);
				removelinkedListIter(myIter);
			}
		}

	printf("After removing 2 \n");
	initlinkedListIter(myStack, myIter);

	while(linkedListIteratorHasNext(myIter))
		printf("The next value in the stack is: %d\n", nextlinkedListIter(myIter));


	return(0);

}
