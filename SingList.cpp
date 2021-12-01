#include<iostream>

template<typename T>
struct Node
{
				T value;
				Node* next;
				Node(T value):value(value),next(nullptr){}

};


template<typename T>


class List
{
				public:
								List():head(new Node<T>(0)){}

								~List()
								{
												if(head)
												{
																auto p = head;
																while(p)
																{
																				auto q = p->next;
																				delete p;
																				p=q;
																}
												}

								}
								void Print()
								{

                 while(head->next)
								 {
                    std::cout<<head->next->value<<"-->";
										head = head->next;
								 }
								 std::cout<<"nullptr"<<std::endl;
								}
								void push_back(T value)
								{

                   Node<T>* newNode = new Node<T>(value);
									 auto temp = head;
									 while(temp->next)
													 temp =temp->next;
									 temp->next = newNode;
								}
				private:
								Node<T>* head;	 

};

int main()
{
  List<int> ls;
	ls.push_back(1);
	ls.push_back(2);
	ls.push_back(3);
	ls.push_back(4);
	ls.push_back(5);
	ls.Print();
  return 0;
}
