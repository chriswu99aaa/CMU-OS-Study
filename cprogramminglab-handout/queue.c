/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
    if (q == NULL)
      return NULL;
    q->head = NULL;
    q->tail = NULL;
    q->count = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* How about freeing the list elements? */
    /* Free queue structure */

    if (q == NULL)
      return;

    list_ele_t *next;
    for(list_ele_t *ele = q->head; ele!=NULL; ele = next)
    {
      // create a pointer ele (element) to be the head of the queue, while ele not equal to NULL
      // ele to be next after each iteration
      next = ele->next;
      free(ele);
    }
    free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(queue_t *q, int v)
{
    if(!q)
        return false;

    list_ele_t *newh;
    /* What should you do if the q is NULL? */

    newh = malloc(sizeof(list_ele_t));
    
    /* What if malloc returned NULL? */
    if(newh == NULL)
        return false;
    
    newh->value = v;
    newh->next = q->head;
    
    //if newh is the first element in the queue, head and tail are the same element.
    if(!q->head)
        q->tail = newh;
    q->head = newh;
    q->count++;
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(queue_t *q, int v)
{
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    
    if(q == NULL)
        return false;
    list_ele_t *newh;
    newh = malloc(sizeof(list_ele_t));
    if(!newh)
        return false;

    newh->value = v;
    // newh->prev = q->tail;
    q->tail->next = newh;
    q->tail = newh;
    q->count++;

    return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{

    if(q==NULL || q->head==NULL)
        return false;
    /* You need to fix up this code. */

    list_ele_t *newh = q->head;
    q->head = q->head->next;

    if(vp)
    {
        //store the value of the removed element as the value of the pointer *vp
        *vp = newh->value;
    }
    q->count--;
    free(newh);

    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    if(q == NULL || q->head==NULL)
    {
        return 0;
    }
    else{

        return q->count;
    }
    
}

/*
  Reverse elements in queue.

  Your implementation must not allocate or free any elements (e.g., by
  calling q_insert_head or q_remove_head).  Instead, it should modify
  the pointers in the existing data structure.
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */

    int size = q->count;
    if(q==NULL || q->head==NULL)
        return ;

    int i = 0;

    list_ele_t *current = q->head;
    list_ele_t *next = q->head->next;
    list_ele_t *new_next;
    
    for(; next; current=next, next = new_next)
    {
        //the next ele of the current node should be next
        //but we make the next->next to be current reversing the original order
        //we make such reverse for each pair of current and next.
        new_next = next->next;
        next->next = current;

    }

    q->head->next = NULL;
    q->tail = q->head;
    q->head = current;
    

}

