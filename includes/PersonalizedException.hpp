#ifndef PERSONALIZEDEXCEPTION
#define PERSONALIZEDEXCEPTION

#include <exception>
#include <string>

using std::string;

/**
 * @class PersonalizedException
 * @brief Classe de exceção personalizada que herda de std::exception.
 * 
 * Esta classe é usada para criar exceções personalizadas no programa.
 */
class PersonalizedException : public std::exception {
    private:
        string msg; ///< Armazena a mensagem de erro.
    public:
        /**
         * @brief Construtor que inicializa a mensagem de erro.
         * 
         * @param message Mensagem de erro a ser armazenada.
         */
        PersonalizedException(const string& message);
        
        /**
         * @brief Sobrescreve o método what() para retornar a mensagem de erro.
         * 
         * @return const char* Mensagem de erro.
         */
        virtual const char* what() const noexcept override;
};

#endif