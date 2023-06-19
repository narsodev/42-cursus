#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
  if (argc != 4) {
    std::cerr << "Usage: ./replace <filename> <string1> <string2>" << std::endl;
    return 1;
  }

  std::ifstream inputstream(argv[1]);
  if (!inputstream.is_open()) {
    std::cerr << "Error: could not open file" << std::endl;
    return 1;
  }

  std::string filename(argv[1]);
  std::string s1(argv[2]);
  std::string s2(argv[3]);
  std::string line;
  std::string content;

  while (std::getline(inputstream, line)) {
    content += line + "\n";
  }

  if (!inputstream.eof()) {
    inputstream.close();
    std::cerr << "Error: could not read file" << std::endl;
    return 1;
  }

  inputstream.close();

  std::string::size_type pos = content.find(s1);
  while (pos != std::string::npos) {
    content.erase(pos, s1.length());
    content.insert(pos, s2);
    pos = content.find(s1, pos + s2.length());
  }

  std::ofstream outputstream((filename + ".replace").c_str());
  if (!outputstream.is_open()) {
    std::cerr << "Error: could not open file" << std::endl;
    return 1;
  }

  outputstream << content;
  outputstream.close();

  return 0;
}