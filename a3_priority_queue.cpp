#include "a3_priority_queue.hpp"

// Implement the functions here

 // Constructor initializes heap_ to an array of (capacity_ + 1) size, so 
  // that there are at most capacity_ elements in the priority queue. 
  PriorityQueue::PriorityQueue(unsigned int capacity): capacity_(capacity) {

  	//capacity_(capacity) == capacity_ = capacity;
  	heap_ = new DataType [capacity+ 1];
  	size_ = 0;

  }
  // Destructor of the class PriorityQueue. It deallocates the memory space 
  // allocated for the priority queue. 
  PriorityQueue::~PriorityQueue() 
  {
  	delete [] heap_;
  }
  
  // Returns the number of elements in the priority queue.
  unsigned int size() const
  {
  	return size_;
  }
  // Returns true if the priority queue is empty, and false otherwise.
  bool empty() const
  {
  	return size_ == 0;
  }
  // Returns true if the priority queue is full, and false otherwise.
  bool full() const
  {
  	return size_== capacity_;
  }
  // Prints the contents of the priority queue.
  void print() const
  {
  	for(int i = 0; i < size_; i++)
  	{
  		cout << heap_[i] << endl;
  	}
  }
  // Returns the max element of the priority queue, but does not remove it.
  DataType max() const
  {
  	return heap_[1];
  }

  
  // Inserts value into the priority queue. Returns true if successful, and 
  // false otherwise. Assume no duplicate entries will be entered.
  bool enqueue(DataType val)
  {

  	if(full ())
  	{
  		return false;
  	}
  	else if(empty ())
  	{
  		heap_[1] = val;
  		size_++;
  		return true;
  	}
  	else
  	{
  		heap_[size +1] = val;
  		for(int i =size +1; i > 0; i = floor(i/2))
  		{
  			if (heap_[1] == val)
  			{
  				size_++;
  				return true;
  			}	
  			if(heap_[i] < heap_[floor(i/2)]){
  				size_++;
  				return true;
  			}
  			else
  			{
  				DataType temp = heap_[floor(i/2)];
  				heap_[floor(i/2)] = heap_[i];
  				heap_[i] = temp;
  			}
  		}
  	}

  	return false;
  }
  // Removes the top element with the maximum value (priority) and rearranges 
  // the resulting heap. Returns true if successful, and false otherwise.
  bool dequeue()
  {
  	if(empty())
  	{
  		return false;
  	}
  	else
  	{
  		heap_[1] = heap_[size_];
  		heap_[size_] = NULL;
  		int c = 0;
  		for(int i = 1; i < size_; i = (2*1) + c)
  		{

  			if((2*i) > size_)
  			{
  				size_--;
  				return true;
  			}
  
  			if(heap_[2*i] > heap_[(2*i)+1])
  			{
  				if(heap_[i] < heap_[2*i])
  				{
  					DataType temp = heap_[i];
  					heap_[i] = heap_[2*i];
  					heap[2*i] = temp;
  					c = 0;

  				}
  			}
  			if(heap_[i] < heap_[(2*i)+1])
			{
				DataType temp = heap_[i];
				heap_[i] = heap_[(2*i)+1];
				heap[(2*i)+1] = temp;
				c = 1;
			}
			else
			{
				size_--;
				return true;
			}
  		}


  		size_--;
  		return true;
  	}

  	return false;
  }
