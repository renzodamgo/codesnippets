#include <algorithm>
#include <functional>

template <typename T, typename R = T> class AVLtree {
  struct Node {
    T e;
    Node *l;
    Node *r;
    int h;
    Node(T e) : l(nullptr), r(nullptr), h(0) {}
    static int height(Node *n) { return n == nullptr ? -1 : n->h; }
    void updateH() { h = std::max(Node::height(l), Node::height(r)) + 1; }
  };
  Node *root;
  int lenght;
  std::function<R(T)> key; // para que sean comparables
  void destroy(Node *n) {
    if (n != nullptr) {
      destroy(n->l);
      destroy(n->r);
      delete n;
    }
  }
  void rotAB(Node *&n) {
    Node *aux = n->l;
    n->l = aux->r;
    n->updateH();
    aux->r = n;
    n = aux;
    n->updateH();
  }
  void rotBA(Node *&n) {
    Node *aux = n->r;
    n->r = aux->l;
    n->updateH();
    aux->l = n;
    n = aux;
    n->updateH();
  }
  void balance(Node *&n) {
    int delta = Node::height(n->l) - Node::height(n->r);
    if (delta < -1) {
      if (Node::height(n->r->l) > Node::height(n->r->r)) {
        rotAB(n->r);
      }
      rotBA(n);
    } else if (delta > 1) {
      if (Node::height(n->l->r) > Node::height(n->l->l)) {
        rotBA(n->l);
      }
      rotAB(n);
    }
  }
  void add(Node *&n, T e) {
    if (n == nullptr) {
      n = new Node(e);
      return;
    } else if (key(e) < key(n->e)) {
      add(n->l, e);
    } else {
      add(n->r, e);
    }
    balance(n);
    n->updateH();
  }

public:
  AVLtree(std::function<R(T)> key = [](T a) { return a; })
      : root(nullptr), lenght(0), key(key) {}
  ~AVLtree() { destroy(root); }

  int size() { return lenght; }
  int height() { return Node::height(root); }
  void Add(T e) {
    add(root, e);
    ++lenght;
  }
};
