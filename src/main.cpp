#include "Core/Game/Game.hpp"
#include <memory>

int main(void) {
  std::shared_ptr<Game> game = std::make_shared<Game>();
  game->Init();
  game->Run();
  return 0;
}

