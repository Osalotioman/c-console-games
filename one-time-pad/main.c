#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generate_key(char *key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 256;
    }
}

void xor_cipher(const char *input, char *output, const char *key, int length) {
    for (int i = 0; i < length; i++) {
        output[i] = input[i] ^ key[i];
    }
}

void write_to_file(const char *filename, const char *data, int length) {
    FILE *file = fopen(filename, "wb");
    if (file) {
        fwrite(data, 1, length, file);
        fclose(file);
    } else {
        printf("Error writing to file: %s\n", filename);
    }
}

int main() {
    srand(time(NULL));

    char input[1024];
    char *message;
    int length;
    char key[1024];
    char encrypted[1024];
    char decrypted[1024];

    printf("Enter 1 to input text or 2 to read from file: ");
    int choice;
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        printf("Enter the message: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        length = strlen(input);
        message = input;
    } else if (choice == 2) {
        char filename[256];
        printf("Enter file path: ");
        fgets(filename, sizeof(filename), stdin);
        filename[strcspn(filename, "\n")] = '\0';

        FILE *file = fopen(filename, "rb");
        if (!file) {
            printf("Error opening file.\n");
            return 1;
        }

        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);

        message = malloc(length + 1);
        fread(message, 1, length, file);
        message[length] = '\0';
        fclose(file);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    generate_key(key, length);
    xor_cipher(message, encrypted, key, length);
    xor_cipher(encrypted, decrypted, key, length);

    printf("Original:   %s\n", message);
    printf("Encrypted:  ");
    for (int i = 0; i < length; i++) printf("%02X ", (unsigned char)encrypted[i]);
    printf("\n");
    printf("Decrypted:  %s\n", decrypted);

    write_to_file("encrypted.bin", encrypted, length);
    write_to_file("key.bin", key, length);
    write_to_file("decrypted.txt", decrypted, length);

    if (choice == 2) free(message);

    return 0;
}