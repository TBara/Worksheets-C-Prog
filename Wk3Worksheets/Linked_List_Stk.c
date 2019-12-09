#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include "Linked_List_Stk.h"

struct link
{
    TYPE value;
    struct link *next;
};

struct linkedListStack
{
    struct link *firstLink;
};

void linkedListStackInit(struct linkedListStack *s)
{
    s->firstLink = 0;
}

int linkedListStackIsEmpty(struct linkedListStack *s)
{
    return s->firstLink == 0;
}

void linkedListStackPop(struct linkedListStack *s)
{
    /* Fix me */

    if (!linkedListStackIsEmpty(s))
    {
        struct link *lnk = s->firstLink->next;
        free(s->firstLink);
        s->firstLink = lnk;
    }
}

void linkedListStackFree(struct linkedListStack *s)
{
    while (!linkedListStackIsEmpty(s))
        linkedListStackPop(s);
}

void linkedListStackPush(struct linkedListStack *s, TYPE d)
{
    struct link *newLink = (struct link *)malloc(sizeof(struct link));
    assert(newLink != 0);
    
    /* Fix me */
    newLink->value = d;
    newLink->next = s->firstLink;
    s->firstLink = newLink;
}

TYPE linkedListStackTop(struct linkedListStack *s)
{
    /* Fix me */
    if (s->firstLink == 0)
    {
        return 0;
    }
    
    return s->firstLink->value;
}

int main (){
    struct linkedListStack * list = malloc(sizeof(struct linkedListStack));

    printf("Initializing the linked list.\n");
   linkedListStackInit(list);
   printf("Is list empty? = %i\n", linkedListStackIsEmpty(list));
   
   printf("Pushing the value 3 onto the list.\n");
   linkedListStackPush(list,3);
   printf("Is list empty? = %i\n", linkedListStackIsEmpty(list));
   printf("Top of the list = %i\n", linkedListStackTop(list));
   
   printf("Pushing the value 5 onto the list.\n");
   linkedListStackPush(list,5); 
   printf("Pushing the value 8 onto the list.\n");
   linkedListStackPush(list,8);
   printf("Pushing the value 13 onto the list.\n");
   linkedListStackPush(list,13);
   
   printf("Top of the list = %i\n", linkedListStackTop(list));
   printf("Popping the list.\n");
   linkedListStackPop(list);
   
   printf("Top of the list = %i\n", linkedListStackTop(list));
   printf("Popping the list.\n");
   linkedListStackPop(list);
   
   printf("Top of the list = %i\n", linkedListStackTop(list));
   printf("Popping the list.\n");
   linkedListStackPop(list);
   
   printf("Top of the list = %i\n", linkedListStackTop(list));
   printf("Is list empty? = %i\n", linkedListStackIsEmpty(list));
   printf("Popping the list.\n");
   linkedListStackPop(list);
   
   printf("Top of the list = %i\n", linkedListStackTop(list));
   printf("Is list empty? = %i\n", linkedListStackIsEmpty(list));

   linkedListStackFree(list);
   
    return 0;
}