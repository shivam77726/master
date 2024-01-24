#define NOF 15

void init();
//int cl;
extern void* mainMenu(void*);
extern void* ExitProgram(void*);
extern void* createLinkedList(void*);
extern void* createNode(void*);
extern void* displayNode(void*);
extern void* insertNode(void*);
extern void* deleteNode(void*);
extern void* insertBeg(void*);
extern void* insertEnd(void*);
extern void* insertNth(void*);
extern void* insertKey(void*);

extern void* deleteBeg(void*);
extern void* deleteEnd(void*);
extern void* deleteNth(void*);
extern void* deleteKey(void*);

extern void* (*fun_ptr[NOF])(void*);
