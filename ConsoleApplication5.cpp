#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <fstream>

int get_int()
{
    int result;
    std::cout << "Enter an integer: ";
    std::cin >> result;
    while (std::cin.fail())
    {
        std::cin.clear();
        std::string line;
        std::getline(std::cin, line);
        std::cout << "Wrong number format. Try again: ";
        std::cin >> result;
    }
    return result;
}

class ShoppingCart
{
private:
    std::map<std::string, int> storeInventory;
    std::map<std::string, int> cart;

public:
    void addToCart(const std::string& item, int quantity)
    {
        if (storeInventory.find(item) == storeInventory.end())
        {
            throw std::invalid_argument("Item not found in store inventory.");
        }
        if (quantity > storeInventory[item])
        {
            throw std::invalid_argument("Quantity exceeds available stock.");
        }
        cart[item] += quantity;
    }

    void removeFromCart(const std::string& item, int quantity)
    {
        if (cart.find(item) == cart.end())
        {
            throw std::invalid_argument("Item not found in cart.");
        }
        if (quantity > cart[item])
        {
            throw std::invalid_argument("Quantity exceeds quantity in cart.");
        }
        cart[item] -= quantity;
        if (cart[item] == 0)
        {
            cart.erase(item);
        }
    }

    void displayCart()
    {
        std::cout << "Items in Cart:\n";
        for (const auto& item : cart)
        {
            std::cout << item.first << " : " << item.second << "\n";
        }
    }

    void addItemToStore(const std::string& item, int quantity)
    {
        storeInventory[item] = quantity;
    }

    std::map<std::string, int> getCart() const
    {
        return cart;
    }
};

void saveCartToFile(const std::map<std::string, int>& cart, const std::string& filename)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        for (const auto& item : cart)
        {
            file << item.first << "," << item.second << "\n";
        }
        file.close();
        std::cout << "Cart data saved to " << filename << std::endl;
    }
    else
    {
        throw std::runtime_error("Unable to open file for writing.");
    }
}

int main()
{
    ShoppingCart cart;

    // Заполнение базы данных магазина
    cart.addItemToStore("item1", 10);
    cart.addItemToStore("item2", 5);

    while (true) 
    {
        try 
        {
            std::string action;
            std::cout << "Enter action (add/remove): ";
            std::cin >> action;

            if (action == "add") 
            {
                std::string item;
                int quantity;

                std::cout << "Enter item to add: ";
                std::cin >> item;
                quantity = get_int();

                cart.addToCart(item, quantity);
            }
            else if (action == "remove") 
            {
                std::string item;
                int quantity;

                std::cout << "Enter item to remove: ";
                std::cin >> item;
                quantity = get_int();

                cart.removeFromCart(item, quantity);
            }
            else 
            {
                throw std::invalid_argument("Invalid action. Please enter 'add' or 'remove'.");
            }

            cart.displayCart();

            // Сохранение корзины в файл после каждого изменения
            saveCartToFile(cart.getCart(), "cart_data.csv");
        }
        catch (const std::exception& e) 
        {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
    return 0;
}
