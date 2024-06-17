#include "PersonalizedException.hpp"

// construtor que inicializa a mensagem de erro
PersonalizedException::PersonalizedException(const string& message)
    : msg(message) {}

// método whay() que retorna a mensagem de erro
const char* PersonalizedException::what() const noexcept {
    return msg.c_str(); // Converte std::string para const char*
}