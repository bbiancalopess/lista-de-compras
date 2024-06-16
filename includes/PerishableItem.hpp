#ifndef PERISHABLEITEM
#define PERISHABLEITEM

#include "Item.hpp"
#include <string>  

using std::string; 

/**
 * @brief Classe derivada para representar um Item Perecível.
 * 
 * Esta classe herda os atributos e métodos da classe base Item e adiciona
 * o atributo `expirationDate` para representar a data de validade do item.
 */
class PerishableItem : public Item {
private:
    string expirationDate;  /**< Data de validade do item perecível */

public:
    /**
     * @brief Construtor da classe PerishableItem.
     * 
     * @param id ID do item perecível.
     * @param name Nome do item perecível.
     * @param price Preço do item perecível.
     * @param quantity Quantidade do item perecível.
     * @param expirationDate Data de validade do item perecível.
     */
    PerishableItem(const int& id, const string& name, const double& price, const int& quantity, const string& expirationDate);
        
    /**
     * @brief Obtém a data de validade do item perecível.
     * 
     * @return Data de validade do item perecível.
     */
    string getExpirationDate();

    /**
     * @brief Exibe informações detalhadas do item perecível.
     * 
     * Este método exibe todas as informações do item, incluindo a data de validade.
     */
    void display() override;

};

#endif 