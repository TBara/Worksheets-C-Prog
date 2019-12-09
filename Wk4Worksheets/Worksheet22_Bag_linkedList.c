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


struct dLink
{
    TYPE value;
    struct dLink *next;
    struct dLink *prev;
};

struct linkedList
{
    struct dLink *frontSentinel;
    struct dLink *backSentinel;
    int size;
};


/* the following functions were written in earlier lessons */
void linkedListInit(struct linkedList *q);

void linkedListFree(struct linkedList *lst);

void _addLink(struct linkedList *lst, struct dLink *lnk, TYPE e);

void _removeLink(struct linkedList *lst, struct dLink *lnk);

void linkedListAdd(struct linkedList *lst, TYPE e)
{
    _addLink(lst, lst->frontSentinel->next, e);
}

/* you must write the following */
int linkedListContains(struct linkedList *lst, TYPE e)
{
    if (lst->frontSentinel == lst->backSentinel)
    {
        return 0;
    }
    
    struct dLink *link = lst->frontSentinel->next;
    while (link->next)
    {
        if (link->value == e)
        {
            return 1;       
        }
        link = link->next;
    }
    return 0;
}

void linkedListRemove(struct linkedList *lst, TYPE e)
{ 
    struct dLink *link = lst->frontSentinel->next;
    if (lst->frontSentinel != lst->backSentinel)
    {
        while (link->next)
        {
            if (link->value == e){
                _removeLink(lst, link);
            }
            link = link->next;
        }
    }
}

int main() {
    return 0;
}

