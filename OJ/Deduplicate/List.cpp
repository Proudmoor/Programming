class List{
private:
	int _size;
	Node *head; Node *tail;

protected:
	void init();
	int clear();
public:
	List(){init()};
	~List();
	Node *insertFirst(const Node* p);
	Node *insertLast(const Node *p);
	Node *insertA(Node *p, int const& e);
	Node *insertB(Node *p, int const& e);
};

List::init(){
	head = new Node();
	tail = new Node();
	head ->succ = tail; head->pred = NULL;
	tail ->pred = header; tail->succ = NULL;
	_size = 0;
}
