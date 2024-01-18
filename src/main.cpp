#include "game.hpp"

int main(void)
{
    Game game = Game();
    game.Init();
    game.Run();
    system("pause");
    return 0;
}