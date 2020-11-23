#include <BashDB/parser.hpp>

int main(int argc, char *argv[]) {
  // 1. Read Settings
  // 2. Parse Input
  // 3. Append to WAL
  // 4. If WAL is successful, add to Memtable
  // 5. Compaction/flush threads

  Parser::parseInput(argc, argv);
  return 0;
}
