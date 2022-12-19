/*


   header file 


*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 50

struct node                             //implementation
{
    char data;
	struct node *next;
};
typedef struct node NODE;
NODE *s;


struct Node
{
	float coeff;
	int pow;
	struct Node* next;
};

struct node *hPtr1, *hPtr2, *hPtr3;

struct NODE {                          //polynomial multiplication
  int coefficient ,exponent;
  struct NODE *next;
};
struct NODE *h1, *h2, *h3;

struct poly                           //polynomial subtration
{
       int c,e;
       struct poly *next;
};


typedef enum {head, entry} tagfield;

typedef struct {
	int row; int col; int value;                    //sparse matrix
} entryNode;

struct MN {             /* Matrix Node */
	struct MN *down;
	struct MN *right;
	tagfield tag;
	union {
		struct MN *next;
		entryNode entry;
	} u;
};

typedef struct MN *matrixPointer;
matrixPointer hdnode[MAX_SIZE];

//Declaration of functions
  void init();
  void insertF(char x);
  void insert(char x,int pos);
  void insertL(char x);
  int size();
  void display();
  int deleteF();
  int deleteL();
  int delete(int pos);
  void create(int x);

  void addition_of_polynomial();
  void addPolynomials(struct Node** result, struct Node* first, struct Node* second);
  void displayPolynomial(struct Node* poly);
  void readPolynomial(struct Node** poly);

  struct NODE * buildNode(int coefficient, int exponent);
  void polynomial_insert(struct NODE ** myNode, int  coefficient, int exponent);
  void polynomial_multiply(struct NODE **n1, struct NODE *n2, struct NODE *n3);
  struct NODE * polynomial_deleteList(struct NODE *ptr);
  void polynomial_view(struct NODE *ptr);
  int multiplication_of_polynomial();
  int polynomial_add(struct NODE **n1, int coefficient, int exponent);

  void subtraction_of_polynomial();

  matrixPointer Read_Sparse();
  void Print_Sparse(matrixPointer node);
  void Msparse();

void init()
{
	s=NULL;
}

void insertF(char x)
{
	NODE *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	temp->data=x;
	temp->next=NULL;

    if (s==NULL)
        s=temp;
    else
   {
	temp->next=s;
	s=temp;
   }
}

void insertL(char x)
{
    NODE *temp,*p;
	temp=(NODE*)malloc(sizeof(NODE));
	temp->data=x;
	temp->next=NULL;

   if(s==NULL)
     s=temp;
 else
   {
     for(p=s;p->next!=NULL;p=p->next);
     p->next=temp;
   }
}

void insert(char x,int pos)
{
    int l;
    l=size();

	if(pos==1)
		insertF(x);
	else if (pos<1 || pos>(l+1) )
	   printf("Cannot insert Element.Invalid insertion.");
	else if (pos==(l+1))
	   insertL(x);
	else if(pos>1 && pos<(l+1))
	{
	   int i;
	   NODE *p;
       NODE *temp;
	   temp=(NODE*)malloc(sizeof(NODE));
	   temp->data=x;
	   temp->next=NULL;
      {
         for(p=s,i=1;i<(pos-1);i++,p=p->next);
	 	{
            temp->next=p->next;
            p->next=temp;
        }

      }
    }
}

int size()
{
	NODE *p;
	int i;
	for(p=s,i=0;p!=NULL;i++,p=p->next);
	return(i);
}

void display()
{
	NODE *p;
	if(s==NULL)
	  printf("LL is empty.");
    printf("DISPLAYING:");
	for(p=s;p!=NULL;p=p->next)
	printf("\n%c",p->data);
	printf("\n");
}
int deleteF()
{
	if(s==NULL)
	return 1;

	else{
		NODE *p;
		  p=s;
		  s=p->next;
		char x=p->data;
          free(p);
          return(x);
	  }
}

int underflow()
{
	if(s==NULL)
      return 1;
	else
	  return 0;
}

int deleteL()
{
	if (s==NULL)
	return 1;

	else
	{
		NODE *p,*t;
		for(p=s;p->next!=NULL;t=p,p=p->next);
		if (p==s)
		   s=NULL;
		else t->next=NULL;
		char x=p->data;
		free(p);
		return(x);
	}
}

