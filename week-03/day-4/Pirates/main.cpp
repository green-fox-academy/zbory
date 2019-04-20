#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include "Ship.h"
#include "Armada.h"


int main()
{
    srand(time(0));

    std::string asciiShip = "              |    |    |\n"
                            "             )_)  )_)  )_)\n"
                            "            )___))___))___)\\\n"
                            "           )____)____)_____)\\\\\n"
                            "         _____|____|____|____\\\\\\__\n"
                            "---------\\                   /---------\n"
                            "  ^^^^^ ^^^^^^^^^^^^^^^^^^^^^\n"
                            "    ^^^^      ^^^^     ^^^    ^^\n"
                            "         ^^^^      ^^^";

    std::string asciiSkull = " _;~)                  (~;_\n"
                        "(   |                  |   )\n"
                        " ~', ',    ,''~'',   ,' ,'~\n"
                        "     ', ','       ',' ,'\n"
                        "       ',: {'} {'} :,'\n"
                        "         ;   /^\\   ;\n"
                        "          ~\\  ~  /~\n"
                        "        ,' ,~~~~~, ',\n"
                        "      ,' ,' ;~~~; ', ',\n"
                        "    ,' ,'    '''    ', ',\n"
                        "  (~  ;               ;  ~)\n"
                        "   -;_)               (_;-";

    std::string asciiTreasure = "                            _.--.\n"
                                "                        _.-'_:-'||\n"
                                "                    _.-'_.-::::'||\n"
                                "               _.-:'_.-::::::'  ||\n"
                                "             .'`-.-:::::::'     ||\n"
                                "            /.'`;|:::::::'      ||_\n"
                                "           ||   ||::::::'     _.;._'-._\n"
                                "           ||   ||:::::'  _.-!oo @.!-._'-.\n"
                                "           \\'.  ||:::::.-!()oo @!()@.-'_.|\n"
                                "            '.'-;|:.-'.&$@.& ()$%-'o.'\\U||\n"
                                "              `>'-.!@%()@'@_%-'_.-o _.|'||\n"
                                "               ||-._'-.@.-'_.-' _.-o  |'||\n"
                                "               ||=[ '-._.-\\U/.-'    o |'||\n"
                                "               || '-.]=|| |'|      o  |'||\n"
                                "               ||      || |'|        _| ';\n"
                                "               ||      || |'|    _.-'_.-'\n"
                                "               |'-._   || |'|_.-'_.-'\n"
                                "            jgs '-._'-.|| |' `_.-'\n"
                                "                    '-.||_/.-'";

    //Redirecting stdout to file
    std::fstream file;
    file.open("war_output.txt", std::ios::out);

    // Backup streambuffers of  cout
//    streambuf* stream_buffer_cout = cout.rdbuf();
//    streambuf* stream_buffer_cin = cin.rdbuf();

    // Get the streambuffer of the file
    std::streambuf* stream_buffer_file = file.rdbuf();

    // Redirect cout to file
    std::cout.rdbuf(stream_buffer_file);



    std::cout << asciiShip << std::endl;
    //Creating ships
/*    Ship ship1("Black Pearl");
    Ship ship2("The Dirty Titanic");
    //Filling them with crew
    ship1.fillShip();
    ship2.fillShip();
    //Ship1 heavy drinking
    ship1.getCaptain()->drinkSomeRum();
    ship1.getCaptain()->drinkSomeRum();
    ship1.getCaptain()->drinkSomeRum();


    ship1.printCrewState();
    ship2.printCrewState();*/

    //Battle
    Armada armada1;
    Armada armada2;

    bool result = armada1.war(armada2);

    if(result)
        std::cout << asciiTreasure;
    else
        std::cout << asciiSkull;


    return 0;
}