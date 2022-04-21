#include <iostream>

class Node {
private:
	Node	*parent;
	Node	*left;
	Node	*right;
	int		data;
	int		balance;
	int		height;
public:
	Node (Node *parent, int data) : parent(parent), left(NULL), right(NULL), data(data), balance(0), height(1)
	{
		parent->increase_height(height);
	}
	Node (int data) : parent(NULL), left(NULL), right(NULL), data(data), balance(0), height(1) {}
	~Node ()
	{
		delete left;
		delete right;
	}
	Node	*get_root()
	{
		if (parent != NULL)
			return (parent->get_root());
		else
			return (this);
	}
	void	print_node()
	{
		std::cout << get_data() << " ";
		if (left != NULL)
			left->print_node();
		if (right != NULL)
			right->print_node();
	}
	void	rotL()
	{
		if (parent->get_right() == this)
			parent->set_right(get_left());
		else if (parent->get_left() == this)
			parent->set_left(get_left());
		left->set_parent(get_parent());
		set_parent(get_left());
		set_left(parent->get_right());
		left->set_parent(this);
		parent->set_right(this);
		this->height = 1 + std::max(this->left->get_height(), this->right->get_height());
		this->parent->height = 1 + std::max(this->get_height(), this->parent->left->get_height());
	}
	void	rotR()
	{
		if (parent->get_right() == this)
			parent->set_right(get_right());
		else if (parent->get_left() == this)
			parent->set_left(get_right());
		right->set_parent(get_parent());
		set_parent(get_right());
		set_right(parent->get_left());
		right->set_parent(this);
		parent->set_left(this);
		this->height = 1 + std::max(this->left->get_height(), this->right->get_height());
		this->parent->height = 1 + std::max(this->get_height(), this->parent->right->get_height());
	}
	int	renew_balance(void)
	{
		balance = 0;
		if (left != NULL)
			balance -= left->renew_balance();
		if (right != NULL)
			balance += right->renew_balance();
		if (balance <= -2)		// left side
		{
			if (left->left->get_height() > left->right->get_height())
			{
				std::cout << "LL" << std::endl;
				rotL();
			}
			else if (left->left->get_height() < left->right->get_height())
			{
				std::cout << "LR" << std::endl;
				left->rotR();
				get_root()->print_node();
				std::cout << std::endl;
				rotL();
			}
			else
				std::cout << "balance collapsed but cannot find causing child." << std::endl;
		}
		else if (balance >= 2)		// right side
		{
			if (right->left->get_height() > right->right->get_height())
			{
				std::cout << "RL" << std::endl;
				right->rotL();
				rotR();
			}
			else if (right->left->get_height() < right->right->get_height())
			{
				std::cout << "RR" << std::endl;
				rotR();
			}
			else
				std::cout << "balance collapsed but cannot find causing child." << std::endl;
		}
		return (height);
	}
	bool	find_node(Node *node)
	{
		if (this == NULL)
			return (false);
		if (this == node)
			return (true);
		if (left != NULL && right != NULL)
			return (left->find_node(node) || right->find_node(node));
		else if (left != NULL)
			return (left->find_node(node));
		else if (right != NULL)
			return (right->find_node(node));
		return (false);
	}
	// int	renew_height(void)
	// {
	// 	int	maxHeight;

	// 	maxHeight = 0;
	// 	if (left != NULL)
	// 	{
	// 		int tmp = left->renew_height();
	// 	}
	// 	if (right != NULL)
	// 	{
	// 		right->renew_height();
	// 	}
	// 	height = maxHeight + 1;
	// }
	void	increase_height(int childHeight)
	{
		if (childHeight >= height)
		{
			height = childHeight + 1;
			if (parent != NULL)
				parent->increase_height(height);
		}
	}
	Node	*insert_node(int data)
	{
		if (this->data > data)
		{
			if (left != NULL)
				return (left->insert_node(data));
			else
				return (left = new Node(this, data));
		}
		else
		{
			if (right != NULL)
				return (right->insert_node(data));
			else
				return (right = new Node(this, data));
		}
	}
	int	get_data(void)
	{
		if (this == NULL)
			return (-1);
		return (data);
	}
	int get_height(void)
	{
		if (this == NULL)
			return (0);
		return (height);
	}
	Node	*get_parent(void)
	{
		if (this == NULL)
			return (NULL);
		return (parent);
	}
	void set_parent(Node *parent)
	{
		if (this == NULL)
			return ;
		this->parent = parent;
	}
	Node	*get_left(void)
	{
		if (this == NULL)
			return (NULL);
		return (left);
	}
	void set_left(Node *left)
	{
		if (this == NULL)
			return ;
		this->left = left;
	}
	Node	*get_right(void)
	{
		if (this == NULL)
			return (NULL);
		return (right);
	}
	void set_right(Node *right)
	{
		if (this == NULL)
			return ;
		this->right = right;
	}
};

void	insert_node(int data, Node *&AVLParent)
{
	if (AVLParent == NULL)
	{
		AVLParent = new Node(data);
		return ;
	}
	Node	*newNode = AVLParent->insert_node(data);
	AVLParent->renew_balance();
	AVLParent = AVLParent->get_root();
	AVLParent->print_node();
	std::cout << std::endl;
}

int main(void)
{
	Node *AVLParent = NULL;
	insert_node(60, AVLParent);
	insert_node(50, AVLParent);
	insert_node(20, AVLParent);
	insert_node(80, AVLParent);
	insert_node(90, AVLParent);
	insert_node(70, AVLParent);
	insert_node(55, AVLParent);
	insert_node(10, AVLParent);
	insert_node(40, AVLParent);
	insert_node(35, AVLParent);
	delete AVLParent;
}