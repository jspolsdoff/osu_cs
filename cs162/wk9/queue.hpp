#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue
{
	private:
		class QueueNode
		{
			friend class Queue;
			int value;
			QueueNode *next;
			QueueNode(int value1, QueueNode *next1 = NULL)
			{
				value = value1;
				next = next1;
			}
		};
		
		QueueNode *front;
		QueueNode *rear;
		
	public:
		// constructor and destructor
		Queue();
		~Queue();	
		
		// member functions
		void addBack(int num);
		int getFront();
		void removeFront();
		isEmpty();
}

#endif