#ifndef STACK_HPP
#define STACK_HPP

class Stack
{
	private:
		class StackNode
		{
			friend class Stack;
			int value;
			StackNode *next;
			StackNode(int value1, StackNode *next1 = NULL)
			{
				value = value1;
				next = next1;
			}
		};
		
		StackNode *top;
		
	public:
		Stack() { top = NULL; }
		void push(int);
		void pop(int &);
		bool isEmpty() const;
		int peek();
};

#endif
