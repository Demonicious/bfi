#include <iostream>
#include <fstream>
#include <vector>
#include <vector>

int main(int argc, char *argv[]) {
	// Some Error Reporting
	if(argc > 1) {
		std::ifstream ifs(argv[1]);

		// |- Brainfuck Interpreter -| //

  		std::string instructions((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
		long length = instructions.length();
		long position = 0;

		std::vector<int> memory = {0};
		long memPos = 0;

		if(length != 0) {
			while(position < length) {
				char token = instructions.at(position);

				if(token == '>') {
					memPos++;
					if(memory.size() <= memPos) {
						memory.push_back(0);
					}
				}
				else if(token == '<') {
					memPos--;
					if(memPos < 0) {
						std::cout << "[Error]: Memory Position less than 0. Moved off Memory Tape at Character No. ${position + 1}." << std::endl;
						exit(1);
					}
				}
				else if(token == '+') {
					memory[memPos]++;
					if(memory[memPos] >= 255) {
						memory[memPos] = 0;
					}
				}
				else if(token == '-') {
					memory[memPos]--;
					if(memory[memPos] <= -1) {
						memory[memPos] = 255;
					}
				}
				else if(token == '.') std::cout << char(memory[memPos]);
				else if(token == ',') {
					char inp;
					std::cin >> inp;
					memory[memPos] = int(inp);
				}
				else if(token == '[') {
					if(memory[memPos] == 0) {
						int openedBraces = 0;
						position++;
						while(position < length) {
							char braceToken = instructions.at(position);
							if(braceToken == ']' && openedBraces == 0) break;
							else if(braceToken == '[') openedBraces++;
							else if(braceToken == ']') openedBraces--;
							position++;
						}
					}
				}
				else if(token == ']') {
					if(memory[memPos] != 0) {
						int closedBraces = 0;
						position--;
						while(position >= 0) {
							char braceToken = instructions.at(position);
							if(braceToken == '[' && closedBraces == 0) break;
							else if(braceToken == ']') closedBraces++;
							else if(braceToken == '[') closedBraces--;
							position--;
						}
					}
				}

				position++;
			}
		} else {
			std::cout << "[Error]: Invalid File Path provided." << std::endl;
		}

		// |- Brainfuck Interpreter -| //

		return 0;
	} else {
		std::cout << "[Error]: No Source File provided." << std::endl;
		return 1;
	}
}