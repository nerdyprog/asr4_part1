#include <stdio.h>
#include "malloc.h"

/* Q1 */
unsigned int get_int(void *ptr) {
        return *(unsigned int *) ptr; /* pour retourner un int on caste*/
}

void set_int(void *ptr, unsigned int val) {
        *(unsigned int *)ptr = val; /* ajout de val dans ptr, attention à ne pas oublier de caster*/       
}

/* Q2 */
void set_chunk(chunk *c, unsigned char *ptr) {
	set_int(ptr, c->free);
	set_int(ptr+sizeof(unsigned int), c->size);
	set_int((ptr + c->size-sizeof(unsigned int)), c->size);
        
}
/* Q3 */
void get_chunk(chunk *c, unsigned char *ptr){
	c->addr = ptr;
	c->free=get_int(&ptr);
	c->size=get_int(&ptr+1);
	if(get_int(&ptr)+c->size == HEAP_SIZE) c->next_chunk=NULL;
	else c->next_chunk=ptr+c->size;
	if(ptr==heap) c->previous_chunk=NULL;
	else c->previous_chunk=ptr-get_int(&ptr-1);
}
/* Q4 */
void init_alloc(){

	chunk c;
	c->free=1;
	c->size=HEAP_SIZE;
	c->next_chunk=NULL;
	c->previous_chunk=NULL;
	set_chunk(&c,heap);
}
/* Q5 */
void *my_malloc(unsigned int size){
	void *ptr = NULL;
	int old_size = 0;
	chunk tmp;
	get_chunk(&tmp, heap);
	if(tmp.size>=size){
		tmp.free = BUSY;
		old_size = tmp.size;
		tmp.size = size + 3*sizeof(unsigned int);	
		ptr = &tmp;
		&tmp = tmp.next_chunk;
		tmp.free = FREE;
		tmp.size = old_size - size + 3*sizeof(unsigned int);
	}
	
	return ptr;
}
/*Q6*/