int delete(int pos)
{
    char x;
    int l;
	l=size();

	if(s==NULL)
	  printf("Cannot Delete from linked list because of UNDERFLOW.");
    else if(pos==1){
		x=deleteF();
		printf("Deleted element:%c",x);
    }else if (pos<1 || pos>(l) )
	   printf("Cannot delete Element.Invalid deletion.");
	else if (pos==(l)){
        x=deleteL();
        printf("Deleted element:%c",x);
	}else if(pos>1 && pos<(l))
	{
	    int i;char x;
	    NODE *p,*t;
        NODE *temp;
	    temp=(NODE*)malloc(sizeof(NODE));
	    temp->data=x;
	    temp->next=NULL;
     	{
           for(p=s,i=1;i<(pos-1);i++,p=p->next);
		   {
             t=p->next;
             p->next=t->next;
             x=t->data;
             free(t);
             //return(x);
             printf("Deleted element:%c",x);
          }

       }
    }
}

void create(int  x)
{
	char n;
	int i;
	for(i=0;i<=x;i++)
	{
		NODE *temp,*p;
		temp=(NODE*)malloc(sizeof(NODE));

        printf("enter the data: ");
		scanf("%c",&n);
        temp->data=n;
		temp->next=NULL;

		if(s==NULL)
		  s=temp;
        else
        for(p=s;p->next!=NULL;p=p->next);
		p->next=temp;
	}
}

void readPolynomial(struct Node** poly)
{
	float coeff;
	int exp, cont;
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	*poly = temp;
	do{
		printf("\n Coeffecient: ");
		scanf("%f", &coeff);
		printf("\n Exponent: ");
		scanf("%d", &exp);
		temp->coeff = coeff;
		temp->pow = exp;
		temp-> next = NULL;
		printf("\nHave more terms? 1 for y and 0 for no: ");
		scanf("%d", &cont);
		if(cont)
		{
			temp->next = (struct Node*)malloc(sizeof(struct Node));
			temp = temp->next;
			temp->next = NULL;
		}
	}while(cont);
}

void displayPolynomial(struct Node* poly)
{
	printf("\nPolynomial expression is: ");
	while(poly != NULL)
	{
		printf("%fX^%d", poly->coeff, poly->pow);
		poly = poly->next;
		if(poly != NULL)
			printf("+");
	}
}

