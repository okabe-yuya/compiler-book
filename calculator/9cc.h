#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 抽象構文木のノードの種類
typedef enum {
  ND_ADD, // +
  ND_SUB, // -
  ND_MUL, // *
  ND_DIV, // /
  ND_EQ,  // ==
  ND_NE,  // !=
  ND_LT,  // <=
  ND_LE,  // <=
  ND_NUM, // 整数
} NodeKind;

typedef struct Node Node;
struct Node {
  NodeKind kind; // ノードの型
  Node *lhs; // 左辺(left-hand side)
  Node *rhs; // 右辺(right-hand side)
  int val;   // kindがND_NUMの場合のみ使う
};

// token kind
typedef enum {
  TK_RESERVED, // 記号
  TK_NUM, // 整数トークン
  TK_EOF, // 入力の終わりを表すトークン
} TokenKind;

typedef struct Token Token;
struct Token {
  TokenKind kind; // トークンの型
  Token *next; // 次の入力トークン
  int val; // kindがTK_NUMの場合、その数値
  char *str; // トークン文字列
  int len; // トークンの長さ
};

extern Token *token;
extern char *user_input;
Token *tokenize();
Node *expr();

void gen(Node *node);
