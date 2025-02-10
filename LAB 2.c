#include <stdio.h>
#include <string.h>

// Function to perform XOR operation
void xor_operation(char *dividend, const char *generator, int len) {
    for (int i = 0; i < len; i++) {
        dividend[i] = (dividend[i] == generator[i]) ? '0' : '1';
    }
}

// Function to perform CRC
void crc(char data[], const char generator[]) {
    int data_len = strlen(data);
    int gen_len = strlen(generator);
    int total_len = data_len + gen_len - 1;
    
    // Append zeros to the data (simulate the message with padding for CRC).
    char padded_data[total_len + 1];
    strcpy(padded_data, data);
    for (int i = data_len; i < total_len; i++) {
        padded_data[i] = '0';
    }
    padded_data[total_len] = '\0';

    printf("Padded data: %s\n", padded_data);

    char dividend[gen_len];
    strncpy(dividend, padded_data, gen_len);
    dividend[gen_len] = '\0';

    for (int i = 0; i <= total_len - gen_len; i++) {
        if (dividend[0] == '1') {
            // Perform XOR with the generator polynomial
            xor_operation(dividend, generator, gen_len);
        }

        // Shift left and bring in the next bit from padded_data
        memmove(dividend, dividend + 1, gen_len - 1);
        dividend[gen_len - 1] = padded_data[i + gen_len];
        dividend[gen_len] = '\0';
    }

    printf("Remainder (CRC): %s\n", dividend);
}

int main() {
    char data[256];  // Input data buffer
    int choice;
    const char *generator;

    // Menu to select CRC type
    printf("Select CRC type:\n");
    printf("1. CRC-8\n");
    printf("2. CRC-10\n");
    printf("3. CRC-16\n");
    printf("4. CRC-32\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Assign generator polynomial based on choice
    switch (choice) {
        case 1:
            generator = "100000111"; // x^8 + x^2 + x + 1
            break;
        case 2:
            generator = "11000110101"; // x^10 + x^9 + x^5 + x^4 + x^2 + 1
            break;
        case 3:
            generator = "11000000000000101"; // x^16 + x^12 + x^5 + 1
            break;
        case 4:
            generator = "100000100110000010001110110110111"; // x^32 + ...
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    // Input data from the user
    printf("Enter data to calculate CRC: ");
    scanf("%s", data);

    // Calculate and print CRC
    crc(data, generator);

    return 0;
}
