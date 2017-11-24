#pragma once
#include <exception>
#include <stdexcept>

template<typename element_type>
class dlinked_list{
	struct Node
	{
		Node* prev;
		element_type value;
		Node* next;
	};
	Node *begin_node,*end_node;
	unsigned int actual_size;
public:
	dlinked_list(): begin_node{ nullptr }, end_node{ nullptr }, actual_size{ 0 } {};
	dlinked_list(const dlinked_list& source)
	{	begin_node = nullptr; end_node = nullptr; actual_size = 0;
		for (Node* current = source.begin_node; current != nullptr; current = current->next)
		push_back(current->value);}
	void operator=(const dlinked_list& other);
	bool empty() const;
	void push_back(const element_type& value);
	element_type& at(int pos);
	element_type& operator[](int pos);
	unsigned int size() const;
	~dlinked_list()
	{	if(begin_node != nullptr && end_node != nullptr)
			for (Node *current = begin_node, *aux = current->next; current != nullptr; current = aux)
			{aux = current->next; delete current;}}
	class iterator
	{
		Node* current;
	public:
		iterator() : current{ nullptr } {};
		iterator(Node* current) : current{ current } {};
		bool operator!=(const iterator& it);
		iterator& operator++();
		iterator operator++(int);
		iterator& operator--();
		iterator operator--(int);
		iterator& operator+=(int pos); // compound assignment (does not need to be a member,
		// friends defined inside class body are inline and are hidden from non-AD lookup
		friend iterator operator+(iterator lhs, const int& pos)// passing lhs by value helps optimize chained a+b+c
		{
			lhs += pos;
			return lhs; // return the result by value (uses move constructor)
		}
		
		const element_type& operator *();
	};
	iterator begin() const;
	iterator end() const;
	const iterator& erase(iterator& pos);
};

template<typename element_type>
void dlinked_list<element_type>::operator=(const dlinked_list<element_type>& source)
{
	
	if (&source != this)
	{
		if (begin_node != nullptr && end_node != nullptr)
			for (Node *current = begin_node, *aux = current->next; current != nullptr; current = aux)
			{
				aux = current->next; delete current;
			}
		begin_node = nullptr; end_node = nullptr; actual_size = 0;
		for (Node* current = source.begin_node; current != nullptr; current = current->next)
			push_back(current->value);
		
	}
	
}

template<typename element_type>
bool dlinked_list<element_type>::empty() const
{
	return actual_size == 0;
}

template<typename element_type>
void dlinked_list<element_type>::push_back(const element_type& value)
{		
	Node* new_node = new Node{nullptr, value, nullptr};
	if (begin_node == nullptr || end_node == nullptr)
	{	begin_node = new_node;end_node = new_node;	}
	else 
	{
		end_node->next = new_node;
		new_node->prev = end_node;
		end_node = new_node;
	}
	actual_size++;
}

template<typename element_type>
element_type& dlinked_list<element_type>::at(int pos)
{
	if (pos > size())
		throw std::out_of_range("Vector out of range.(vector::_M_range_check)");
	int current_pos = 0;
	for (Node* current = begin_node; current != nullptr; current = current->next)
	{
		if(pos == current_pos++)
			return current->value;
	}
}

template<typename element_type>
element_type& dlinked_list<element_type>::operator[](int pos)
{
	return at(pos);
}

template<typename element_type>
unsigned int dlinked_list<element_type>::size() const
{
	return actual_size;
}

template<typename element_type>
typename dlinked_list<element_type>::iterator dlinked_list<element_type>::begin() const
{
	return iterator{begin_node};
}

template<typename element_type>
typename dlinked_list<element_type>::iterator dlinked_list<element_type>::end() const
{
	return iterator{};
}

template<typename element_type>
const typename dlinked_list<element_type>::iterator& dlinked_list<element_type>::erase(iterator& pos)
{
	if(pos != nullptr)
		for (Node* current = begin_node; current != nullptr; current = current->next)
			if(*pos == current->value)
			{
				pos+=1;
				Node *aux_p = current->prev, *aux_n = current->next;
				if(aux_p != nullptr)
				aux_p->next = current->next;
				else begin_node = aux_n;
				if(aux_n != nullptr)
				aux_n->prev = current->prev;
				else end_node = aux_p;
				delete current;
				actual_size--;
				return pos;
			}
	return nullptr;
}

template<typename element_type>
bool dlinked_list<element_type>::iterator::operator!=(const iterator & other)
{
	return current != other.current;
}

template<typename element_type>
inline typename dlinked_list<element_type>::iterator & dlinked_list<element_type>::iterator::operator+=(int pos)
{          
	for (int j = 0; j < pos; j++)
		operator++();
	return *this; 
}

template<typename element_type>
typename dlinked_list<element_type>::iterator& dlinked_list<element_type>::iterator::operator++()
{
	current = current->next;
	return *this;
}

template<typename element_type>
typename dlinked_list<element_type>::iterator dlinked_list<element_type>::iterator::operator++(int)
{
	iterator temp(*this);
	operator++();
	return temp;
}

template<typename element_type>
typename dlinked_list<element_type>::iterator& dlinked_list<element_type>::iterator::operator--()
{
	current = current->prev;
	return *this;
}

template<typename element_type>
typename dlinked_list<element_type>::iterator dlinked_list<element_type>::iterator::operator--(int)
{
	iterator temp(*this);
	current = current->prev;
	return temp;
}

template<typename element_type>
const element_type& dlinked_list<element_type>::iterator::operator*()
{
	return current->value;
}

void test_linked_list();