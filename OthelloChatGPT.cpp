#include <iostream>
#include <vector>

const int SIZE = 8; // taille du plateau de jeu

// Enumération des différentes couleurs des cases du plateau
enum class Color {
  Empty,
  Black,
  White
};

// Représentation du plateau de jeu sous forme d'un tableau à deux dimensions
using Board = std::vector<std::vector<Color>>;

// Fonction pour initialiser le plateau de jeu en position de départ
Board initializeBoard() {
  Board board(SIZE, std::vector<Color>(SIZE, Color::Empty));
  // Place les quatre pions centraux sur le plateau
  board[SIZE/2 - 1][SIZE/2 - 1] = Color::White;
  board[SIZE/2 - 1][SIZE/2] = Color::Black;
  board[SIZE/2][SIZE/2 - 1] = Color::Black;
  board[SIZE/2][SIZE/2] = Color::White;
  return board;
}

// Fonction pour afficher le plateau de jeu dans la console
void printBoard(const Board& board) {
  std::cout << "   ";
  for (int i = 0; i < SIZE; ++i) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  for (int i = 0; i < SIZE; ++i) {
    std::cout << i << "  ";
    for (int j = 0; j < SIZE; ++j) {
      switch (board[i][j]) {
        case Color::Empty: std::cout << ". "; break;
        case Color::Black: std::cout << "B "; break;
        case Color::White: std::cout << "W "; break;
      }
    }
    std::cout << std::endl;
  }
}

// Fonction pour vérifier si un coup est valide pour un joueur donné
bool isValidMove(const Board& board, Color color, int x, int y) {
  // Vérifier si la case est vide
  if (board[x][y] != Color::Empty) {
    return false;
  }

  // Vérifier si le coup peut capturer des pions adverses dans chacune des 8 directions
  const std::vector<std::pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
  for (const auto& [dx, dy] : directions) {
    int i = x + dx, j = y + dy;
    // Vérifier si la case voisine dans la direction actuelle est occupée par un pion adverse
    if (i >= 0 && i < SIZE && j >= 0 && j < SIZE && board[i
