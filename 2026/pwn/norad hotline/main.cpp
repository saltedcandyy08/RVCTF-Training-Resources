// g++ -fno-stack-protector -no-pie -fno-pie -z execstack -o norad_hotline main.cpp

#include <iostream>
#include <cstring>
#include <cstdio>

#define FLAG "REDACTED"

class PhoneLine
{
public:
    char caller_name[32];
    char phone_number[16];
    int call_duration;

public:
    PhoneLine()
    {
        memset(caller_name, 0, sizeof(caller_name));
        memset(phone_number, 0, sizeof(phone_number));
        call_duration = 0;
    }

    virtual void route_call()
    {
        std::cout << "Routing your call...\n";
        std::cout << "Caller: " << caller_name << "\n";
        std::cout << "Dialed: " << phone_number << "\n";
    }

    virtual void take_message()
    {
        std::cout << "Santa's elves are busy! Please leave a message.\n";
        std::cout << "Your message has been recorded.\n";
    }

    virtual void disconnect()
    {
        std::cout << "\nCall disconnected.\n";
    }
};

class NORADHotline : public PhoneLine
{
    char classified_message[64];

public:
    NORADHotline() : PhoneLine()
    {
        memset(this->classified_message, 0, sizeof(this->classified_message));
        strcpy(this->classified_message, "CLASSIFIED: No aerial activity detected.");
    }

    virtual void route_call()
    {
        std::cout << "CONTINENTAL AIR DEFENSE COMMAND\n";
        std::cout << "HELLO! This is a MILITARY HOTLINE.\n";
        std::cout << "Caller '" << this->caller_name << "' has reached the wrong number.\n";
        std::cout << "Transferring to public relations...\n";
    }

    virtual void alert_air_defense()
    {
        std::cout << "RED ALERT! UNIDENTIFIED AERIAL OBJECT!\n";
        std::cout << "Scrambling fighter jets...\n";
        std::cout << "Wait... is it just a kid asking for Santa!\n";
    }

    virtual void connect_to_santa()
    {
        std::cout << "Connecting to SANTA!";
        std::cout << "\n";
        std::cout << " HO HO HO! This is Colonel Shoup speaking!\n";
        std::cout << "\n";
        std::cout << " Well hello there! You've reached the Continental Air Defense Command, but don't worry - we've got Santa on our radar!\n";
        std::cout << " According to our tracking systems, Santa is currently over the North Pole preparing for his Christmas Eve flight!\n";
        std::cout << "\n";
        std::cout << " Btw kid, here's a special gift for you:\n";
        std::cout << "\n ";

        std::cout << FLAG;

        std::cout << "\n";
        exit(0);
    }
};

void print_banner()
{
    std::cout << "\n";
    std::cout << "╔══════════════════════════════════════════════════╗\n";
    std::cout << "║        SANTA'S HOTLINE - December 1955           ║\n";
    std::cout << "║                                                  ║\n";
    std::cout << "║  \"Call ME-2-6681 to talk to Santa!\"              ║\n";
    std::cout << "║       - Sears Christmas Advertisement            ║\n";
    std::cout << "╚══════════════════════════════════════════════════╝\n";
    std::cout << "\n";
}

void handle_call()
{
    PhoneLine caller;
    NORADHotline hotline;

    std::cout << "Welcome to Santa's Hotline!\n\n";

    std::cout << "Please enter your name: ";
    std::cout.flush();
    std::cin.width(32);
    std::cin >> hotline.caller_name;

    std::cout << "Please enter the phone number you're calling from: ";
    std::cout.flush();

    std::cin >> caller.phone_number;

    std::cout << "\nRing ring! Connecting your call...\n";

    hotline.route_call();

    hotline.disconnect();
}

int main()
{
    // ignore
    setvbuf(stdin, 0, _IONBF, 0);
    setvbuf(stdout, 0, _IONBF, 0);
    setvbuf(stderr, 0, _IONBF, 0);

    print_banner();

    handle_call();

    return 0;
}
