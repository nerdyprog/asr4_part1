#define HEAP_SIZE 50
#define FREE 1
#define BUSY 0

unsigned char heap[HEAP_SIZE];

typedef struct
{
        unsigned int free;
        unsigned int size;
        unsigned char * addr;
        unsigned char * next_chunk;
        unsigned char * previous_chunk;
} chunk ;
unsigned int get_int(void *ptr);
void set_int(void *ptr, unsigned int val);
void set_chunk(chunk *c, unsigned char *ptr);
void get_chunk(chunk *c, unsigned char *ptr);
void init_alloc();
void display_raw();
void display_chunks();
void *my_malloc(unsigned int size);
void my_free(void *ptr);
