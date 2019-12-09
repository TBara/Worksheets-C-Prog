# ifndef TYPE

# define TYPE  int
# define TYPE_SIZE sizeof(int)
# define TYPE int
# define EQ(a, b) (a == b)

# endif 

void linkedListInit(struct linkedList *q);
int linkedListIsEmpty(struct linkedList *q);
void _removeLink(struct linkedList *q, struct dlink *lnk);
void linkedListRemoveFront(struct linkedList *q);
void linkedListFree(struct linkedList *q);
void _addLink(struct linkedList *q, struct dlink *lnk, TYPE e);
