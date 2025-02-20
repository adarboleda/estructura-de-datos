#include <iostream>
#include <functional>

// Alias para operaciones binarias
using BinaryOp = std::function<int(int, int)>;

// Clase para operadores personalizados
class CustomOperator {
public:
    BinaryOp operation;

    CustomOperator(BinaryOp op) : operation(op) {}

    CustomOperator operator+(const CustomOperator& other) const {
        return CustomOperator([=](int a, int b) {
            return operation(a, b) + other.operation(a, b);
        });
    }

    int execute(int a, int b) const {
        return operation(a, b);
    }
};

// Nodo de la lista circular doble
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Clase para la lista circular doble
class CircularDoublyLinkedList {
private:
    Node* head;

public:
    CircularDoublyLinkedList() : head(nullptr) {}

    // Insertar un nodo al final
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    // Eliminar un nodo con un valor específico
    bool remove(int value) {
        if (!head) return false;

        Node* current = head;
        do {
            if (current->data == value) {
                if (current->next == current) { // Único nodo
                    delete current;
                    head = nullptr;
                } else {
                    Node* prevNode = current->prev;
                    Node* nextNode = current->next;

                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;

                    if (current == head) {
                        head = nextNode;
                    }

                    delete current;
                }
                return true;
            }
            current = current->next;
        } while (current != head);

        return false;
    }

    // Mostrar la lista circular
    void display() const {
        if (!head) {
            std::cout << "La lista está vacía." << std::endl;
            return;
        }

        Node* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }

    // Aplicar una operación personalizada a todos los elementos de la lista
    void applyOperation(const CustomOperator& op, int operand) {
        if (!head) return;

        Node* current = head;
        do {
            current->data = op.execute(current->data, operand);
            current = current->next;
        } while (current != head);
    }
};



int main() {
    // Operadores personalizados
    CustomOperator add([](int a, int b) { return a + b; });
    CustomOperator multiply([](int a, int b) { return a * b; });
    CustomOperator combined = add + multiply;

    // Lista circular doble
    CircularDoublyLinkedList list;

    int option;
    do {
        std::cout << "\n----- Menú -----\n";
        std::cout << "1. Insertar valor en la lista\n";
        std::cout << "2. Eliminar valor de la lista\n";
        std::cout << "3. Mostrar lista\n";
        std::cout << "4. Aplicar suma a todos los elementos\n";
        std::cout << "5. Aplicar multiplicación a todos los elementos\n";
        std::cout << "6. Aplicar operación combinada (suma + multiplicación)\n";
        std::cout << "7. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> option;

        switch (option) {
        case 1: {
            int value;
            std::cout << "Ingrese el valor a insertar: ";
            std::cin >> value;
            list.insert(value);
            std::cout << "Valor insertado correctamente.\n";
            break;
        }
        case 2: {
            int value;
            std::cout << "Ingrese el valor a eliminar: ";
            std::cin >> value;
            if (list.remove(value)) {
                std::cout << "Valor eliminado correctamente.\n";
            } else {
                std::cout << "El valor no se encontró en la lista.\n";
            }
            break;
        }
        case 3:
            std::cout << "Contenido de la lista: ";
            list.display();
            break;
        case 4: {
            int operand;
            std::cout << "Ingrese el valor a sumar a cada elemento: ";
            std::cin >> operand;
            list.applyOperation(add, operand);
            std::cout << "Operación de suma aplicada.\n";
            break;
        }
        case 5: {
            int operand;
            std::cout << "Ingrese el valor para multiplicar cada elemento: ";
            std::cin >> operand;
            list.applyOperation(multiply, operand);
            std::cout << "Operación de multiplicación aplicada.\n";
            break;
        }
        case 6: {
            int operand;
            std::cout << "Ingrese el valor para la operación combinada: ";
            std::cin >> operand;
            list.applyOperation(combined, operand);
            std::cout << "Operación combinada aplicada.\n";
            break;
        }
        case 7:
            std::cout << "Saliendo del programa.\n";
            break;
        default:
            std::cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (option != 7);

    return 0;
}
