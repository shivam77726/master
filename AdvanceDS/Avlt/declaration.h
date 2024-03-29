#define NOF 7

void init(void);

extern void* mainMenu(void*);
extern void* exitProgram(void*);
extern void* createTree(void*);
extern void* createNode(void*);
extern void* insertNode(void*);
extern void* inOrderTraversal(void*);
extern void* getBalanceFactor(void*);

extern void* (*fptr[NOF])(void*);
