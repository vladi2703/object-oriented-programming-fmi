#include <cstring>
#include <fstream>
#include <iostream>

// "C:Users/Ivana/Desktop/file.txt" -> пълен път
// "../Fold1/file.txt" -> относителен път
// "file.txt" -> файлът е в директорията, в която се намираме

const int LINE_BUFFER_SIZE = 1024;

void replace_in_line(const char* current_line, char* new_line,
                     const char* to_replace, const char* replacer) {
  int replacer_length = strlen(replacer);
  int to_replace_length = strlen(to_replace);
  int new_line_index = 0;
  for (int i = 0; current_line[i] != '\0'; i++) {
    if (current_line[i] != to_replace[0]) {  // check if it is the first letter
                                             // of the word to replace
      new_line[new_line_index++] =
          current_line[i];  // if not, just copy the letter to the new line
      continue;
    }

    // check if it is a substring
    if ((i > 0 && current_line[i - 1] !=
                      ' ') ||  // if the letter before the word is not a space
        (current_line[i + to_replace_length] !=
             ' ' &&  // if the letter after the word is not a space
         current_line[i + to_replace_length] !=
             '\0')) {  // and if the letter after the word is not the end of the
                       // line
      new_line[new_line_index++] =
          current_line[i];  // if not, just copy the letter to the new line
      continue;
    }

    int to_replace_index = 0;
    while (to_replace_index <
               to_replace_length &&  // check if the word is the same as the
                                     // word to replace
           current_line[i + to_replace_index] == to_replace[to_replace_index]) {
      to_replace_index++;
    }

    if (to_replace_index != to_replace_length) {
      new_line[new_line_index++] = current_line[i];
      continue;
    }

    for (int j = 0; j < replacer_length; j++) {
      new_line[new_line_index++] = replacer[j];
    }

    i += to_replace_length - 1;
  }

  new_line[new_line_index] = '\0';
}

void replace_in_text(const char* filename, const char* to_replace,
                     const char* replacer) {
  std::ifstream i_file(filename);

  if (!i_file.is_open()) {
    return;
  }

  std::ofstream o_file("corrected.cpp", std::ios::trunc);

  char* current_line = new char[LINE_BUFFER_SIZE];
  char* new_line =
      new char[LINE_BUFFER_SIZE];  // думата не може да е по-дълга от

  while (!i_file.eof()) {
    i_file.getline(current_line, LINE_BUFFER_SIZE);
    replace_in_line(current_line, new_line, to_replace, replacer);
    o_file << new_line << "\n";
  }
}

int main() {
  replace_in_text("replace-in-text.cpp", "int", "uint_32");

  return 0;
}