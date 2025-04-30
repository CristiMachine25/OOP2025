#include <iostream>
using namespace std;

template <typename T>
struct TreeNode {
    T value;
    TreeNode<T>* firstChild;
    TreeNode<T>* nextSibling;

    TreeNode(const T& val) : value(val), firstChild(nullptr), nextSibling(nullptr) {}
};

template <typename T>
class Tree {
private:
    TreeNode<T>* root;

    void delete_subtree(TreeNode<T>* node) {
        if (node == nullptr)
            return;
        TreeNode<T>* child = node->firstChild;
        while (child != nullptr) {
            TreeNode<T>* next = child->nextSibling;
            delete_subtree(child);
            child = next;
        }
        delete node;
    }

    void swap(TreeNode<T>*& a, TreeNode<T>*& b) {
        TreeNode<T>* temp = a;
        a = b;
        b = temp;
    }

public:
    Tree() : root(nullptr) {}

    TreeNode<T>* getRoot() {
        return root;
    }

    TreeNode<T>* add_node(TreeNode<T>* parent, const T& value) {
        TreeNode<T>* newNode = new TreeNode<T>(value);

        if (parent == nullptr) {
            if (root == nullptr) {
                root = newNode;
                return root;
            }
            else {
                delete newNode;
                return nullptr; // root already exists
            }
        }

        if (parent->firstChild == nullptr) {
            parent->firstChild = newNode;
        }
        else {
            TreeNode<T>* current = parent->firstChild;
            while (current->nextSibling != nullptr) {
                current = current->nextSibling;
            }
            current->nextSibling = newNode;
        }

        return newNode;
    }

    TreeNode<T>* get_node(TreeNode<T>* node) {
        return node;
    }

    void delete_node(TreeNode<T>* node) {
        if (node == nullptr) return;

        if (node == root) {
            delete_subtree(root);
            root = nullptr;
            return;
        }

        // Find parent
        TreeNode<T>* parent = nullptr;
        find_parent(root, node, parent);
        if (parent == nullptr) return;

        TreeNode<T>* prev = nullptr;
        TreeNode<T>* current = parent->firstChild;

        while (current) {
            if (current == node) {
                if (prev == nullptr) {
                    parent->firstChild = current->nextSibling;
                }
                else {
                    prev->nextSibling = current->nextSibling;
                }
                break;
            }
            prev = current;
            current = current->nextSibling;
        }

        delete_subtree(node);
    }

    void find_parent(TreeNode<T>* current, TreeNode<T>* target, TreeNode<T>*& parent) {
        if (current == nullptr) return;
        TreeNode<T>* child = current->firstChild;
        while (child) {
            if (child == target) {
                parent = current;
                return;
            }
            find_parent(child, target, parent);
            if (parent) return;
            child = child->nextSibling;
        }
    }

    TreeNode<T>* find(TreeNode<T>* node, const T& target, bool(*cmp)(const T&, const T&)) {
        if (node == nullptr)
            return nullptr;

        if (cmp(node->value, target))
            return node;

        TreeNode<T>* child = node->firstChild;
        while (child) {
            TreeNode<T>* found = find(child, target, cmp);
            if (found)
                return found;
            child = child->nextSibling;
        }

        return nullptr;
    }

    void insert(TreeNode<T>* parent, const T& value, int index) {
        if (parent == nullptr) return;

        TreeNode<T>* newNode = new TreeNode<T>(value);

        if (index <= 0 || parent->firstChild == nullptr) {
            newNode->nextSibling = parent->firstChild;
            parent->firstChild = newNode;
            return;
        }

        TreeNode<T>* current = parent->firstChild;
        int i = 0;
        while (current->nextSibling != nullptr && i < index - 1) {
            current = current->nextSibling;
            i++;
        }

        newNode->nextSibling = current->nextSibling;
        current->nextSibling = newNode;
    }

    void sort(TreeNode<T>* node, bool(*cmp)(const T&, const T&) = nullptr) {
        if (node == nullptr || node->firstChild == nullptr) return;

        // Count children
        int count = 0;
        TreeNode<T>* current = node->firstChild;
        while (current) {
            count++;
            current = current->nextSibling;
        }

        // Copy to array
        TreeNode<T>** arr = new TreeNode<T>*[count];
        current = node->firstChild;
        for (int i = 0; i < count; ++i) {
            arr[i] = current;
            current = current->nextSibling;
        }

        // Bubble sort
        for (int i = 0; i < count - 1; ++i) {
            for (int j = 0; j < count - i - 1; ++j) {
                bool shouldSwap = cmp ? cmp(arr[j + 1]->value, arr[j]->value)
                    : arr[j + 1]->value < arr[j]->value;
                if (shouldSwap) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }

        // Rebuild list
        for (int i = 0; i < count - 1; ++i) {
            arr[i]->nextSibling = arr[i + 1];
        }
        arr[count - 1]->nextSibling = nullptr;
        node->firstChild = arr[0];

        delete[] arr;
    }

    int count(TreeNode<T>* node) {
        if (node == nullptr)
            return 0;

        int total = 1; // count self
        TreeNode<T>* child = node->firstChild;
        while (child) {
            total += count(child);
            child = child->nextSibling;
        }
        return total;
    }
};

// Comparator example
bool equals(const int& a, const int& b) {
    return a == b;
}

int main() {
    Tree<int> tree;
    auto root = tree.add_node(nullptr, 1);
    auto c1 = tree.add_node(root, 2);
    auto c2 = tree.add_node(root, 3);
    auto c3 = tree.add_node(c1, 4);

    std::cout << "Total nodes: " << tree.count(root) << '\n'; // Output: 4
    tree.delete_node(c1);
	std::cout << tree.count(root) << '\n'; // Output: 1
}