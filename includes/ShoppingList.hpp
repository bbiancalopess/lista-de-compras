#ifndef SHOPPINGLIST
#define SHOPPINGLIST

#include "Item.hpp" 
#include <vector>   
#include "PerishableItem.hpp"

using std::vector;

/**
 * @brief Classe para representar uma lista de compras.
 * 
 * Esta classe gerencia uma lista de itens de compra.
 */
class ShoppingList {
private:
    vector<Item*> items;  /**< Vetor de ponteiros para itens */

public:
    /**
     * @brief Construtor padrão da classe ShoppingList.
     * 
     * Inicializa uma lista de compras vazia.
     */
    ShoppingList();

    /**
     * @brief Destrutor da classe ShoppingList.
     * 
     * Libera a memória alocada para todos os itens da lista.
     */
    ~ShoppingList();

    /**
     * @brief Adiciona um item à lista de compras.
     * 
     * @param item Ponteiro para o item a ser adicionado.
     */
    void addItem(Item* item);

    void addPerishableItem(PerishableItem* item);

    /**
     * @brief Remove um item da lista de compras pelo ID.
     * 
     * @param id ID do item a ser removido.
     */
    void removeItem(int id);

    /**
     * @brief Exibe todos os itens da lista de compras.
     * 
     * @return Valor gasto na lista de compras, soma dos valores dos itens.
     */
    double displayItems();

    /**
     * @brief Obtém o último ID usado na lista de compras.
     * 
     * @return Último ID usado na lista.
     */
    int getLastId();

    /**
     * @brief Obtém todos os itens da lista do csv e cria-os no sistema.
     */
    void getAllItemsFromCSV();

};

#endif 
