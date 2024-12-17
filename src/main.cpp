#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include <iostream>

int main()
{
    BinaryTree<int> binaryTree;
    binaryTree.insert(10);
    binaryTree.insert(20);
    binaryTree.insert(30);
    binaryTree.print();
    std::cout << "\nSearch for 20 in BinaryTree: " << binaryTree.search(20) << '\n';
    try{
        binaryTree.remove(10);
    } catch(const std::logic_error& err){
        std::cerr << "error: " << err.what() << '\n';
    }

    BinarySearchTree<int> largeTree;
        for (int i = 0; i < 100; ++i) {
            largeTree.insert(rand() % 10);
        }
    std::cout << "Search for 7 in largeTree: " << largeTree.search(7) << '\n'; // Поиск элемента
    largeTree.print();

    BinarySearchTree<std::string> bst;
    int x = 1;
    std::string word;

    while (x != 0)
    {
        std::cout << "\nSelect 1 for enter elements/ 2 for search/ 3 for remove/ 4 for print/ 0 for finish program: ";
        std::cin >> x;
        switch (x)
        {
        case 1:
            std::cout << "enter items, 0 to end input:\n";
            while (std::cin >> word && word != "0") 
            {
                if (std::isalpha(word[0])) {
                    bst.insert(word);
                }
            }
            break;
        case 2:
            std::cin >> word;
            std::cout << "Search for " << word << " in BinarySearchTree: " << bst.search(word) << '\n';
            break;
        case 3:
            std::cin >> word;
            bst.remove(word);
            bst.print();
            break;
        case 4:
            std::cout << "Binary search tree: ";
            bst.print();
            break;
        case 0:
            break;
        }
    }

    system("pause");

    return 0;
}