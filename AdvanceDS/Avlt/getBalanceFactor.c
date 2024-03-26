#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"


void* getBalanceFactor(void* arg)
{
	int bf;
#ifdef DEBUG
	printf("%s Begin Node:%d.\n",__func__,((Node*)arg)->data);
#endif

	if(((Node*)arg)->left==NULL && ((Node*)arg)->right!=NULL)
        {
//                ((Node*)arg)->height=1+((Node*)arg)->right->height;
                bf= - ((Node*)arg)->right->height;
        }
        else if(((Node*)arg)->right==NULL && ((Node*)arg)->left!=NULL)
        {
//                ((Node*)arg)->height=1+((Node*)arg)->left->height;
                bf= ((Node*)arg)->left->height;
        }
        else if(((Node*)arg)->right==NULL && ((Node*)arg)->left==NULL)
        {
//              ((Node*)arg)->height=1;
                bf=0;
        }
        else
        {
//                ((Node*)arg)->height=1+(((Node*)arg)->left->height > ((Node*)arg)->right->height ? ((Node*)arg)->left->height:((Node*)arg)->right->height);
                bf=((Node*)arg)->left->height - ((Node*)arg)->right->height;
        }

	
	
	if(bf>1 || bf <-1)
        {
                if(((Node*)arg)->left==NULL && ((Node*)arg)->right==NULL)
                {
                        printf("Balance Factor is Zero\n");
                }
                else if(((Node*)arg)->left==NULL)
                {

                        if(((Node*)arg)->right->left==NULL && ((Node*)arg)->right->right==NULL)
                        {
                                printf("Balance Factor is Zero\n");
                        }
                        else if(((Node*)arg)->right->left==NULL)
                        {
                                printf("Need to do RR rotation\n");
                        }
                        else
                        {
                                printf("Need to do RL rotation\n");
                        }

                }
                else
                {
                        if(((Node*)arg)->left->left==NULL && ((Node*)arg)->left->right==NULL)
                        {
                                printf("Balance Factor is Zero\n");
                        }
                        else if(((Node*)arg)->left->left==NULL)
                        {
                                printf("Need to do LR rotation\n");
                        }
                        else
                        {
                                printf("Need to do LL rotation\n");
                        }
                }
        }


#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif

	return (void*)0;
}
