#include <iostream>
#include <utility>

template <typename T>
struct Node {
    T data;
    Node* next;

    explicit Node(T data) : data(std::move(data)), next(nullptr) {};
};

template <typename T>
void showList(const Node<T>* head) {
    const Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template<typename T>
Node<T>* arrayToList(const T tab[], size_t size) {
    if (size == 0) {
        return nullptr;
    }

    auto* head = new Node<T>(tab[0]);
    Node<T>* current = head;
    for (auto i = 1; i < size; ++i) {
        current->next = new Node<T>(tab[i]);
        current = current->next;
    }
    return head;
}

template <typename T, typename Pred>
Node<T>* extract(Node<T>*& head, Pred predicate) {
    Node<T>* newHead = nullptr;
    Node<T>* tail = nullptr;

    Node<T>* current = head;
    Node<T>* previous = nullptr;
    Node<T>* toExtract = nullptr;

    while (current != nullptr) {
        if (predicate(current->data)) {
            toExtract = current;
            current = current->next;

            if (previous != nullptr) {
                previous->next = current;
            } else {
                head = current;
            }

            toExtract->next = nullptr;
            if (tail == nullptr) {
                newHead = toExtract;
                tail = toExtract;
            } else {
                tail->next = toExtract;
                tail = toExtract;
            }
        } else {
            previous = current;
            current = current->next;
        }
    }

    return newHead;
}

template<typename T>
void deleteList (Node<T>*& head) {
    while (head != nullptr) {
        Node<T>* toDel = head;
        std::cout << "DEL "<< head->data << "; ";
        head = head->next;
        delete toDel;
    }
    std::cout << std::endl;
    head = nullptr;
}

bool isLong(const std::string& s) { return s.size() >= 5; }

auto main() -> int {
    int tabi[] = { 2, 1, 4, 3, 6, 5, 7, 8 };
    size_t sizei = sizeof(tabi)/sizeof(tabi[0]);
    Node<int>* listAi = arrayToList(tabi, sizei);
    showList(listAi);
    Node<int>* listBi = extract(listAi,
                                [](int n) {
                                    return n % 2 == 0;
                                });
    showList(listBi);
    showList(listAi);
    deleteList(listBi);
    deleteList(listAi);
    std::string tabs[]{ "Kasia", "Ola", "Ala", "Zosia", "Ela", "Basia" };
    size_t sizes = sizeof(tabs)/sizeof(tabs[0]);
    Node<std::string>* listAs = arrayToList(tabs, sizes);
    showList(listAs);
    Node<std::string>* listBs = extract(listAs, isLong);
    showList(listBs);
    showList(listAs);
    deleteList(listBs);
    deleteList(listAs);

    return 0;
}