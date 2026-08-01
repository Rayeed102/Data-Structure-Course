#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Calculate string length
size_t get_length(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// 1. String Reverse 
void reverse_string(char *str) {
    if (!str) return;
    
    int start = 0;
    int end = (int)get_length(str) - 1;
    
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// 2. Substring Finding and Counting
int count_substring(const char *str, const char *sub) {
    if (!str || !sub) return 0;
    
    size_t str_len = get_length(str);
    size_t sub_len = get_length(sub);
    
    if (sub_len == 0 || sub_len > str_len) return 0;
    
    int count = 0;
    for (size_t i = 0; i <= str_len - sub_len; i++) {
        bool match = true;
        for (size_t j = 0; j < sub_len; j++) {
            if (str[i + j] != sub[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            count++; 
        }
    }
    return count;
}

// 3. String Concatenation
void concatenate_string(char *dest, const char *src) {
    if (!dest || !src) return;
    
    
    while (*dest != '\0') {
        dest++;
    }
    
    
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    
    
    *dest = '\0';
}

// 4. Palindrome Check 
bool is_palindrome(const char *str) {
    if (!str) return false;
    
    int start = 0;
    int end = (int)get_length(str) - 1;
    
    while (start < end) {
        
        while (start < end && !isalnum((unsigned char)str[start])) {
            start++;
        }
       
        while (start < end && !isalnum((unsigned char)str[end])) {
            end--;
        }
        
       
        if (tolower((unsigned char)str[start]) != tolower((unsigned char)str[end])) {
            return false;
        }
        
        start++;
        end--;
    }
    
    return true;
}

// 5. Character Frequency
void print_character_frequency(const char *str) {
    if (!str) return;
    
    int freq[256] = {0}; 
    
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }
    
    printf("Character Frequencies:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            if (i == ' ') {
                printf("  ' ' (space) : %d\n", freq[i]);
            } else if (i == '\n') {
                printf("  '\\n' (newline) : %d\n", freq[i]);
            } else {
                printf("  '%c' : %d\n", i, freq[i]);
            }
        }
    }
}

int main(void) {
    printf("=== 1. STRING REVERSE ===\n");
    char rev_test[] = "Hello, World!";
    printf("Original : \"%s\"\n", rev_test);
    reverse_string(rev_test);
    printf("Reversed : \"%s\"\n\n", rev_test);

    printf("=== 2. SUBSTRING COUNTING ===\n");
    const char *text = "banana apple banana band banana";
    const char *sub = "ana";
    printf("Text      : \"%s\"\n", text);
    printf("Substring : \"%s\"\n", sub);
    printf("Count     : %d\n\n", count_substring(text, sub));

    printf("=== 3. CONCATENATION ===\n");
    char buffer[100] = "Data ";
    const char *append_text = "Structures";
    printf("Before : \"%s\"\n", buffer);
    concatenate_string(buffer, append_text);
    printf("After  : \"%s\"\n\n", buffer);

    printf("=== 4. PALINDROME CHECK ===\n");
    const char *p1 = "A man, a plan, a canal: Panama";
    const char *p2 = "Hello World";
    printf("\"%s\" -> %s\n", p1, is_palindrome(p1) ? "Palindrome" : "Not a Palindrome");
    printf("\"%s\" -> %s\n\n", p2, is_palindrome(p2) ? "Palindrome" : "Not a Palindrome");

    printf("=== 5. CHARACTER FREQUENCY ===\n");
    const char *freq_test = "programming";
    printf("Text: \"%s\"\n", freq_test);
    print_character_frequency(freq_test);

    return 0;
}