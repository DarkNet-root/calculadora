#include <iostream>
#include <stdexcept>

double adicao(double a, double b)
{
    return a + b;
}
double subtracao(double a, double b)
{
    return a - b;
}
double multiplicacao(double a, double b)
{
    return a * b;
}
double divisao(double a, double b)
{
    if (b == 0)
    {
        throw std::invalid_argument("Nao e possivel dividir por 0.");
    }
    return a / b;
}

int opcao()
{
    int op;

    std::cout << "\n\nESCOLHA A OPERACAO." << std::endl;
    std::cout << "1. Adicao" << std::endl;
    std::cout << "2. subtracao" << std::endl;
    std::cout << "3. Multiplicacao" << std::endl;
    std::cout << "4. Divisao" << std::endl;
    std::cout << "5. SAIR" << std::endl;
    std::cin >> op;

    if (op == 5)
    {
        std::cout << "Hasta la vista, baby!..." << std::endl;
    }
    return op;
}

int main()
{

    double a, b;
    int op;
    double resultado;

    do
    {
        std::cout << "\nDigite o primeiro numero: ";
        std::cin >> a;
        std::cout << "Didite o segundo numero: ";
        std::cin >> b;

        op = opcao();

        switch (op)
        {
        case 1:
            std::cout << "O resultado da soma e: " << adicao(a, b) << std::endl;
            break;
        case 2:
            std::cout << "O resultado da subtracao e: " << subtracao(a, b) << std::endl;
            break;
        case 3:
            std::cout << "O resultado da multiplicacao e: " << multiplicacao(a, b) << std::endl;
            break;
        case 4:
            try
            {
                resultado = divisao(a, b);
                std::cout << "O resultado da divisao e: " << resultado << std::endl;
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << "ERRO: " << e.what() << std::endl;
            }
            break;
        case 5:
            std::cout << "Saindo..." << std::endl;
            break;
        default:
            std::cout << "Ops...opcao invalida, tente novamente." << std::endl;
            break;
        }

    } while (op != 5);

    return 0;
}
