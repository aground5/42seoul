#include <iostream>
#include <fstream>

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
	void	inorder_print(std::ofstream &out)
	{
		if (left != NULL)
			left->inorder_print(out);
		out << get_data() << " ";
		if (right != NULL)
			right->inorder_print(out);
	}
	void	preorder_print(std::ofstream &out)
	{
		out << get_data() << " ";
		if (left != NULL)
			left->preorder_print(out);
		if (right != NULL)
			right->preorder_print(out);
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
		recalibrate_height();
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
		recalibrate_height();
	}
	int	renew_balance(bool &collapsed)
	{
		balance = 0;
		if (left != NULL)
			balance -= left->renew_balance(collapsed);
		if (right != NULL)
			balance += right->renew_balance(collapsed);
		if (collapsed)
			return (-1);
		if (balance <= -2)		// left side
		{
			collapsed = true;
			if (left->left->get_height() > left->right->get_height())
				rotL();
			else if (left->left->get_height() < left->right->get_height())
			{
				left->rotR();
				rotL();
			}
		}
		else if (balance >= 2)		// right side
		{
			collapsed = true;
			if (right->left->get_height() > right->right->get_height())
			{
				right->rotL();
				rotR();
			}
			else if (right->left->get_height() < right->right->get_height())
				rotR();
		}
		return (height);
	}
	void	recalibrate_height(void)
	{
		if (this == NULL)
			return ;
		this->height = 1 + std::max(this->left->get_height(), this->right->get_height());
		parent->recalibrate_height();
	}
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
	AVLParent->insert_node(data);
	bool	balanceCollapsed;
	do {
		balanceCollapsed = false;
		AVLParent->renew_balance(balanceCollapsed);
	} while (balanceCollapsed);
	AVLParent = AVLParent->get_root();
}

int main(void)
{
	Node			*AVLParent = NULL;
	std::ifstream	in("AVL.in");
	std::ofstream	out("AVL.out");
	char	op;
	int		content;
	while (!in.eof())
	{
		in >> op;
		if (in.eof())
			break ;
		in >> content;
		if (op == 'I')
		{
			insert_node(content, AVLParent);
			out << "I ";
			AVLParent->inorder_print(out);
			out << std::endl;
			out << "P ";
			AVLParent->preorder_print(out);
			out << std::endl << std::endl;
		}
	}
	in.close();
	out.close();
	delete AVLParent;
}