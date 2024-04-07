#include "headers.h"
#include "declaration.h"
#include "dataStructure.h"


void* getBalanceFactor(void* arg)
{
	int bf;
#ifdef DEBUG
	printf("%s Begin Node:%d.\n",__func__,((DSinsert*)arg)->node->data);
#endif

	if(((DSinsert*)arg)->node->left==NULL && ((DSinsert*)arg)->node->right!=NULL)
        {
//                ((Node*)arg)->height=1+((Node*)arg)->right->height;
                bf= - ((DSinsert*)arg)->node->right->height;
        }
        else if(((DSinsert*)arg)->node->right==NULL && ((DSinsert*)arg)->node->left!=NULL)
        {
//                ((Node*)arg)->height=1+((Node*)arg)->left->height;
                bf= ((DSinsert*)arg)->node->left->height;
        }
        else if(((DSinsert*)arg)->node->right==NULL && ((DSinsert*)arg)->node->left==NULL)
        {
//              ((Node*)arg)->height=1;
                bf=0;
        }
        else
        {
//                ((Node*)arg)->height=1+(((Node*)arg)->left->height > ((Node*)arg)->right->height ? ((Node*)arg)->left->height:((Node*)arg)->right->height);
                bf=((DSinsert*)arg)->node->left->height - ((DSinsert*)arg)->node->right->height;
        }

	printf("Balance Factor:%d\n",bf);	
	
	if(bf>1 || bf <-1)
        {
               /* if(((DSinsert*)arg)->node->left==NULL && ((DSinsert*)arg)->node->right==NULL)
                {
                        printf("Balance Factor is Zero\n");
                }*/
                if(((DSinsert*)arg)->key > ((DSinsert*)arg)->node->data)
                {


                        if(((DSinsert*)arg)->key > ((DSinsert*)arg)->node->right->data)
                        {
                                printf("Need to do RR rotation\n");
				return fptr[8]((void*)((DSinsert*)arg)->node);
                        }
                        else
                        {
                                printf("Need to do RL rotation\n");
				return fptr[10]((void*)((DSinsert*)arg)->node);
                        }

                }
                else
                {
                        if(((DSinsert*)arg)->key > ((DSinsert*)arg)->node->left->data)
                        {
                                printf("Need to do LR rotation\n");
				return fptr[9]((void*)((DSinsert*)arg)->node);
                        }
                        else
                        {
                                printf("Need to do LL rotation\n");
				return fptr[7]((void*)((DSinsert*)arg)->node);
                        }
                }
        }


#ifdef DEBUG
	printf("%s End.\n",__func__);
#endif

	return (void*)((DSinsert*)arg)->node;
}
