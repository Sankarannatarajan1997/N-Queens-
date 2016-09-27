struct stack{
	int arr[50];
	int top;
};
int isEmpty(struct stack *);
int push(struct stack *,int);
int pop(struct stack *,int *);
