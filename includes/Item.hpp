#ifndef ITEM
#define ITEM

#include <string> 

using std::string;  

/**
 * @brief Classe base para representar um Item da lista.
 * 
 * Esta classe encapsula os atributos e métodos comuns de um Item,
 * como ID, nome, preço e quantidade.
 */
class Item {
    protected:
        int id;           /**< ID do item */
        string name;      /**< Nome do item */
        double price;     /**< Preço do item */
        int quantity;     /**< Quantidade do item */

    public:
        /**
         * @brief Construtor da classe Item.
         * 
         * @param id ID do item.
         * @param name Nome do item.
         * @param price Preço do item.
         * @param quantity Quantidade do item.
         */
        Item(const int& id, const string& name, const double& price, const int& quantity);

        /**
         * @brief Destrutor virtual padrão.
         * 
         * Destrutor virtual padrão para a classe Item.
         */
        virtual ~Item() = default;

        /**
         * @brief Obtém o ID do item.
         * 
         * @return ID do item.
         */
        int getId();

        /**
         * @brief Obtém o preço do item.
         * 
         * @return Preço do item.
         */
        double getPrice();

        /**
         * @brief Obtém a quantidade do item.
         * 
         * @return Quantidade do item.
         */
        int getQuantity();

        string getName();

        /**
         * @brief Exibe informações do item.
         * 
         * Exibe as informações de id, nome, valor e quantidade do item.
         */
        virtual void display();

};

#endif
