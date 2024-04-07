#define NOF 12

void init(void);

extern void* mainMenu(void*);
extern void* exitProgram(void*);
extern void* createTree(void*);
extern void* createNode(void*);
extern void* insertNode(void*);
extern void* inOrderTraversal(void*);
extern void* getBalanceFactor(void*);
extern void* leftLeftRotate(void*);
extern void* rightRightRotate(void*);
extern void* leftRightRotate(void*);
extern void* rightLeftRotate(void*);
extern void* deleteNode(void*);

extern void* (*fptr[NOF])(void*);
