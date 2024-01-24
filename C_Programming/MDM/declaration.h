#define NOF 10
//extern short cl;
void init();
extern void* openFile(void*);
extern void* exitFail(void*);
extern void* compression(void*);
extern void* compressionStat(void*);
extern void* decompressionStat(void*);
extern void* createMasterarray(void*);
extern void* uniqchar(void*);
extern void* codeLength(void*);
extern void* findLocation(void*);
extern void* mainMenu(void*);

extern void* (*fun_ptr[NOF])(void*);