void addPolynomials(struct Node** result, struct Node* first, struct Node* second)
{
 	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
 	temp->next = NULL;
 	*result = temp;
 	while(first && second)
 	{
 		if(first->pow > second->pow)
 		{
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}
 		else if(first->pow < second->pow)
 		{
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 		else
 		{
 			temp->coeff = first->coeff + second->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 			second = second->next;
 		}

 		if(first && second)
 		{
 			temp->next = (struct Node*)malloc(sizeof(struct Node));
 			temp = temp->next;
 			temp->next = NULL;
 		}
 	}
 	while(first || second)
 	{
 		temp->next = (struct Node*)malloc(sizeof(struct Node));
 		temp = temp->next;
 		temp->next = NULL;

 		if(first)
 		{
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}

 		else if(second)
 		{
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 	}
}

void addition_of_polynomial()
{

	struct Node* first = NULL;
	struct Node* second = NULL;
	struct Node* result = NULL;

	printf("\nEnter the corresponding data:-\n");
	printf("\nFirst polynomial:\n");
	readPolynomial(&first);
	displayPolynomial(first);
	printf("\nSecond polynomial:\n");
	readPolynomial(&second);
	displayPolynomial(second);
	printf("\nResultant:");
	addPolynomials(&result, first, second);
	displayPolynomial(result);
}

 struct NODE * buildNode(int coefficient, int exponent)
{
  struct NODE *ptr = (struct NODE *) malloc(sizeof (struct NODE));
  ptr->coefficient = coefficient;
  ptr->exponent = exponent;
  ptr->next = NULL;
  return ptr;
}

/* insert data in decending order - based on exponent value */
void polynomial_insert(struct NODE ** myNode, int coefficient, int exponent)
{
  struct NODE *lPtr, *pPtr, *qPtr = *myNode;
  lPtr = buildNode(coefficient, exponent);

  /* inserting new node at appropriate position */
  if (*myNode == NULL || (*myNode)->exponent < exponent) {
    *myNode = lPtr;
    (*myNode)->next = qPtr;
    return;
  }

  /* placing new node between two nodes or end of node */
  while (qPtr) {
    pPtr = qPtr;
    qPtr = qPtr->next;
    if (!qPtr) {
      pPtr->next = lPtr;
      break;

    }
    else if ((exponent < pPtr->exponent) && (exponent > qPtr->exponent)){
    lPtr->next = qPtr;
    pPtr->next = lPtr;
    break;
      }
      }
    return;
  }

  /* inserting new node with resultant data into the output list (n1) */
  int polynomial_add(struct NODE **n1, int coefficient, int exponent)
  {
    struct NODE *x = NULL, *temp = *n1;
    if (*n1 == NULL || (*n1)->exponent < exponent) {
      /* adding at the front */
      *n1 = x = buildNode(coefficient, exponent);
      (*n1)->next = temp;
    } else {
      while (temp) {
    if (temp->exponent == exponent) {
      /* updating the co-efficient value  alone */
      temp->coefficient = temp->coefficient + coefficient;
      return 0;
    }
    if (temp->exponent > exponent && (!temp->next || temp->next->exponent < exponent)) {
      /* inserting in the middle or end */
      x = buildNode(coefficient, exponent);
      x->next = temp->next;
      temp->next = x;
      return 0;
    }
    temp = temp->next;
      }
      x->next = NULL;
      temp->next = x;
    }
    return 0;
  }

  void polynomial_multiply(struct NODE **n1, struct NODE *n2, struct NODE *n3)
  {
    struct NODE * temp;
    int coefficient, exponent;

    temp = n3;

    /* if both input list are absent, then output list is NULL */
    if (!n2 && !n3)
      return;

    /* input list 1(n2) is absent, then output list is input list2 (n3) */
    if (!n2) {
      *n1 = n3;
    } else if (!n3) {

      /*
       * list n3 is absent, then o/p list is n2
       */
      *n1 = n2;
    } else {
      while (n2) {
    while (n3) {
      /* multiply coefficient & add exponents */
      coefficient = n2->coefficient * n3->coefficient;
      exponent = n2->exponent + n3->exponent;
      n3 = n3->next;
      /* insert the above manipulated data to o/p list */
      polynomial_add(n1, coefficient, exponent);
    }
    n3 = temp;
    n2 = n2->next;
      }
    }
    return;
  }

  /* delete the given input list */
  struct NODE * polynomial_deleteList(struct NODE *ptr)
   {
    struct NODE *temp;
    while (ptr){
      temp = ptr->next;
      free(ptr);
      ptr = temp;
    }
    return NULL;
  }

  void polynomial_view(struct NODE *ptr) {
    int i = 0;
    int flag=0;
    while (ptr) {
      if(ptr->exponent != 0 || ptr->exponent != 1 ){
    if(ptr->coefficient > 0 && flag==0 ){
      printf("%dx^%d", ptr->coefficient,ptr->exponent);
      flag++;
    }
    else if (ptr->coefficient > 0 && flag==1 )
      printf("+%dx^%d", ptr->coefficient,ptr->exponent);
    else if(ptr->coefficient < 0)
      printf("%dx^%d", ptr->coefficient,ptr->exponent);
      }
      else if (ptr->exponent == 0){
    if(ptr->coefficient > 0 && flag==0 ){
      printf("%d", ptr->coefficient);
      flag++;
    }
    else if (ptr->coefficient > 0 && flag==1 )
      printf("+%d", ptr->coefficient);
    else if(ptr->coefficient < 0)
      printf("%d", ptr->coefficient);
      }
      else if( ptr->exponent == 1 ){
    if(ptr->coefficient > 0 && flag==0 ){
      printf("%dx", ptr->coefficient);
      flag++;
    }
    else if (ptr->coefficient > 0 && flag==1 )
      printf("+%dx", ptr->coefficient);
    else if(ptr->coefficient < 0)
      printf("%dx", ptr->coefficient);
      }
      ptr = ptr->next;
      i++;
    }
    printf("\n");
    return;
  }

  int multiplication_of_polynomial()
   {
    int coefficient, exponent, i, n;
    int count;
    printf("Enter the number of coefficients in the multiplicand:");
    scanf("%d",&count);
    for(i=0;i<count;i++){
      printf("Enter the coefficient and exponent part:");
      scanf("%d %d", &coefficient,&exponent);
      polynomial_insert(&h1, coefficient, exponent);
    }
    printf("Enter the number of coefficients in the multiplier:");
    scanf("%d",&count);
    for(i=0;i<count;i++){
      printf("Enter the coefficient and exponent part:");
      scanf("%d %d", &coefficient,&exponent);
      polynomial_insert(&h2, coefficient, exponent);
    }
        printf("Polynomial Expression 1: ");
        polynomial_view(h1);
        printf("Polynomial Expression 2: ");
        polynomial_view(h2);

        polynomial_multiply(&h3, h1, h2);

        printf("Result:\n");
        polynomial_view(h3);

        h1 = polynomial_deleteList(h1);
        h2 = polynomial_deleteList(h2);
        h3 = polynomial_deleteList(h3);

        return 0;
  }


void subtraction_of_polynomial()

{

struct poly

{

float coff;

int expo;

struct poly *link;

}*temp1,*start1,*temp2,*start2,*start3,*temp3;

int n,i,z=1,num;

char c;

start1=NULL;

printf("\tSUBTRACTION\n\n");

while(1)

{

if(start1==NULL)

{

temp1=(struct poly*)malloc(sizeof(struct poly));

printf("Enter Coefficient and Exponent for polynomial 1 => Node %d\n",z);

scanf("%f %d",&temp1->coff,&temp1->expo);

start1=temp1;

temp1->link=NULL;

}

else

{

temp1->link=(struct poly*)malloc(sizeof(struct poly));

temp1=temp1->link;

printf("Enter Coefficient and exponent for polynomial 1 => Node %d\n",z);

scanf("%f %d",&temp1->coff,&temp1->expo);

}

z++;

printf("Do you want to create another node (type y (yes) and type n (no))\n");

fflush(stdin);

scanf("%c",&c);

if(c!='y')

{

temp1->link=NULL;

break;

}

}

start2=NULL;

temp2=NULL;

z=1;

while(1)

{

if(start2==NULL)

{

temp2=(struct poly*)malloc(sizeof(struct poly));

printf("Enter Coefficient and exponent for polynomial 2 => Node %d\n",z);

scanf("%f %d",&temp2->coff,&temp2->expo);

start2=temp2;

temp2->link=NULL;

}

else

{

temp2->link=(struct poly*)malloc(sizeof(struct poly));

temp2=temp2->link;

printf("Enter Coefficient and exponent for polynomial 2 => Node %d\n",z);

scanf("%f %d",&temp2->coff,&temp2->expo);

}

z++;

printf("Do you want to create another node\n");

fflush(stdin);

scanf("%c",&c);

if(c!='y')

{

temp2->link=NULL;

break;

}

}

// TARVERSING

temp1=NULL;

temp2=NULL;

temp1=start1;

temp2=start2;

printf("Polynomial Linked List 1\n");

while(temp1!=NULL)

{

printf("%2fx^%d-",temp1->coff,temp1->expo);

temp1=temp1->link;

}

printf("\b \b");

printf("\nPolynomial Linked List 2\n");

while(temp2!=NULL)

{

printf("%2fx^%d -",temp2->coff,temp2->expo);

temp2=temp2->link;

}

printf("\b \b");

// subtraction

temp1=NULL;

temp2=NULL;

temp1=start1;

temp2=start2;

temp3=NULL;

start3=NULL;

while(1)

{

if((temp1!=NULL)||(temp2!=NULL))

{

if(start3==NULL)

{

if((temp1->expo)==(temp2->expo))

{

temp3=(struct poly*)malloc(sizeof(struct poly));

temp3->coff= (temp1->coff) - (temp2->coff);

temp3->expo=temp1->expo;

start3=temp3;

temp1=temp1->link;

temp2=temp2->link;

temp3->link=NULL;

}

else if(temp1->expo>temp2->expo)

{

temp3=(struct poly*)malloc(sizeof(struct poly));

temp3->coff=temp1->coff;

temp3->expo=temp1->expo;

start3=temp3;

temp1=temp1->link;

temp3->link=NULL;

}

else

{

temp3=(struct poly*)malloc(sizeof(struct poly));

temp3->coff=temp2->coff;

temp3->expo=temp2->expo;

start3=temp3;

temp2=temp2->link;

temp3->link=NULL;

}

}

else

{

if(temp1->expo==temp2->expo)

{

temp3->link=(struct poly*)malloc(sizeof(struct poly));

temp3=temp3->link;

temp3->coff= (temp1->coff) - (temp2->coff);

temp3->expo=temp1->expo;

temp1=temp1->link;

temp2=temp2->link;

}

else if(temp1->expo>temp2->expo)

{

temp3->link=(struct poly*)malloc(sizeof(struct poly));

temp3=temp3->link;

temp3->coff=temp1->coff;

temp3->expo=temp1->expo;

temp1=temp1->link;

}

else

{

temp3->link=(struct poly*)malloc(sizeof(struct poly));

temp3=temp3->link;

temp3->coff=temp2->coff;

temp3->expo=temp2->expo;

temp2=temp2->link;

}

}

}

else

break;

}

temp3->link=NULL;

//traversing temp3

temp3=NULL;

temp3=start3;

printf("\nResult:\n");

while(temp3!=NULL)

{

printf("%2fx^%d - ",temp3->coff,temp3->expo);

temp3=temp3->link;

}

printf("\b\b");

}


matrixPointer Read_Sparse()
{
    int numRows, numCols, numTerms, numHeads, i;
    int row, col, value, currentRow;
	matrixPointer temp, last, node;
	printf("Enter the number of rows, columns and number of nonzero terms: \n");
	scanf("%d%d%d", &numRows, &numCols, &numTerms);
	numHeads = (numCols > numRows) ? numCols : numRows;
	/* set up header node for the list of header nodes */
    node =  (matrixPointer) malloc(sizeof(struct MN));
    node->tag = entry;
    node->u.entry.row = numRows;
    node->u.entry.col = numCols;
    if (!numHeads) node->right = node;
    else {                                  /* initialize the header nodes */
        for (i = 0; i < numHeads; i++) {
            temp = (matrixPointer) malloc(sizeof(struct MN));
            hdnode[i] = temp;
            hdnode[i]->tag = head;
            hdnode[i]->right = temp;
            hdnode[i]->u.next = temp;
        }
        currentRow = 0;
        last = hdnode[0];
        for(i=0; i < numTerms; i++) {
            printf("Enter row, column and value: ");
            scanf("%d%d%d", &row, &col, &value);
            if (row > currentRow) {                 /*close current row */
                last->right = hdnode[currentRow];
                currentRow = row;
                last = hdnode[row];
            }
            temp = (matrixPointer) malloc(sizeof(*temp));
            temp->tag = entry;
            temp->u.entry.row = row;
            temp->u.entry.col = col;
            temp->u.entry.value = value;
            last->right = temp;          /* link into row list */
            last = temp;
            /* link into column list */
            hdnode[col]->u.next->down = temp;
            hdnode[col]->u.next = temp;
        }
        /* close last row */
        last->right = hdnode[currentRow];
        /* close all column lists */
        for (i = 0; i < numCols; i++)
            hdnode[i]->u.next->down = hdnode[i];
        /* link all header nodes together */
        for (i = 0; i < numHeads-1; i++)
            hdnode[i]->u.next = hdnode[i+1];
        hdnode[numHeads-1]->u.next = node;
        node->right = hdnode[0];
    }
    return node;
}

void Print_Sparse(matrixPointer node)
{
    int i;
    matrixPointer temp, head;
    head = node->right;
    printf("numRows = %d, numCols = %d\n", node->u.entry.row, node->u.entry.col);
    printf("The matrix by row, col, and value: \n");
    for(i=0; i<node->u.entry.row; i++) {
        for(temp=head->right; temp != head; temp = temp->right)
            printf("%5d%5d%5d", temp->u.entry.row,temp->u.entry.col,temp->u.entry.value);
        head = head->u.next;
        printf("\n");
    }
}

void Msparse()
{
    matrixPointer p;
    p=Read_Sparse();
    Print_Sparse(p);
}
