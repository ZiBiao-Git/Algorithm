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
								List(){}

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
								void Print(Node<T>* head)
								{
                 auto temp =head;
                 while(temp)
								 {
                    std::cout<<temp->value<<"-->";
										temp = temp->next;
								 }
								 std::cout<<"nullptr"<<std::endl;
								}
								void push_back(T value)
								{

                   Node<T>* newNode = new Node<T>(value);
									 if(head == nullptr)
									 {
                     head = newNode;
										 return;
									 }
									 auto temp = head;
									 while(temp->next)
													 temp =temp->next;
									 temp->next = newNode;
								}
								Node<T>* head = nullptr;	 

};

template<typename T>
Node<T>* reverse_1(Node<T>* head)
{
   if(head == nullptr || head->next == nullptr)
					 return head;
	 Node<T>* pre = nullptr;
	 Node<T>* cur = head;
	 Node<T>* end = head->next;
	 while(end)
	 {
      cur->next = pre;
			pre = cur;
			cur= end;
			end = end->next;
    
	 }
      cur->next = pre;
      return cur;   
}

template<typename T>
Node<T>* reverse_2(Node<T>* head)
{

   if(head == nullptr || head->next == nullptr)
					 return head;
	 Node<T>* newHead = reverse_2(head->next);
	 head->next->next = head;
	 head->next = nullptr;
	 return newHead;
}

template<typename T>
void Common(Node<T>* head1,Node<T>* head2)
{
   if(head1 == nullptr || head2 == nullptr)
					 return;
	 while(head1 && head2)
	 {
     if(head1->value == head2->value)
		 {
           std::cout<<head1->value<<" ";
					 head1 = head1->next;
					 head2 = head2->next;
		 }
		 else if(head1->value < head2->value)
						 head1=head1->next;
		 else
						 head2 = head2->next;
	 }
	 std::cout<<std::endl;

}

template<typename T>
bool IsPalindrome(Node<T>* head)
{
   if(head == nullptr || head->next == nullptr)
					 return true;
    Node<T>* slow  = head;
    Node<T>* quick  = head;
    if(quick->next && quick->next->next)
		{
       slow = slow ->next;
			 quick = quick->next;
		}
		quick = slow->next;
		Node<T>* pre = nullptr;
		Node<T>* cur = quick;
		Node<T>* end = quick->next;
    while(end)
		{
        cur->next = pre;
				pre = cur;
				cur = end;
				end= end->next;
 
		}
		cur->next = pre;
		auto NewHead = cur;
		bool res = true;
		while(head && NewHead)
		{
        if(NewHead->value != head->value)
				{
            res = false;
						break;
				}
				head = head->next;
         NewHead = NewHead->next; 
		}
		slow->next = reverse_2(cur);
		return res;
}
int main()
{
  List<int> ls,ls1;
	ls.push_back(1);
	ls.push_back(2);
	ls.push_back(3);
	ls.push_back(4);
	ls.push_back(5);
	ls.Print(ls.head);
	ls1.push_back(1);
	ls1.push_back(2);
	ls1.push_back(2);
	ls1.push_back(3);
	ls1.push_back(1);
	ls1.Print(ls1.head);
//	Common(ls.head,ls1.head);
//	ls.Print(reverse_1(ls.head));
//	ls.Print(reverse_2(ls.head));
    std::cout<<IsPalindrome(ls1.head)<<std::endl;
		ls1.Print(ls1.head);
  return 0;
}
