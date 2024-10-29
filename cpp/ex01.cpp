#include <iostream>
#include <string>
#include <vector>

class horse {
public:
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phonenumber;
    std::string darkest_secret;

    // Constructor
    horse(std::string firstname = "", std::string lastname = "", std::string nickname = "", std::string phonenumber = "", std::string darkest_secret = "") {
        this->firstname = firstname;
        this->lastname = lastname;
        this->nickname = nickname;
        this->phonenumber = phonenumber;
        this->darkest_secret = darkest_secret;
    }

    // Display the horse's details
    void display() const {
        std::cout << "First Name: " << firstname << "\n";
        std::cout << "Last Name: " << lastname << "\n";
        std::cout << "Nickname: " << nickname << "\n";
        std::cout << "Phone Number: " << phonenumber << "\n";
        std::cout << "Darkest Secret: " << darkest_secret << "\n";
    }
};

int main(int argc, char **argv) {
    const int max_horses = 8;
    std::vector<horse> horses;
    std::string command;

    if (argc > 1) {
        command = argv[1];
    } else {
        std::cout << "Please enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
    }

    while (command != "EXIT") {
        if (command == "ADD") {
            std::string firstname, lastname, nickname, phonenumber, darkest_secret;

            std::cout << "What's your name, bbgurl? ";
            std::getline(std::cin, firstname);

            std::cout << "Your last name is mine, isn't it? ";
            std::getline(std::cin, lastname);

            std::cout << "Are you my pookie or do you prefer something else? ";
            std::getline(std::cin, nickname);

            std::cout << "Can I have your number? ;3 ";
            std::getline(std::cin, phonenumber);

            std::cout << "What's your darkest secret, baby? ";
            std::getline(std::cin, darkest_secret);

            // Create and store the horse object
            horse newHorse(firstname, lastname, nickname, phonenumber, darkest_secret);

            // If max records reached, remove the oldest one
            if (horses.size() >= max_horses) {
                horses.erase(horses.begin());
            }
            horses.push_back(newHorse);

            std::cout << "\nNew record added!\n";
        } 
        else if (command == "SEARCH") {
            if (horses.empty()) {
                std::cout << "No records found. Try adding some first!" << std::endl;
            } else {
                std::cout << "\nHorse Records (up to " << max_horses << " most recent):\n";
                for (size_t i = 0; i < horses.size(); ++i) {
                    std::cout << "\nHorse " << (i + 1) << " Details:\n";
                    horses[i].display();
                }
            }
        } 
        else {
            std::cout << "Unknown command. Please enter 'ADD', 'SEARCH', or 'EXIT'." << std::endl;
        }

        // Prompt for the next command
        std::cout << "\nEnter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
    }

    std::cout << "Exiting the program. Goodbye!" << std::endl;
    return 0;
}
